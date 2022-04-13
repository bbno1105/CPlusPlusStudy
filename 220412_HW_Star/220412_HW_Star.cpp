// 220412_HW_Star.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	/*
		별찍기
		1) 별-빈
		*
		**
		***
		****
		*****
		
		2) 빈-별
		    *
		   **
		  ***
		 ****
		*****

		3) 별-빈
		*****
		****
		***
		**
		*

		4) 빈-별
		*****
		 ****
		  ***
		   **
		    *
			
		5) 빈-별-빈
		    *
		   ***
		  *****
		 *******
		*********

		6) 빈-별-빈
		*********
		 *******
		  *****
		   ***
			*

		7) 빈-별-빈
			*
		   ***
		  *****
		 *******
		*********
		 *******
		  *****
		   ***
			*
	
	*/

	//int maxStar;
	//cout << "그려볼 별의 숫자를 선택하시오 (과제5) : " << endl;
	//cin >> maxStar;
	

	cout << "\n[실습1]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//별
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}

		//빈칸
		for (int j = 0; j < 4 - i; j++)
		{
			cout << " ";
		}

		cout << endl;
	}

	cout << "\n[실습2]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//빈칸
		for (int j = 0; j < 4 - i; j++)
		{
			cout << " ";
		}

		//별
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}


	cout << "\n[실습3]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//별
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}

		//빈칸
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		cout << endl;
	}


	cout << "\n[실습4]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//빈칸
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		//별
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cout << "\n[실습5]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//빈칸
		for (int j = 0; j < 4 - i; j++)
		{
			cout << " ";
		}

		//별
		for (int j = 0; j < 1 + (2 * i); j++)
		{
			cout << "*";
		}

		//빈칸
		for (int j = 0; j < 4 - i; j++)
		{
			cout << " ";
		}

		cout << endl;
	}


	cout << "\n[실습6]" << endl;

	for (int i = 0; i < 5; i++)
	{
		//빈칸
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		//별
		for (int j = 0; j < 9 - (2 * i); j++)
		{
			cout << "*";
		}

		//빈칸
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		cout << endl;
	}


	cout << "\n[실습7]" << endl;

	for (int i = 0; i < 9; i++)
	{
		//빈칸
		for (int j = 0; j < abs(4 - i); j++)
		{
			cout << " ";
		}

		//별
		for (int j = 0; j < 9 - (2 * abs(4 - i)); j++)
		{
			cout << "*";
		}

		//빈칸
		for (int j = 0; j < abs(4 - i); j++)
		{
			cout << " ";
		}

		cout << endl;
	}

	int MAX_LINE = 5;

	for (int line = -MAX_LINE + 1; line < MAX_LINE; line++)
	{
		for (int space = 0; space < abs(line); space++)
		{
			cout << "-";
		}
		for (int star = 0; star < (MAX_LINE - abs(line) - 1) * 2 + 1; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
