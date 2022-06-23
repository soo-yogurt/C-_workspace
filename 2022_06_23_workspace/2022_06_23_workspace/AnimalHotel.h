#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<cstring>
#include<cstdint>
#include "Animal.h"
using namespace std;

// ȣ�� Ŭ�������� ��� �ؾ� Animal Ŭ������ ������ ����� �� ������ �߸𸣰ڽ��ϴ�.

class AnimalHotel
{
	enum {
		LASTROOMNUMBER = 8
	};

	// ȣ�������� ������ �־���ϴ� �մ� ������� �������� �ۼ��Ͽ���.
	typedef struct {
		char* name;
		char* type;
	}GUEST;

	typedef struct {
		int roomNum;
		GUEST guest;
	}ROOM;

private:
	ROOM* room = new ROOM[LASTROOMNUMBER];
public:
	AnimalHotel()
	{
		// ������� �ƴ��� �մ��� �̸��� ���� Ȯ���Ѵ�. �̸��� 0�̸� ���
		memset(room, 0, sizeof(ROOM) * LASTROOMNUMBER);
		// ȣ�� ��ȣ�� ���ϴ� �κ��̴�. 1ȣ�� 2ȣ��... ���� ����ϰ�  �ֱ� ������ ���� �ڵ忡���� ũ�� �ǹ� ����.
		// ���ǿ� ���� 101ȣ 102ȣ������ �ٲٱ� ���� �ۼ��Ͽ���.
		for (int i = 0; i < 8; i++)
			room[i].roomNum = i + 1;
	}
	~AnimalHotel()
	{
		delete[] room;
	}

	
	void CheckIn(const int room, const char* _name, const char* _type); // �Խǿ� �ʿ��� ������ �޾� üũ��
	int checkRoom(); // ����ڰ� ����ִ� �游 �� �� �ְ� ���ش�.
	char* CheckOut(); // ȣ���� ���ϸ� üũ�ƿ��� �� �� �ִ�.
	void FrontDesk();// ���� �޴��� �ҷ��´�.
	void List(); // ȣ�Ǻ��� �Խ� ��Ȳ�� �˷��ش�.

};