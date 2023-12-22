#include "BloomFilter.hpp"

int main() {
    constexpr uint16_t iterations = 10; 
    double averageError = 0;

    for(double fillingFactor = 0.05; fillingFactor <= 0.5; fillingFactor += 0.05) {
        double totalError = 0.0;
        BloomFilter filter(0.69 / fillingFactor);

        const uint16_t messagesToAdd = static_cast<uint16_t>(FILTER_SIZE * fillingFactor);
    
        for(uint16_t iter = 0; iter < iterations; ++iter) {

            for(int i = 0; i < messagesToAdd; i++)
                filter.add(generateString());

            uint16_t generatedMessages = 0;
            while(true) {
                generatedMessages++;
                if (filter.possiblyContains(generateString())) {
                    double error = 1.0 / generatedMessages;
                    totalError += error;
                    break;
                }
            }
            filter.clear();
        }
        
        std::cout << "s:\t" << (int)(0.69 / fillingFactor) << std::endl;
        std::cout << "factor: " << fillingFactor << std::endl;
        std::cout << "error:  " << std::setprecision(10) << totalError / iterations << std::endl << std::endl;
        
        averageError += totalError;
    }

    averageError = averageError / (iterations * 10);
    std::cout << "Estimated error probability: " << std::setprecision(10) << averageError << std::endl;

    return 0;
}