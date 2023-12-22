#include "BloomFilter.hpp"

uint16_t polyHash(const uint16_t coef, const std::string& inputString) {
    if (inputString.size() > MAX_STRING_SIZE) {
        std::cout << "Error: The size of the input string exceeds the limit...";
        return 0;
    }

    std::array<uint16_t, MAX_STRING_SIZE / 2> arr{};

    for (size_t i = 0, j = 0; i < inputString.size() - 1; i += 2, ++j) {
        arr[j] = static_cast<uint16_t>(inputString[i]) + (static_cast<uint16_t>(inputString[i + 1]) << 8);
    }

    uint16_t res = 1;
    for (const auto& elem : arr)
        res = res * coef + elem;

    return res;
}

std::string generateString() {
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> lengthDistribution(10, 49);

    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    int length = lengthDistribution(generator);
    for (int i = 0; i < length; ++i)
        random_string += CHARACTERS[distribution(generator)];

    return random_string;
}

BloomFilter::BloomFilter(uint16_t num) {
    numOfHashFunc = num;
}

void BloomFilter::add(const std::string &inputString) {
    for (uint16_t i = 1; i <= numOfHashFunc; ++i) {
        uint16_t hash_val = polyHash(i, inputString);
        filter.set(hash_val % FILTER_SIZE, true);
    }
}

bool BloomFilter::possiblyContains(const std::string &inputString) {
    for (uint16_t i = 1; i <= numOfHashFunc; ++i) {
        uint16_t hash_val = polyHash(i, inputString);
        if (!filter.test(hash_val % FILTER_SIZE)) 
            return false;
    }
    return true; 
}

void BloomFilter::clear() {
    filter.reset();
}