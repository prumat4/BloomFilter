#include "BloomFilter.hpp"

uint16_t polyHash(const uint16_t coef, const std::string& inputString) {
    if (inputString.size() > MAX_SIZE) {
        std::cout << "Error: The size of the input string exceeds the limit...";
        return 0;
    }

    std::array<uint16_t, MAX_SIZE / 2> arr{};

    for (size_t i = 0, j = 0; i < inputString.size() - 1; i += 2, ++j) {
        arr[j] = static_cast<uint16_t>(inputString[i]) + (static_cast<uint16_t>(inputString[i + 1]) << 8);
    }

    uint16_t res = 1;
    for (const auto& elem : arr)
        res = res * coef + elem;
        
    return res;
}

void BloomFilter::add(const std::string &inputString) {
    for (uint16_t i = 1; i <= NUM_HASH_FUNCTIONS; ++i) {
        uint16_t hash_val = polyHash(i, inputString);
        filter.set(hash_val, true);
    }
}

bool BloomFilter::possiblyContains(const std::string &inputString) {
    for (uint16_t i = 1; i <= NUM_HASH_FUNCTIONS; ++i) {
        uint16_t hash_val = polyHash(i, inputString);
        if (!filter.test(hash_val)) 
            return false;
    }
    return true; 
}

void BloomFilter::clear() {
    filter.reset();
}