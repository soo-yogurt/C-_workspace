#pragma once


namespace VendingMahing1 {
	enum {
		NUM_MAX = 4,
		NAME_LEN_MAX = 10
	};

	typedef struct
	{
		char drinkName[NAME_LEN_MAX];
		int price;
		int numOfdrink;
		int buttonNumber;
	} DRINK;

	class VendingMachine
	{
	private:
		DRINK drink[NUM_MAX];
		int money = 0;

	public:
		// 구조체 초기화를 위한 함수, main에서 생성한 구조체를 한번에 전달하고 싶었지만
		// 방법을 몰라 맴버 변수 하나하나를 매개변수로 넣었습니다.
		void AddDrink(char* name1, int price1, int num1, char* name2, int price2, int num2, char* name3,
			int price3, int num3, char* name4, int price4, int num4);
		// 매개변수가 없을 경우 자판기가 가지고 있는 금액이 0 이되도록 한다. // 돈을 반환하는 함수
		void SetMoney();
		// 사용자가 입력한 금액 만금 class 내 맴버 변수money값에 더 해진다.
		void SetMoney(int money);
		// 사용자가 맴버 변수 money를 볼 수 있다.
		int GetMoney();
		// num 값에 맞는 음료가 존재하고 돈이 있다면 맴버 변수 nmOfdrink와 money가 감소한다.
		void PushDrink(const int num);
		// 현재 남아있는 음료 리스트를 출력 할 수 있다.
		void PrintDrinkList();
		// 음료의 구매가 가능한지 구매가 되었는지 여부를 알려준다.
		void PrintPushDrink(const int num);
		// 남은 금액으로 살 수있는 음료가 있는지 확인하는 함수이다.
		bool CheckingAccounts();
	};

}