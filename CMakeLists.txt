
#使用 cmake 构造 liblog4cplus 的例子
#其中 src 是所有的原始代码
#其中 src/test1 是调用使用 C 编译器，采用动态构造的方式调用目标库
#其中 src/test2 是调用使用 C++ 编译器，采用静态构造的方式调用目标库
#其中 lib 存放构造的目标动态和静态库
#其中 build 存放所以的临时文件,包括 makefile 文件.

#编译方法,进入 build 目录
#[root@six build]# cmake ../;make
#[root@six build]# ../bin/test2; ../bin/test1;


cmake_minimum_required(VERSION 3.1.0)

PROJECT(LIB_LOG4CPLUS)

#SET(SYS_LIBLOG4CPLUS "/usr/local/log4cplus-2.0.0/")
SET(SYS_LIBLOG4CPLUS "/usr/local/log4cplus-1.1.2/")
SET(PROJECT_ROOT_PATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_VERBOSE_MAKEFILE on)
enable_testing()
enable_language(C)

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#SET(CMAKE_C_COMPILER "/usr/bin/g++")

set(CMAKE_BUILD_TYPE "debug")		

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "debug")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "debug")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -O0")
    set(CMAKE_C_FLAGS_DEBUG "-g -Wall -std=gnu99 -O0")
else()
   set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG -std=gnu99")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

if(CMAKE_BUILD_BITS EQUAL 32)
   list(APPEND CMAKE_C_FLAGS "-m32")
   list(APPEND CMAKE_CXX_FLAGS "-m32")
 endif()

#list(APPEND CMAKE_CXX_FLAGS "-D_SERVER_MONITER_")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

ADD_SUBDIRECTORY(src)
