#include "Car.h"


Car::Car(int _num)
{
	number = _num;
}

// �ڷ����� (char*)�� ��ȯ �Ѵٴ� ���� ��ȯ ���������� ���� ���� �� �� �ִٴ�
// ���� �ǹ��Ѵ�. ������ ����� ������ ĳ���� �Ͽ��� ��ȯ �Ͽ��⶧���� ������ �Ұ����� �����̴�.
// ������ �ǹ̸� ��Ȯ�� �˷��ֱ� ���� �ڷ����� const char*�� �����Ͽ���.
const char* Car::GetType() { 
	return (char*)"NoType"; 
}
int Car::GetNumber()
{
	return number;
}
