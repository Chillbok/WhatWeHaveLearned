#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;



struct tagPlayer //플레이어 구조체
{
    int Money;
    int InchantPt[INVEN_END];
    int Inventory[INVEN_END];
};

//함수 오버로딩
void Openning();
bool MainGame();
void EndGame();
