#include <iostream>
#inclde <string>
#include <Windows.h>
#include "time.h"

using namespace std;

void Continue_Chapter()//계속
{
  cout << "Enter를 눌러서 계속" << endl << endl;
  system("pause");
  system("cls");
}



void C_and_Cpp_both()//C와 C++에서 모두 사용하는 것들
{
  /*
  이스케이프 시퀸스: 역슬래시하고 쓰는 것들

  대표적인 예시: \t, \n, \v, ...
  */
  //\t
  /*
  tab을 사용해주는 이스케이프 시퀸스이다.
  */
  cout << "\" << "t 예시: " << endl;
  cout << "안녕하세요\t저는" << endl;
  cout << "/t사람입니다." << endl << endl;
  cout << "======================" << endl << endl;

  //\n 예시
  /*
  줄을 바꾸어주는 이스케이프 시퀸스이다.
  endl과 같은 용도로 사용된다.
  */
  cout << "안녕하세요.\n저는\n사람입니다." << endl;
}

void Input_in_C()//C에서의 입력
{
  /*
  입력: scanf("서식문자", 입력받을 내용의 주소값);
  출력은 안에 값이 이미 있기 때문에 얼마만큼을(크기)
  출력하면 되는가에 대해서 미리 알 수 있다.

  입력을 받을 때는 유저가 얼마만큼을 입력할지를 가늠할 수가 없다.
    --> 아이디 만들때: 2글자, 4글자, 5글자, ... / 예상 불가.
  */
  int num;//입력받아서 담아둘 변수.
  //사용하기 위해서 프로젝트 속성 --> 언어 --> 준수 모드 --> 아니요 선택
  scanf_s("%d", &num);
  printf("%d", num);
}

void Input_in_Cpp()//Cpp에서 입출
{
  /*
  C++에서의 출력: cout <<
  C++에서의 입력: cin >>
  */
  //예시
  cout << "C++에서의 입출력 사용법" << endl;
  int CppInput;
  cout << "입력 숫자: "
  cin >> CppInput;
  cout << CppInput + 2;
  /*
  따라서 마지막에 출력되는 것은 유저가 입력한 숫자에 2를 더한 내용이다.
  */
}

int main()
{
  int ChapterNumber = 0;
  string ContinueOrStop = 0;
  for(;;)
  {
    ChapterNumber = 0;

    cout << "출력할 챕터를 고르세요" << endl << endl;
    cout << "1. C와 C++에서 공통" << endl;
    cout << "2. C에서 입출력 사용" << endl;
    cout << "3. C++에서 입출력 사용" << endl;

    cout << "선택은?" << endl;
    cout << "--> ";
    cin >> ChapterNumber;
    if (ChapterNumber = 1)
    {
      C_and_Cpp_both();
    }
    else if (ChapterNumber = 2)
    {
      Input_in_C();
    }
    else if (ChapterNumber = 3)
    {
      Input_in_Cpp();
    }
    else
    {
      cout << "번호를 잘못 입력하셨습니다. 다시 입력하세요.";
      system("cls");
      continue;
    }

    system("cls");
    cout << "다른 챕터도 학습하시겠습니까?" << endl;
    cout << "네 또는 아니요를 입력해주세요:" << endl;
    cin >> ContinueOrStop;
    if (ContinueOrStop = "네" || ContinueOrStop = "sp")
    {
      continue;
    }
    else if (ContinueOrStop = "아니요" || ContinueOrStop = "아니오" || ContinueOrStop = "dksldy" || ContinueOrStop = "dksldh")
    {
      break;
    }
  }

  return 0;
}
