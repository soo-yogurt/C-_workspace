#include "Suv.h"


Suv::Suv(int num) :Car(num)
{

}

const char* Suv::GetType()
{
	return (char *)"SUV";
}