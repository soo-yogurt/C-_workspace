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
		void AddDrink(char* name1, int price1, int num1, char* name2, int price2, int num2, char* name3,
			int price3, int num3, char* name4, int price4, int num4);
		void SetMoney();
		void SetMoney(int money);
		int GetMoney();
		void PushDrink(const int num);

		void PrintDrinkList();
		void PrintPushDrink(const int num);

	};



}