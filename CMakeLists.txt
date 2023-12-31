# 指定CMake最低版本
#cmake_minimum_required(VERSION 3.10) 

# 项目名称  
project(connection-pool-cpp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# 添加可执行文件
add_executable(main src/main.cpp src/Connection.cpp src/CommonConnectionPool.cpp) 

# 添加头文件搜索路径
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc /usr/include/mysql)

# 添加库搜索路径 
link_directories(/usr/lib64/mysql/)

# 链接库
target_link_libraries(main /usr/lib64/mysql/libmysqlclient.so)

# 添加编译选项
target_compile_options(main PRIVATE
  -fdiagnostics-color=always 
  -pthread
)