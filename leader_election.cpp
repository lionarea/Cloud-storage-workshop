#include <zookeeper/zookeeper.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstring>
const char *hosts = "71.136.92.241:2181"; // ZooKeeper服务器地址
int recv_timeout = 10000; // 接收超时时间

// 监听器回调函数
void watcher(zhandle_t *zh, int type, int state, const char *path, void *context) {
    if (type == ZOO_CHILD_EVENT) {
        std::cout << "Child event triggered: type=" << type << ", state=" << state << ", path=" << path << std::endl;
    } else if (type == ZOO_SESSION_EVENT) {
        if (state == ZOO_EXPIRED_SESSION_STATE) {
            std::cerr << "Session expired. Reconnecting..." << std::endl;
            // 实现重新连接逻辑
            zookeeper_close(zh);
            zh = zookeeper_init(hosts, watcher, recv_timeout, 0, 0, 0);
        }
    }
}

// 创建节点并加入选举
std::string joinElection(zhandle_t *zh) {
    char path_buffer[512];
    const char *electionPath = "/MasterElection/node-";
    const char *value = "candidate";
    int buffer_len = sizeof(path_buffer);
    int flag = ZOO_EPHEMERAL | ZOO_SEQUENCE;

    int ret = zoo_create(zh, electionPath, value, strlen(value), &ZOO_OPEN_ACL_UNSAFE, flag, path_buffer, buffer_len);
    if (ret != ZOK) {
        std::cerr << "Failed to create an election node: " << zerror(ret) << std::endl;
        exit(EXIT_FAILURE); // or handle more gracefully
    }

    std::cout << "Joined election with node: " << path_buffer << std::endl;
    return std::string(path_buffer);
}

// 执行选举
void electMaster(zhandle_t *zh, std::string myNodePath) {
    struct String_vector children;
    int ret = zoo_get_children(zh, "/MasterElection", 0, &children);
    if (ret != ZOK) {
        std::cerr << "Error getting children from ZooKeeper: " << zerror(ret) << std::endl;
        return;
    }

    std::vector<std::string> masterNodes;
    for (int i = 0; i < children.count; ++i) {
        masterNodes.push_back(children.data[i]);
    }
    deallocate_String_vector(&children);

    std::sort(masterNodes.begin(), masterNodes.end());
    if (myNodePath == ("/MasterElection/" + masterNodes[0])) {
        std::cout << "This instance is the Leader." << std::endl;
    } else {
        std::cout << "This instance is not the Leader." << std::endl;
    }
}

int main() {
    zhandle_t *zh = zookeeper_init(hosts, watcher, recv_timeout, 0, 0, 0);
    if (!zh) {
        std::cerr << "Unable to connect to ZooKeeper server." << std::endl;
        return 1;
    }

    std::string myNodePath = joinElection(zh);


    while (true) {
        electMaster(zh, myNodePath);
        std::this_thread::sleep_for(std::chrono::seconds(5)); // 主循环等待时间
    }

    zookeeper_close(zh);
    return 0;
}