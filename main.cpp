#include "src/BloomFilter.hpp"

int main() {
    BloomFilter bloomFilter(3);

    bloomFilter.add("some");
    bloomFilter.add("random");
    bloomFilter.add("words");
    bloomFilter.add("ddos");

    std::cout << std::boolalpha;
    std::cout << "Contains 'random': " << bloomFilter.possiblyContains("random") << std::endl;
    std::cout << "Contains 'do not contain': " << bloomFilter.possiblyContains("do not contain") << std::endl;  

    return 0;
}