#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

struct tagPlayer//플레이어 구조체
{
    int Money;
    int InchantPt;
};

//함수 오버로딩
void Opening();
bool MainGame();
void EndGame();
void Turning_Pages();