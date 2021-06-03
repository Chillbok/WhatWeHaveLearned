#include <iostream>
#include <string>
#include "windows.h"
#include "time.h"
using namespace std;

struct People
{
	string name;
	string Gender;
	int Lv;
}

void Gamestart()
{
	cout << "게임을 시작합니다.";
	system("pause");
	system("cls");
}

People making_character(People Maincharacter)
{
	for (;;)
	{
		cout << "1단계: 성별 정하기" << endl;
		cout << "=================" << endl;
		cout << "성별을 정해주세요." << endl;
		cout << "해당하는 성별을 그대로 적어주세요." << endl;
		cout << "1. Man" << "2. Woman" << endl;
		cin >> Maincharacter.Gender;
		cout << endl << endl;

		if (Maincharacter.Gender == "man" || Maincharacter.Gender == "Man")
		{
			Maincharacter.Gender = "Man";
			cout << "당신의 성별은 " << Maincharacter.Gender << " 입니다." << endl;
			break;
		}
		else if (Maincharacter.Gender == "Woman" || Maincharacter.Gender == "woman")
		{
			Maincharacter.Gender = "Woman";
			cout << "당신의 성별은 " << Maincharacter.Gender << " 입니다." << endl;
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 다시 입력하세요." << endl;
			continue;
		}
	}

	system("pause");
	system("cls");

	for (;;)
	{
		cout << "2단계: 이름 정하기" << endl;
		cout << "=================" << endl;
		cout << "이름을 골라주세요. 이름을 따로 적지 않은 경우 자동으로 디폴트 네임으로 설정됩니다.";
		cout << endl << "당신의 성별이 " << Maincharacter.Gender << " 인 경우:" << endl;
		cout << "--> 당신의 디폴트 네임은 "
		if (Maincharacter.Gender == "Man")
		{
			Maincharacter.name = "James";
			cout << Maincharacter.name;
		}
		else if (Maincharacter.Gender == "Woman")
		{
			Maincharacter.name = "Alice";
			cout << Maincharacter.name;
		}
		cout << "입니다." << endl << endl;
		
		cout << "이름을 적어주세요." << endl;
		cout << "디폴트 네임을 사용하길 원하신다면, '디폴트 네임'을 작성하고 엔터를 누르세요." << endl;
		string ChooseName = "";
		cin >> ChooseName;
		cout << endl;

		if (ChooseName == "디폴트 네임");
		{
			cout << "디폴트 네임을 사용하시겠습니까?" << endl;
			cout << "해당하는 번호를 골라주세요." << endl;
			cout << "1. yes" << endl << "2. no" << endl;
		}
		else
		{
			Maincharacter.name = ChooseName;
		}
	}
	return Maincharacter;
}

int main()
{
	People Maincharacter = {};
	Gamestart();
	making_character(Maincharacter);
	return 0;
}