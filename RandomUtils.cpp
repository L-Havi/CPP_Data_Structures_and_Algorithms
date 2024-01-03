/*
 *  Utilities for random events
 *  Includes a function for getting a random integer between set minumum and maximum values
 */

#include <iostream>
#include "RandomUtils.hpp"
#include <random>

using u32 = uint_least32_t;
using engine = std::mt19937;

int generateRandomInteger(int minGeneratedValue, int maxGeneratedValue)
{
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(minGeneratedValue, maxGeneratedValue);
    return distribute(generator);
}