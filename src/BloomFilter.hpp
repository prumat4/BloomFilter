#include <iostream>
#include <string>
#include <array>

constexpr uint16_t MAX_SIZE = 50;

uint16_t hash(const uint16_t k, const std::string& inputString) {
    if (inputString.size() > MAX_SIZE)
        return 0;

    std::array<uint16_t, MAX_SIZE / 2> arr{};

    for (size_t i = 0, j = 0; i < inputString.size() - 1; i += 2, ++j) {
        arr[j] = static_cast<uint16_t>(inputString[i]) + (static_cast<uint16_t>(inputString[i + 1]) << 8);
    }

    uint16_t res = 1;
    for (const auto& elem : arr)
        res = res * k + elem;
    return res;
}