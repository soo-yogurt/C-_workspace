#pragma once


namespace VendingMahing1 {
	enum {
		NUM_MAX = 4,
		NAME_LEN_MAX = 10
	};

	class VendingMachine
	{
	/*	DRINK drink[NUM_MAX];*/
		int money;

	public:
		void InitMembers();
	};

	typedef struct
	{
		char drinkName[NAME_LEN_MAX];
		int price;
		int numOfdrink;
	} DRINK;

}