#pragma once
#include <iostream>
#include <windows.h>
#include "Cbuy.h"
#include "CSell.h"
#include "CInchant.h"
using namespace std;

struct tagPlayer//
{
	int Money = 0;
	int InchantPt = 0;
};

//함수 오버로딩
void Opening();
bool MainGame();
void EndGame();