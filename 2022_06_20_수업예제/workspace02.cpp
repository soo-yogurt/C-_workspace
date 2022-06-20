#include <iostream>

using namespace std;
class Sosimple
{
private:
	int num;
public:
	Sosimple(int n) : num(n)
	{}
	Sosimple(const Sosimple& copy) : num(copy.num)
	{
		std::cout << "Called SoSimple(const Sosimple& copy)\n";
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
	~Sosimple()
	{
		cout << "destroy obj: " << num << endl;
	}

};

void SimpleFuncObj(Sosimple ob)
{
	ob.ShowData();
}

//int main(void)
//{
//	Sosimple obj(7);
//	cout << "�Լ�ȣ�� ��" << endl;
//	SimpleFuncObj(obj);
//	cout << "�Լ�ȣ�� ��" << endl;
//	return 0;
//}