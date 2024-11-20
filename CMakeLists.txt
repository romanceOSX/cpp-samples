cmake_minimum_required(VERSION 3.28.0)

project(template_sample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED Y)

set(SRC_DIR src)
set(APP_SOURCES
    ${SRC_DIR}/variadic_dbg.cpp
)

add_executable(out ${APP_SOURCES})

