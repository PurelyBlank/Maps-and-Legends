cmake_minimum_required(VERSION 3.28)
project(Maps_and_Legends CXX)

# Google test requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Source Files === #
set(SRC_FILES_WITHOUT_MAIN
    
)

add_executable(${PROJECT_NAME} ${SRC_FILES_WITHOUT_MAIN} src/main.cpp)

set(HELPER_FILES
    helper/io.h
    helper/io.cpp
)

include_directories(helper)
target_sources(${PROJECT_NAME} PRIVATE ${HELPER_FILES})

# === Google Test === #
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

enable_testing()

# === Test Executables === #
