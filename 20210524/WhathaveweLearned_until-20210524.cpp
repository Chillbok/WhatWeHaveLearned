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
  //  \t의 경우
  cout << "\" << "t 예시: " << endl;
  cout << "안녕하세요\t저는\t사람입니다." << endl << endl;
  cout << "======================" << endl << endl;

  //  \n의 경우
  cout << "\" << "n 예시: " << endl;
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

void Parameter()//변수
{
  string ParameterList;
  /*
  변수란?
    - 변할 수 있는 수
    - 데이터(data)를 저장할 수 있는 메모리 공간
    - 데이터를 저장하기 위해 프로그램에 의해서, 이름을 할당받은 메모리 공간
    - 변수는 크게 정수형 변수와 실수형 변수로 구분한다.

  변수의 생성)
    변수의 선언: 타입(자료형) 변수명;
      --> 예시: int Number;

  타입(자료형)
    1. 정수형
      char(캐릭터): 1byte signed 변수
      int: integer 1byte signed 변수
    2. 실수형
      float: 4byte signed 변수
      double: 8byte signed 변수

  변수명)
    - 알아보기 쉽게 짓기
    - 표기법의 종류:
      --> 헝가리안: 변수명 앞에 변수의 자료형을 뜻하는 문자는 붙여서 표시하는 법
          정수형: i, n
          실수형: f
          문자열: sz, str

  변수명 생성 규칙(*반드시 지켜야 함*)
    - 변수 이름은 영어와 언더바(_)로만 구성한다.
    - 숫자는 변수에서 가장 처음에 올 수 없다.
      --> 예시: 1Number(X), Number1(O)
    - 공백 불가
      --> 예시: Player Name(X), Player_Name(O)
    - 예약어는 사용 불가능
      --> int struct(X)
    - 변수명 길이에는 제한이 없다.

    - 선언하고자 하는 변수의 타입(자료형)이 같다면, 한 번에 묶어서 복수의 변수를 선언할 수 있다.
      --> 예시: int a, float b;  (X)
          int a, b;  (O)

    - 선언과 동시에 초기화할 수 있다.
      --> 예시: int a;
                a = 0;
                int a = 0; --> 선언과 동시에 초기화하기
                위의 두 개는 같은 것이다.
          복수 선언했을 때
                int a = 0, b = 0;과 같이 선언과 동시에 초기화할 수 있다.
  */
  for(;;)
  {
    system("cls");
    cout << "1. 변수의 의미" << endl;
    cout << "2. 변수의 생성" << endl;
    cout << "3. 타입(자료형)" << endl;
    cout << "4. 변수명" << endl;
    cout << "5. 변수명 생성 규칙" << endl;

    cout << "보고싶은 소단원의 제목을 적으세요." << endl;
    cout << "제목: ";
    cin >> ParameterList;

    system("cls");

    if (ParameterList = "qustndml dmlal" || ParameterList == "변수의 의미")//1. 변수의 의미
    {
      cout << "변수의 의미)" << endl;
      cout << "1. 변할 수 있는 수" << endl;
      cout << "2. 데이터를 저장할 수 있는 메모리 공간" << endl;
      cout << "3. 데이터를 저장하기 위해 프로그램에 의해서, 이름을 할당받은 메모리 공간" << endl;
      cout << "변수는 크게 정수형 변수와 실수형 변수로 구분한다." << endl << endl;
    }
    else if (ParameterList = "변수의 생성" || ParameterList = "qustndml todtjd")//2. 변수의 생성
    {
      cout << "변수의 생성)" << endl;
      cout << "변수의 생성 = 변수의 선언" << endl << endl;
      cout << "타입(자료형) 변수명;" << endl;
      cout << "\t" << "예시: int Number;" << endl;
    }
    else if (ParameterList = "타입" || ParameterList = "xkdlq" || ParameterList = "자료형" || ParameterList = "wkfygud")//3. 타입(자료형
    {
      cout << "변수의 생성)" << endl;
      cout << "1. 정수형" << endl;
      cout << "\t" << "char(캐릭터): 1byte signed 변수" << endl;
      cout << "\t" << "int(integer): 1byte signed 변수" << endl;
      cout << "2. 실수형" << endl;
      cout << "\t" << "float: 4byte signed 변수" << endl;
      cout << "\t" << "double: 8byte signed 변수" << endl;
    }
    else if (ParameterList = "qustnaud" || ParameterList = "변수명")//4. 변수명
    {
      cout << "변수명)" << endl;
      cout << "1. 알아보기 쉽게 짓기" << endl;
      cout << "2. 표기법의 종류: " << endl;
      cout << "\t헝가리안: 변수명 앞에 변수의 자료형을 뜻하는 문자를 붙여서 표시하는 법" << endl;
      cout << "\t정수형: i, n" << endl;
      cout << "\t실수형: f" << endl;
      cout << "\t문자열: sz, str" << endl;
    }
    else if (ParameterList = "변수명 생성 규칙" || ParameterList = "qustnaud todtjd rbclr")//5. 변수명 생성 규칙
    {
      cout << "변수명 생성 규칙" << endl;
      cout << "\t- 아래 내용은 반드시 지켜야 한다." << endl;
      cout << "\t- 변수 이름은 영어와 언더바(_)로만 구성한다." << endl;
      cout << "\t- 숫자는 변수에서 가장 처음에 올 수 없다." << endl;
      cout << "\t\t--> 예시: 1Number(X), Number1(O)" << endl;
      cout << "\t- 공백 불가" << endl;
      cout << "\t\t--> 예시: Player Name(X), Player_Name(O)" << endl;
      cout << "\t- 예약어는 사용 불가능" << endl;
      cout << "\t\t--> int struct(X)" << endl;
      cout << "\t- 변수명 길이에는 제한이 없다." << endl << endl;
      cout << "\t- 선언하고자 하는 변수의 타입(자료형)이 같다면, 한 번에 묶어서 복수의 변수를 선언할 수 있다."













    }
  }



  cout << "\t" << "int(integer): 1byte signed 변수" << endl;
  cout << "2. 실수형" << endl;
  cout << "\t" << "float: 4byte signed 변수" << endl;
  cout << "\t" << "double: 8byte signed 변수" << endl;
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
