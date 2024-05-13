# project name

This is my Workshop #2: Master node in Map Reduce project experiment

## Experimental steps:
1. First download and use the https://github.com/gatech-cc/systems-workshop2.git library, and install the compilation environment on the master1, master2, worker, and zookeeper virtual hosts respectively.
2. After successful installation, compile the code greeter_client.cc on the master1 and master2 hosts respectively.
![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/857ad4eb-e95d-45ee-aea5-07ce06f1b1b7)
3. Then compile the code greeter_server.cc on the worker host and run it. At this time it is in the listening state.
  ![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/ce099103-61f0-465f-a1ac-8db78c5ba33e)
5. Continue to execute the greeter_clientwen files on master1 and master2 respectively. At this time, they will be linked to the workers respectively and return different messages.
![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/ffbd6ad5-63e0-4a91-9370-175f30a24229)
![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/7b8e869c-c852-4cd9-bb3a-9e26e3f46ed4)
7. Continue to compile and execute 2 leader_election.cpp on master1 and 2 respectively. You can see that one of them is selected as the leader. If the connection to a certain node is stopped, the other node will automatically become the leader
8. ![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/6dbb0690-e84d-464f-9aab-85e99d32e637)
9. ![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/b8d81720-5fe0-427c-a75c-ac50f8bad120)
10. ![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/a7b7be3d-1034-4e55-b856-c145ae3c1e2d)
11. ![image](https://github.com/lionarea/Cloud-storage-workshop/assets/169691632/4eb2ebce-34c7-4720-9183-dfeaf6b0fd8f)



