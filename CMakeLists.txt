cmake_minimum_required(VERSION 3.28)
project(Maps_and_Legends CXX)

# Google test requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Source Files === #
set(SRC_FILES_WITHOUT_MAIN
    src/linkedlist.hpp
    src/hashmap.hpp
    src/user.hpp
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
set(PROJECT_CODE_FILES
    ${SRC_FILES_WITHOUT_MAIN}
    ${HELPER_FILES}
)

set(GTEST_FILES_WITHOUT_MAIN
    gtest/linkedlist_gtests.cpp
    gtest/hashmap_gtests.cpp
)

# === All Gtests === #
set(MAPS_AND_LETTERS_GTESTS ${PROJECT_NAME}_gtests)
set(MAPS_AND_LETTERS_GTEST_FILES
    gtest/gtestmain.cpp
    ${GTEST_FILES_WITHOUT_MAIN}
    ${PROJECT_CODE_FILES}
)

add_executable(${MAPS_AND_LETTERS_GTESTS} ${MAPS_AND_LETTERS_GTEST_FILES})
target_link_libraries(${MAPS_AND_LETTERS_GTESTS} gtest gtest_main)
target_include_directories(${MAPS_AND_LETTERS_GTESTS} PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_test(NAME maps_and_letters_gtests COMMAND ${MAPS_AND_LETTERS_GTESTS})

# === Linked List Gtests === #
set(LINKED_LIST_GTESTS linked_list_gtests)
set(LINKED_LIST_GTEST_FILES
    gtest/linkedlist_gtests.cpp
    ${PROJECT_CODE_FILES}
)

add_executable(${LINKED_LIST_GTESTS} ${LINKED_LIST_GTEST_FILES})
target_link_libraries(${LINKED_LIST_GTESTS} gtest gtest_main)
target_include_directories(${LINKED_LIST_GTESTS} PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_test(NAME linked_list_gtests COMMAND ${LINKED_LIST_GTESTS})

# === Hash Map Gtests === #
set(HASH_MAP_GTESTS hash_map_gtests)
set(HASH_MAP_GTEST_FILES
    gtest/hashmap_gtests.cpp
    ${PROJECT_CODE_FILES}
)

add_executable(${HASH_MAP_GTESTS} ${HASH_MAP_GTEST_FILES})
target_link_libraries(${HASH_MAP_GTESTS} gtest gtest_main)
target_include_directories(${HASH_MAP_GTESTS} PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_test(NAME hash_map_gtests COMMAND ${HASH_MAP_GTESTS})
