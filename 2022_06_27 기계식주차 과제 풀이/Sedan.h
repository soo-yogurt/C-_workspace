#pragma once
#include "Car.h"
class Sedan :
    public Car
{
public:
    Sedan(int num);
    const char* GetType();
};

