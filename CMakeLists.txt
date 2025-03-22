# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10.0)

# 设置项目名称和语言
project(datastructc VERSION 0.1.0 LANGUAGES C)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 创建可执行文件，包含main.c和sum.c, 添加头文件搜索路径
file(GLOB DT_SOURCES "src/*c")
add_executable(datastructc ${DT_SOURCES})
target_include_directories(datastructc PUBLIC ${CMAKE_SOURCE_DIR}/include)