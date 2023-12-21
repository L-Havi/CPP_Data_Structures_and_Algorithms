/*
 *  Utilities for random events
 *  Includes a function for getting a random integer between 0 - 100
 */

#include <iostream>
#include "RandomUtils.h"
#include <random>

using u32 = uint_least32_t;
using engine = std::mt19937;

int generateRandomInteger()
{
    std::random_device osSeed;
    const u32 seed = osSeed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 100);

    return distribute(generator);
}
