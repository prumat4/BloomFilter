add_library(BloomFilter
    BloomFilter.cpp
)

target_include_directories(BloomFilter
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)