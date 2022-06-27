#include "Car.h"


Car::Car(int _num)
{
	number = _num;
}

// 자료형이 (char*)를 반환 한다는 것은 반환 받은곳에서 값을 변경 할 수 있다는
// 것을 의미한다. 하지만 상수를 강제로 캐스팅 하였기 반환 하였기때문에 변경이 불가능한 상태이다.
// 때문에 의미를 정확히 알려주기 위해 자료형을 const char*로 변경하였다.
const char* Car::GetType() { 
	return (char*)"NoType"; 
}
int Car::GetNumber()
{
	return number;
}
