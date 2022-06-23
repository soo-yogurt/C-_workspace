#include <iostream>

using namespace std;

class First
{
public:
	void FisrtFunc() {
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() {
		cout << "Second's SecondFunc()" << endl;
	}
	
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

//int main(void)
//{
//	Third obj;
//	obj.FisrtFunc();
//	obj.SecondFunc();
//	obj.ThirdFunc();
//	obj.SimpleFunc();
//	cout << "\n";
//	Second& sref = obj;
//	sref.FisrtFunc();
//	sref.SecondFunc();
//	sref.SimpleFunc();
//	
//	cout << "\n";
//	First& fref = obj;
//	fref.FisrtFunc();
//	fref.SimpleFunc();
//
//
//	return 0;
//}