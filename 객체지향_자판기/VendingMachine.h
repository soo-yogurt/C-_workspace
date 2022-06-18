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
		// ����ü �ʱ�ȭ�� ���� �Լ�, main���� ������ ����ü�� �ѹ��� �����ϰ� �;�����
		// ����� ���� �ɹ� ���� �ϳ��ϳ��� �Ű������� �־����ϴ�.
		void AddDrink(char* name1, int price1, int num1, char* name2, int price2, int num2, char* name3,
			int price3, int num3, char* name4, int price4, int num4);
		// �Ű������� ���� ��� ���ǱⰡ ������ �ִ� �ݾ��� 0 �̵ǵ��� �Ѵ�. // ���� ��ȯ�ϴ� �Լ�
		void SetMoney();
		// ����ڰ� �Է��� �ݾ� ���� class �� �ɹ� ����money���� �� ������.
		void SetMoney(int money);
		// ����ڰ� �ɹ� ���� money�� �� �� �ִ�.
		int GetMoney();
		// num ���� �´� ���ᰡ �����ϰ� ���� �ִٸ� �ɹ� ���� nmOfdrink�� money�� �����Ѵ�.
		void PushDrink(const int num);
		// ���� �����ִ� ���� ����Ʈ�� ��� �� �� �ִ�.
		void PrintDrinkList();
		// ������ ���Ű� �������� ���Ű� �Ǿ����� ���θ� �˷��ش�.
		void PrintPushDrink(const int num);
		// ���� �ݾ����� �� ���ִ� ���ᰡ �ִ��� Ȯ���ϴ� �Լ��̴�.
		bool CheckingAccounts();
	};

}