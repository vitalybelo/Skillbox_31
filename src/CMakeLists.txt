cmake_minimum_required(VERSION 3.24)

add_executable(
        Skillbox_31
        main.cpp
        Toy.cpp
        shared_ptr_toy.cpp
)

target_include_directories(Skillbox_31 PUBLIC ${INCLUDE_DIR})
