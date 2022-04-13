/*
	boolean타입
	bool is_alive = false; (true/false)
	
	배열 (자료구조)
	같은 데이터타입의 여러 변수를 하나의 묶음으로 나타낸 것.

	배열의 데이터타입에 대한 동일한 크기로 메모리상에 연속된 공간이 할당된다.
	배열명이 메모리 시작 주소이다.


	◆ 2차원 배열 및 다차원 배열
	배열이 (개념적으로) 2중으로, 다중으로 구성되어 있는 것. (실제로는 1차원임)

	1차원 배열 : int student_nums[5]; // 5개의 int
		-> 5명의 학생이 있다. 
	2차원 배열 : int student_nums[3][5]; // 15개의 int
		-> 3개 반에 각각 5명의 학생이 있다.
	3차원 배열 : int student_nums[4][3][5]; // 60개의 int
		-> 4개 학년에 각각 3개 반이 존재, 각 반에 5명의 학생이 있다.


	◆ (엔터 없이) 문자 하나를 입력받는 방법
	_getch();

	형변환 : 데이터 타입을 변환한다.
	- 묵시적 형변환 : char inputkey = _getch(); (int값이 char형이 된다)
	- 명시적 형변환 : 강제적으로 변환 (int)inputkey (char형을 강제적으로 int형으로 변환시킴)

*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	/*
		콘솔용 탈출게임
		10 * 10 크기의 맵을 구성한다. (2차원 배열)
		플레이어가 존재한다.
		탈출지점이 존재한다.
		WASD 키입력을 통해 플레이어를 이동시킨다.
		플레이어 시작 지점 : (0,0)
		탈출지점 : 플레이어 시작 지점을 제외한 랜덤 설정

		O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료

		(+장애물)

		#O########
		##########
		##########
		##########
		##########
		##########
		##########
		##########
		#######E##
		##########

		system("cls"); // 시스템 클리어 스크린
	*/

	// 초기 세팅

	srand(time(NULL));
	// 스테이지
	int stage = 1;

	//맵
	int mapSizeX = 10;
	int mapSizeY = 10;

	int map[10][10]; // 맵을 10 * 10으로 만들어주자.


	int mapValue = 0;

	//플레이어
	int player; // 플레이어 좌표 0
	char imgPlayer = 'O';

	//탈출지점
	int goal; // 탈출지점 좌표
	char imgGoal = 'E';

	// 맵 생성
	char imgMap = '#';

	for (int x = 0; x < mapSizeX; x++)
	{
		for (int y = 0; y < mapSizeY; y++)
		{
			map[x][y] = mapValue;
			mapValue++;

		}
	}

	while (true) // 크게 한 번 더 돌아~ 스테이지 바뀔 때
	{
		// 플레이어 초기 위치 세팅 (0,0)
		player = 0;

		// 초기 탈출지점 위치 세팅 (플레이어 자리를 제외한 위치)
		while (true)
		{
			int x = rand() % mapValue;

			if (player != x) // 좌표가 동일하지 않으면 넣어줌
			{
				goal = x; 
				break;
			}
		}

		// 초기 맵 표시
		system("cls"); // 맵 삭제
		cout << "[ " << stage << "Stage ]" << endl;
		for (int y = 0; y < mapSizeY; y++)
		{
			for (int x = 0; x < mapSizeX; x++)
			{
				if (map[x][y] == player) // 플레이어
				{
					cout << imgPlayer;
				}
				else if (map[x][y] == goal) // 탈출지점
				{
					cout << imgGoal;
				}
				else // 그 외 맵
				{
					cout << imgMap;
				}
			}
			cout << endl;
		}

		while (true) // 업데이트();
		{
			// 이동
			int inputKey = _getch();
			if (inputKey >= 97 && inputKey <= 122)
			{
				inputKey -= 32;
			}

			// WASD switch 문을 사용하여 새로운 좌표를 받아 player좌표에 넣어준다.
			// 이동할 공간이 없으면 무시한다.
			int newValue = player; // 새로 받을 좌표
			switch (inputKey)
			{
			case 87: //W
				for (int x = 0; x < mapSizeX; x++)
				{
					for (int y = 0; y < mapSizeY; y++)
					{
						if (map[x][y] == player)
						{
							if (y - 1 >= 0)
							{
								newValue = map[x][y - 1];
								break;
							}
						}
					}
				}
				player = newValue;
				break;

			case 83: //S
				for (int x = 0; x < mapSizeX; x++)
				{
					for (int y = 0; y < mapSizeY; y++)
					{
						if (map[x][y] == player)
						{
							if (y + 1 <= mapSizeY - 1)
							{
								newValue = map[x][y + 1];
								break;
							}
						}
					}
				}
				player = newValue;
				break;

			case 65: //A
				for (int x = 0; x < mapSizeX; x++)
				{
					for (int y = 0; y < mapSizeY; y++)
					{
						if (map[x][y] == player)
						{
							if (x - 1 >= 0)
							{
								newValue = map[x - 1][y];
								break;
							}
						}
					}
				}
				player = newValue;
				break;

			case 68: //D
				for (int x = 0; x < mapSizeX; x++)
				{
					for (int y = 0; y < mapSizeY; y++)
					{
						if (map[x][y] == player)
						{
							if (x + 1 <= mapSizeX - 1)
							{
								newValue = map[x + 1][y];
								break;
							}
						}
					}
				}
				player = newValue;
				break;

			default:
				break;
			}

			// 맵 표시
			system("cls"); // 맵 삭제
			cout << "[ " << stage << "Stage ]" << endl;
			for (int y = 0; y < mapSizeY; y++)
			{
				for (int x = 0; x < mapSizeX; x++)
				{
					if (map[x][y] == player) // 플레이어
					{
						cout << imgPlayer;
					}
					else if (map[x][y] == goal) // 탈출지점
					{
						cout << imgGoal;
					}
					else // 그 외 맵
					{
						cout << imgMap;
					}
				}
				cout << endl;
			}

			// 골인
			if (player == goal)
			{
				cout << "승리했습니다.";

				stage++; // 스테이지 카운트 증가
				break;
			}


		}
	
		// 더 할건가요??
		cout << "게임을 계속 하시겠습니까?......(y/n)" << endl;

		char continueGame = _getch();

		// n,N 누르면 종료, 나머지는 계속하기, 잘 못 눌러도 계속 하기ㅋ
		if (continueGame == 'n' || continueGame == 'N')
		{
			cout << "게임을 종료합니다.\n";
			break;
		}
			
	}



	/*
		실습
		A ~ Z 키 중에 하나를 정답으로 설정한다. (랜덤)
		유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
		유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료.
		틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오바.
	
		+ 틀렸을 때 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌트를 준다
		
		+ 입력된 값이 대/소문자 구분없이 처리될 수 있도록 수정해보자

	*/


	//srand(time(NULL));

	//// 아스키 코드 : A = 65 / Z = 90 / a = 97 / z = 122
	//int correct = rand() % (90 - 65 + 1) + 65;
	//int playTime = 1;
	//int maxChance = 5;
	//int inputKey;

	//cout << "총 5번 안에 정답을 맞추시오(대/소문자 구분 없음)..............(A ~ Z)" << endl;
	//
	//while (true)
	//{
	//	// 입력
	//	while (true)
	//	{
	//		inputKey = _getch();
	//		if (inputKey >= 97)
	//		{
	//			inputKey -= 32;
	//		}
	//		
	//		if (inputKey >= 65 && inputKey <= 90) // a~z까지 입력을 했다면
	//		{
	//			cout << (char)inputKey << " 을(를) 선택하였습니다." << endl;
	//			break; // while문 탈출
	//		}
	//		else 
	//		{
	//			cout << "잘못된 값을 입력하였습니다. 다시 입력해 주세요." << endl;
	//		}
	//	}
	//	// 소문자는 -32 해주는걸로 해야하나..
	//	
	//	// 승리
	//	if(inputKey == correct)
	//	{
	//		cout << "GameClear! 승리하였습니다. 게임을 종료합니다." << endl;
	//		break;
	//	}
	//	
	//	maxChance--;

	//	// 패배
	//	if (maxChance <= 0) 
	//	{
	//		cout << "당신은 패배자입니다. 정답은 " << (char)correct << " 입니다." << endl;
	//		
	//		cout << "다시 도전 하시겠습니까?..............(y/n)" << endl;
	//		
	//		inputKey = _getch();
	//		if (inputKey >= 97)
	//		{
	//			inputKey -= 32;
	//		}
	//		
	//		if (inputKey == 89) // y
	//		{
	//			//재도전
	//			playTime++;
	//			maxChance = 5;
	//			correct = rand() % (90 - 65 + 1) + 65;
	//			cout << playTime << "회차 시작!" << endl;
	//			cout << "총 5번 안에 정답을 맞추시오 (범위 : A ~ Z) (대/소문자 구분 없음)" << endl;
	//		}
	//		else // n 또는 그 외
	//		{
	//			// 게임종료
	//			cout << "GameOver...게임을 종료합니다." << endl;
	//			break;
	//		}
	//	}
	//	else 
	//	{
	//		// 힌트
	//		if (inputKey < correct)
	//		{
	//			cout << "선택한 알파벳 " << (char)inputKey << " 보다 뒤에 있습니다." << endl;
	//		}
	//		else
	//		{
	//			cout << "선택한 알파벳 " << (char)inputKey << " 보다 앞에 있습니다." << endl;
	//		}

	//		cout << "다시 선택해 주세요. (남은 기회 : " << maxChance << ")" << endl;
	//	}

	//}





	//// 엔터 없이 입력받기
	//while (true)
	//{
	//	int input_key =	_getch(); // 특정 키를 입력받으면 특정 키의 아스키 코드를 받아온다.
	//	cout << "int값 : " << input_key << endl;

	//	char input_key_char = input_key;
	//	cout << "Char값 : " << input_key_char << endl;
	//}

	//// 형변환
	//float testFloat = 1.5f;
	//float testFloat2 = (float)1.5;

	///*
	//	실습.
	//	구구단의 결과를 저장하는 2차원 배열을 하나 선언하고,
	//	2 * 1 = 2
	//	
	//	이중 for문을 이용하여 배열 변수에 구구단의 결과값을 저장하고,

	//	두 수를 입력받아서 적합한 결과값을 출력해보자.

	//	예시)
	//		(결과 저장 완료)
	//		몇 단을 볼까요? : _4
	//		몇을 곱할까요? : _7

	//		4 * 7 = 28
	//*/

	//int gogodan[8][9];

	//for (int i = 0; i < 8; i++) // 단은 8개까지 있음
	//{
	//	for (int j = 0; j < 9; j++) // 곱하는건 9개까지 있음
	//	{
	//		gogodan[i][j] = (i + 2) * (j + 1); // 2단부터 시작, 1부터 곱함
	//	}
	//}

	//int inputDan = 1;
	//int inputSu = 1;

	////입력 
	//cout << "[ 몇 단을 볼까요? ]" << endl;
	//while (true)
	//{
	//	cin >> inputDan;

	//	if(inputDan >= 2 && inputDan <= 9)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		cout << "※ 2 ~ 9 사이를 입력해 주세요." << endl;
	//	}
	//}

	//cout << "[ 몇을 곱할까요? ]" << endl;
	//while (true)
	//{
	//	cin >> inputSu;

	//	if (inputSu >= 1 && inputSu <= 9)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		cout << "※ 1 ~ 9 사이를 입력해 주세요." << endl;
	//	}
	//}

	//// 출력
	//cout << inputDan << " * " << inputSu << " = " << gogodan[inputDan-2][inputSu-1] << endl;


	//int student_nums[3][5] = { {1, 2, 3, 4, 5} ,
	//						   {6, 7, 8, 9, 10} ,
	//						   {11, 12, 13, 14, 15} };
	//// 순서대로 출력하는 코드

	//for (int j = 0; j < 3; j++)
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << student_nums[j][i] << endl;
	//	}
	//}

	//cout << student_nums[0][6] << endl; // [1][1]에 해당하는 7이 나옴


	//int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};

	//cout << nums << endl; // 00FEFAFC

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << &(nums[i]) << endl; 
	//}

	///*
	//	실습1. string형 배열변수 5개짜리 선언하고
	//	반복문을 통해 학생의 이름을 입력받는다.

	//	입력을 다 받고나서 1~5사이의 값을 입력하면 해당 학생의 이름이 출력된다.

	//	예시)
	//		1번째 학생의 이름을 입력하세요: __
	//		2번째 학생의 이름을 입력하세요: __
	//		3번째 학생의 이름을 입력하세요: __
	//		4번째 학생의 이름을 입력하세요: __
	//		5번째 학생의 이름을 입력하세요: __

	//		1 ~ 5 사이의 번호를 입력하세요 : _3
	//		3번째 학생의 이름은 ... 입니다.
	//*/
	//int chooseNumber;

	//string studentName[5];

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i+1 << "번째 학생의 이름을 입력하세요 : ";
	//	cin >> studentName[i];
	//}

	//cout << "1~5 사이의 번호를 입력하세요 : ";
	//cin >> chooseNumber;
	//if (chooseNumber >= 1 && chooseNumber <= 5)
	//{
	//	cout << chooseNumber << "번째 학생의 이름은 " << studentName[chooseNumber-1] << "입니다." << endl;
	//}
	//else
	//{
	//	cout << "그런 학생은 없습니다." << endl;
	//}
}