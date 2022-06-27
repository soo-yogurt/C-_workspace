#pragma once
#include "Car.h"

class Suv :
    public Car
{
public:
    Suv(int num);
    const char* GetType();
};

