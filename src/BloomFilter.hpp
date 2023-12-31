#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <random>
#include <iomanip>
#include <algorithm>

constexpr uint16_t MAX_STRING_SIZE = 50;
constexpr uint16_t FILTER_SIZE = 0xFFFF; 

uint16_t polyHash(const uint16_t coef, const std::string& inputString);
std::string generateString();

class BloomFilter {
public:
    void add(const std::string& inputString);
    void clear();
    bool possiblyContains(const std::string& inputString);
    BloomFilter(uint16_t num);

private:
    std::bitset<FILTER_SIZE> filter;
    uint16_t numOfHashFunc;
};