cmake_minimum_required(VERSION 3.12)
project(BloomFilter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_subdirectory(report)

add_executable(main
    main.cpp
)

target_link_libraries(main
    BloomFilter
)