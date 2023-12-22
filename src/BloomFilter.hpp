#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <random>

constexpr uint16_t MAX_SIZE = 50;
constexpr uint16_t NUM_HASH_FUNCTIONS = 9;
constexpr uint16_t FILTER_SIZE = 0xFFFF; 

uint16_t polyHash(const uint16_t coef, const std::string& inputString);

class BloomFilter {
public:
    void add(const std::string& inputString);
    void clear();
    bool possiblyContains(const std::string& inputString);

private:
    std::bitset<FILTER_SIZE> filter;
};