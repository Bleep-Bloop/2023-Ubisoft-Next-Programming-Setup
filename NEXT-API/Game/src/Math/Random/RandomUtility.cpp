#include "stdafx.h"
#include "RandomUtility.h"
#include <random>;

int RandomUtility::RandomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}
