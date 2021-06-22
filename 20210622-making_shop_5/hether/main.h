#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
#include <string.h>
using namespace std;

enum INVEN {INVEN_0, INVEN_T, INVEN_THR, INVEN_END};
enum ITEMGRADE {GRADE_NORMAL, GRADE_MAGIC, GRADE_LEGENO, GRADE_END};

struct tagPlayer//플레이어 구조체
{
	int Money;
	int InchantPt[INVEN_END];
	int Inventory[INVEN_END];
};

struct tagItem
{
	int Grade = 0;
	int Price = 0;
	string Name = "";
};


//함수 오버로딩
void Opening();
bool MainGame();
void EndGame();
