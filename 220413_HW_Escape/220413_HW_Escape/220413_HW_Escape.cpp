#include <iostream>
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

		(+) 추가 작업
		스테이지 구성
		게임을 클리어하면 계속할 것인지 여부를 묻는다
		계속 하면 스테이지가 증가하고
		탈출 지점이 변경된 새로운 스테이지가 출력된다.
	*/

	// 초기 세팅

	srand(time(NULL));
	// 스테이지
	int stage = 1;

	//맵
	int mapSizeX = 10;
	int mapSizeY = 10;

	int map[10][10]; // 맵을 10 * 10으로 만들어주자.
	// 배열에 변수는 안 들어가네 -_-


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
}
