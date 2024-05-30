#include "GenerateNumber.h"
#include <cstdlib>
#include <ctime>

GenerateNumber::GenerateNumber() {
    std::srand(std::time(0)); // Seed the random number generator
}

void GenerateNumber::setNumber() {
    randomNumber = std::rand();
}

int GenerateNumber::getRandomNumber() const {
    return randomNumber;
}
