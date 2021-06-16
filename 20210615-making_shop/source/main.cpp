#include "main.h"


tagPlayer Player = {};

/*
1. 유저가 선택하도록 하기:
	1.1. 상점
		--> 상점 클래스의 매니지먼트 함수 호출
	1.2. 강화
		--> 강화 클래스의 매니지먼트 함수 호출
			유저의 선택의 결과에 따라서, 상점을 선택했다면 다시 한번 선택지가 뜬다.
			상점을 선택했다면 다시 한 번 유저의 선택을 받고,
			1. 구매
				구매를 선택해했다면, 구매 화면이 뜬다.
				--> 상점 클래스의 구매 함수 호출.
			2. 판매
				판매를 선택했으면, 판매 화면이 뜬다.
				--> 판매 클래스의 판매 함수 호출.
			3. 강화
				강화를 선택했으면, 강화 화면이 뜬다.
				--> 강화 클래스의 강화 함수 호출.
*/



//######################################################################



int main()//메인 함수
{
	//클래스(상점 파트) = 구매, 판매, 강화 클래스

	Management();

	return 0;
}



//---------------------------------------------------------------------



void Management()//관리 함수
{
	/*
	순서대로 유저의 선택이나 상황에 따라서 알맞은 장면을 호출한다.
	예전에 메인에서 하던 것을 여기에서 할 예정이다.
	*/
	/*
	//구성//
	오프닝부
	메인 게임부
		- 상점
			- 구매
			- 판매
		- 강화
	종료
	*	원래는 위 항목들은 하나 하나 전부 클래스로 따로 만들어주어야 한다.
		하지만 지금은 시간이 없기 때문에, 그냥 간략화해서 여기에 표현해주도록 하자.
	*/
	bool GameEnd = false;

	//오프닝부
	Opening();

	//메인게임부
	while (true)
	{
		GameEnd = MainGame();
		if (GameEnd == true) break;
	}

	//종료
	EndGame();
}


void Initialize()//초기화 함수
{
	Player.Money = 1000;//초기 자금
	Player.InchantPt = 0;//처음 가지고 있는 아이템 수치
}



void Opening()//게임 시작
{
	cout << "상점에 오신 것을 환영합니다." << endl;
	system("pause");
	int userinput = {};
	cout << "====================" << endl;
	cout << "Wellcome to 상점" << endl;
	cout << "====================" << endl;
	cout << "무엇을 하실 건가요?" << endl;
	cout << "1. 구매\t2. 판매\t3. 강화" << endl;
	cout << "하고 싶은 활동의 번호를 입력하세요" << endl;
	cout << "-->" << endl;
	cin >> userinput;
}



bool MainGame()//게임 플레이 도중
{
	Initialize();
	bool GameEnd = false;
	CInchant Inchant;

	int nUserInput = 0;
	/*
	메인 게임 화면은 알아서 꾸미도록 하자.
	*/

	/*
	유저의 선택의 결과에 따라서, 상점을 선택했다면 다시 한번 선택지가 뜬다.
	상점을 선택했다면 다시 한 번 유저의 선택을 받고,
	*/

	//1. 구매
	/*
		구매를 선택해했다면, 구매 화면이 뜬다.
		--> 상점 클래스의 구매 함수 호출.
	*/
	//2. 판매
	/*
	판매를 선택했으면, 판매 화면이 뜬다.
		--> 판매 클래스의 판매 함수 호출.
	*/

	//3. 강화
	/*
	강화를 선택했으면, 강화 화면이 뜬다.
		--> 강화 클래스의 강화 함수 호출.
	*/

	while (true)
	{
		//메인게임 화면은 알아서 꾸미자
		system("cls");
		cout << "1. 상점" << endl;
		cout << "2. 강화" << endl;
		cin >> nUserInput;

		if (nUserInput == 1)				//상점
		{
			cout << "구현 중인 기능입니다." << endl;
			cout << "업데이트 예정" << endl;
			Sleep(300);
		}
		else if (nUserInput == 2)
		{
			Inchant.Management(Player.Money, Player.InchantPt);
		}
		else if (nUserInput == 3)
		{
			GameEnd = true;
			break;
		}
		else
		{
			cout << "없는 선택지를 선택" << endl;
			Sleep(300);
		}
	}

	return GameEnd;
}



void EndGame()//게임 종료
{
	cout << "안녕히 가세요" << endl;
	Sleep(300);
}

void Turn_the_Page()//페이지 넘기는 함수(일시정지 --> 페이지 지우기) 
{
	system("pause");
	system("cls");
}