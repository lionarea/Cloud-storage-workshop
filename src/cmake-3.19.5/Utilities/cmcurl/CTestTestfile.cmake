# CMake generated Testfile for 
# Source directory: /home/master1/src/cmake-3.19.5/Utilities/cmcurl
# Build directory: /home/master1/src/cmake-3.19.5/Utilities/cmcurl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(curl "curltest" "http://open.cdash.org/user.php")
set_tests_properties(curl PROPERTIES  _BACKTRACE_TRIPLES "/home/master1/src/cmake-3.19.5/Utilities/cmcurl/CMakeLists.txt;1461;add_test;/home/master1/src/cmake-3.19.5/Utilities/cmcurl/CMakeLists.txt;0;")
subdirs("lib")
