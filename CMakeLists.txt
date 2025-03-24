# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10.0)

# 设置项目名称和语言
project(datastructc VERSION 0.1.0 LANGUAGES C)

# 设置 cmake 集成 vcpkg 
set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")
# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 引入klib源文件并创建静态库，添加第三方库搜索路径
file(GLOB KLIB_SOURCES "thirdparty/klib/*.c")
add_library(klib STATIC ${KLIB_SOURCES})
target_include_directories(klib PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty/klib)

# 查找链接 curl 库
find_package(CURL REQUIRED)
target_link_libraries(klib PUBLIC CURL::libcurl)

# 创建可执行文件，包含main.c和sum.c, 添加头文件搜索路径
file(GLOB DT_SOURCES "src/*c")
add_executable(datastructc ${DT_SOURCES})
target_include_directories(datastructc PUBLIC ${CMAKE_SOURCE_DIR}/include)

# 将 datastructc 链接到第三方 klib 库
target_link_libraries(datastructc PUBLIC klib)