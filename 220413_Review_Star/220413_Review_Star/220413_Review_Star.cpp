// 220413_Review_Star.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
	//int number;
	//cin >> number;

	//int lineValue = (2 * number) - 1; //홀수 줄

	//for (int i = 1; i <= lineValue; i++) // 줄 수 만큼 반복해서 그려준다.
	//{
	//	// 별
	//	for (int j = 0; j < ((lineValue+1) - abs((lineValue + 1) - (2 * i))) / 2; j++)
	//	{
	//		cout << "*";
	//	}

	//	// 빈
	//	for (int j = 0; j < abs((lineValue + 1) - (2 * i)); j++)
	//	{
	//		cout << " ";
	//	}

	//	// 별
	//	for (int j = 0; j < ((lineValue + 1) - abs((lineValue + 1) - (2 * i))) / 2; j++)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}
	//int c = 1;
	//int n = 5;
	////scanf("%d", &n);
	//for (int i = 1; i < 2 * n; i++) // 9줄 그려준다 (세로)
	//{
	//	for (int j = 1; j <= 2 * n; j++) // 10개 그려준다 (가로)
	//	{
	//		bool test1 = j <= c;
	//		bool test2 = j > 2 * n - c;
	//		printf((test1 || test2 ? "*" : " "));
	//	}
	//	c += i >= n ? -1 : 1; // 절반(n)을 넘어가면 -1, 안넘어가면 1
	//	puts(""); 
	//}

	int number;
	int starCount = 1;
	cin >> number;

	for (int i = 1; i <= (2 * number)-1; i++) // 2n-1 줄
	{
		for (int j = 0; j < starCount; j++) // 별찍기
		{
			cout << "*";
		}

		if(i >= number)
		{
			starCount--;
		}
		else
		{
			starCount++;
		}


		cout << endl;
	}
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
