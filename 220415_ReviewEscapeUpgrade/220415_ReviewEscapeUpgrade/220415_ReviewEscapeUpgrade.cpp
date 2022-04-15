
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct position
{
	int x;
	int y;
};

struct field
{
	int value;
	string img;
	int damage;
	bool isMove;
};

struct map
{
	position pos;
	field field;
} map[30][30];

struct player 
{
	position startPos;
	position pos;
	int maxHP;
	int nowHP;
} player ;

// 0 : 이동가능
// 1 : 늪
// 2 : 숲
// 3 : 탈출구
// 4 : 플레이어

int getKey;

int main()
{
	system("mode con: cols=100 lines=40");
	// 초기 세팅
	srand(time(NULL));

	// 초기 맵 생성
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			map[x][y].field.value = rand() % 3;
		}
	}

	// 플레이어 위치
	player.maxHP = 100;
	player.nowHP = player.maxHP;

	player.startPos.x = 0;
	player.startPos.y = 0;
	player.pos = player.startPos;

	// 탈출구 위치
	map[rand()%30][rand() % 30].field.value = 3;

	while (true) // 업데이트
	{
		// 맵 갱신
		system("cls");
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
		cout << endl;
		for (int y = 0; y < 30; y++)
		{
			cout << "■";
			for (int x = 0; x < 30; x++)
			{
				if (player.pos.x != x || player.pos.y != y) 
				{
					cout << map[x][y].field.img;

					switch (map[x][y].field.value)
					{
					case 0 :
						cout << "  ";
						break;
					case 1:
						cout << "♤";
						break;
					case 2:
						cout << "＊";
						break;
					case 3:
						cout << "■";
						break;
					default:
						break;
					}
				}
				else
				{
					cout << "●";
				}
			}
			cout << "■";
			cout << endl;
		}
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		cout << "■                                                            ■\n";
		printf ("■   남은 체력 : %3d    \t                              ■\n", player.nowHP);
		cout << "■                                                            ■\n";
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

		player.nowHP -= map[player.pos.x][player.pos.y].field.value;

		if (map[player.pos.x][player.pos.y].field.value == 3)
		{
			cout << "\n게임클리어";
			break;
		}


		if (player.nowHP <= 0)
		{
			cout << "\nYOUDIE";
			break;
		}


		getKey = _getch(); // 키 입력
		if (getKey >= 65 && getKey <= 90) { //입력한게 대문자였을경우 소문자로 변환
			getKey += 32;
		}
		
		switch (getKey)
		{
		case 'w' :
			if (player.pos.y > 0)
			{
				player.pos.y--;
			}
			break;
		case 's':
			if (player.pos.y < 29)
			{
				player.pos.y++;
			}
			break;
		case 'a':
			if (player.pos.x > 0)
			{
				player.pos.x--;
			}
			break;
		case 'd':
			if (player.pos.x < 29)		
			{
				player.pos.x++;
			}
			break;
		default:
			break;
		}

	}
}