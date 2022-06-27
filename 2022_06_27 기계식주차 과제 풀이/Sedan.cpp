#include "Sedan.h"

Sedan::Sedan(int num)
	:Car(num)
{

}
const char* Sedan::GetType()
{
	return "SEDAN";
}

