#include <iostream>﻿
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	char inputKey = 0; // 첫 게임 화면에서 키입력 변수
	bool inputEasy = true; // 이지모드 on/off
	bool haveKey = false; // 열쇠 아이템 보유 on/off
	int stage_count = 0; // 스테이지 변수
	int move_count = 0; // 움직인 횟수 변수
	int total_move_count = 0; // 총 움직인 횟수 변수
	int x = 0, y = 0;

	//문 좌표 전체 지정
	struct position
	{
		int x;
		int y;
	};

	struct state
	{
		int value;
		int damage;
	};

	struct field
	{
		position pos;
		state stat;
		bool isMove;
	};

	struct stage
	{
		int Count;
		field field[10][10];
	} stage[3];


	struct player
	{
		position pos;
		int pirodo = 0;
	} player;



	int map[3][10][10] = {
					   { {0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
						 {0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
						 {1, 1, 0, 0, 0, 0, 1, 1, 0, 1},
						 {1, 0, 0, 1, 1, 0, 1, 1, 0, 0},
						 {0, 0, 1, 1, 1, 0, 1, 1, 1, 0},
						 {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
						 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
						 {1, 0, 0, 1, 0, 0, 1, 0, 0, 0} },

					   { {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
						 {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
						 {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
						 {0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
						 {0, 0, 1, 0, 0, 0, 0, 7, 0, 0},
						 {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
						 {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
						 {1, 1, 1, 1, 7, 1, 0, 0, 0, 0},
						 {0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
						 {0, 0, 0, 0, 1, 0, 0, 1, 0, 0} },

					   { {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
						 {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
						 {0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
						 {1, 0, 0, 0, 1, 1, 0, 0, 7, 0},
						 {1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
						 {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
						 {0, 1, 1, 1, 1, 7, 0, 0, 1, 0},
						 {0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
						 {1, 7, 0, 0, 0, 0, 1, 0, 1, 0},
						 {1, 1, 0, 1, 0, 1, 1, 0, 0, 0} }
	}; // [10][10] 맵 3개

	// 필드에 데이터 넣어주기
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				stage[i].Count = i;
				stage[i].field[x][y].pos.x = x;
				stage[i].field[x][y].pos.y = y;
				stage[i].field[x][y].stat.value = map[i][x][y];
			}
		}
	}

	//struct door
	//{
	//	position pos;
	//} stage2_door1, stage2_door2,
	//	stage3_door1, stage3_door2, stage3_door3;

	//stage2_door1.pos = { 4,7 };
	//stage2_door2.pos = { 7,4 };
	//stage3_door1.pos = { 3,8 };
	//stage3_door2.pos = { 5,6 };
	//stage3_door3.pos = { 8,1 };


	//int player_xposition = 0; // 플레이어 x좌표
	//int player_yposition = 0; // 플레이어 y좌표
	//int escape_xposition[3]; // 탈출구 x좌표배열
	//int escape_yposition[3]; // 탈출구 y좌표배열
	char input_move_key = 0; //이동 키보드 입력변수

	//스테이지 열쇠 위치 랜덤
	//int stage2_key_x = rand() % 5 + 1;
	//int stage2_key_y = rand() % 5 + 1;
	//int stage3_key_x = rand() % 5 + 1;
	//int stage3_key_y = rand() % 5 + 1;


	while (1) {
		if (inputKey == 0) {
			cout << endl;
			cout << "  ■■■■    ■■■    ■■■    ■■    ■■■    ■■■■" << endl;
			cout << "  ■        ■        ■        ■    ■  ■    ■  ■" << endl;
			cout << "  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■" << endl;
			cout << "  ■              ■  ■        ■    ■  ■        ■" << endl;
			cout << "  ■■■■  ■■■      ■■■  ■    ■  ■        ■■■■" << endl << endl << endl;

			cout << "            ■■■    ■■    ■      ■  ■■■■" << endl;
			cout << "          ■        ■    ■  ■■  ■■  ■" << endl;
			cout << "          ■  ■■  ■■■■  ■  ■  ■  ■■■■" << endl;
			cout << "          ■    ■  ■    ■  ■  ■  ■  ■" << endl;
			cout << "            ■■■  ■    ■  ■  ■  ■  ■■■■" << endl << endl << endl;

			cout << "                        ★ EASY ★" << endl << endl;
			cout << "                           HARD" << endl;
		}

		inputKey = _getch();
		if (inputKey >= 65 && inputKey <= 90) { //입력한게 대문자였을경우 소문자로 변환
			inputKey += 32;
		}

		while ((inputKey == 'w') || (inputKey == 's')) {
			system("cls");

			switch (inputKey) {
			case 'w':
				cout << endl;
				cout << "  ■■■■    ■■■    ■■■    ■■    ■■■    ■■■■" << endl;
				cout << "  ■        ■        ■        ■    ■  ■    ■  ■" << endl;
				cout << "  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■" << endl;
				cout << "  ■              ■  ■        ■    ■  ■        ■" << endl;
				cout << "  ■■■■  ■■■      ■■■  ■    ■  ■        ■■■■" << endl << endl << endl;

				cout << "            ■■■    ■■    ■      ■  ■■■■" << endl;
				cout << "          ■        ■    ■  ■■  ■■  ■" << endl;
				cout << "          ■  ■■  ■■■■  ■  ■  ■  ■■■■" << endl;
				cout << "          ■    ■  ■    ■  ■  ■  ■  ■" << endl;
				cout << "            ■■■  ■    ■  ■  ■  ■  ■■■■" << endl << endl << endl;

				cout << "                        ★ EASY ★" << endl << endl;
				cout << "                           HARD" << endl;

				inputEasy = true;

				break;

				/*case 's':
					cout << endl;
					cout << "  ■■■■    ■■■    ■■■    ■■    ■■■    ■■■■" << endl;
					cout << "  ■        ■        ■        ■    ■  ■    ■  ■" << endl;
					cout << "  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■" << endl;
					cout << "  ■              ■  ■        ■    ■  ■        ■" << endl;
					cout << "  ■■■■  ■■■      ■■■  ■    ■  ■        ■■■■" << endl << endl << endl;

					cout << "            ■■■    ■■    ■      ■  ■■■■" << endl;
					cout << "          ■        ■    ■  ■■  ■■  ■" << endl;
					cout << "          ■  ■■  ■■■■  ■  ■  ■  ■■■■" << endl;
					cout << "          ■    ■  ■    ■  ■  ■  ■  ■" << endl;
					cout << "            ■■■  ■    ■  ■  ■  ■  ■■■■" << endl << endl << endl;

					cout << "                           EASY" << endl << endl;
					cout << "                        ★ HARD ★" << endl;

					inputEasy = false;

					break;
				}*/

				inputKey = _getch();
				if (inputKey >= 65 && inputKey <= 90) { //입력한게 대문자였을경우 소문자로 변환
					inputKey += 32;
				}
			}

			if (inputKey == 32) {
				break;
			}
		}
		// 랜덤한 열쇠 배치
		for (int i = 0; i < 3; i++)
		{
			int x, y;
			do
			{
				x = rand() % 5 + 1;
				y = rand() % 5 + 1;
			} while (stage[i].field[x][y].stat.value == 0);
			stage[i].field[x][y].stat.value = 5;
		}
		////스테이지2 열쇠 위치가 벽이나 문 위치 일때 재지정
		//while (map[1][stage2_key_x][stage2_key_x] == 1 || map[1][stage2_key_x][stage2_key_y] == 2 || map[1][stage2_key_x][stage2_key_y] == 7) {
		//	stage2_key_x = rand() % 5 + 1;
		//	stage2_key_y = rand() % 5 + 1;
		//}
		//map[1][stage2_key_x][stage2_key_x] = 5;

		////스테이지 3 열쇠 위치가 벽이나 문 위치일때 재 지정
		//while (map[2][stage3_key_x][stage3_key_y] == 1 || map[2][stage3_key_x][stage3_key_y] == 2 || map[2][stage3_key_x][stage3_key_y] == 7) {
		//	stage3_key_x = rand() % 5 + 1;
		//	stage3_key_y = rand() % 5 + 1;
		//}
		//map[2][stage3_key_x][stage3_key_x] = 5;


		// 탈출구 배치
		for (int i = 0; i < 3; i++)
		{
			int x, y;
			do
			{
				x = (rand() % 2) + 8;
				y = (rand() % 2) + 8;
			} while (stage[i].field[x][y].stat.value == 0);
			stage[i].field[x][y].stat.value = 8;
		}

		////플레이어 좌표 설정
		//for (int i = 0; i < 3; i++) {
		//	map[i][player_xposition][player_yposition] = 9;
		//	//탈출구 좌표 랜덤으로 입력 받기
		//	escape_xposition[i] = rand() % 10;
		//	escape_yposition[i] = rand() % 10;
		//	//탈출구 좌표가 벽일때 또는 플레이어와 가까울 때 재지정
		//	while (map[i][escape_xposition[i]][escape_yposition[i]] == 1 || (escape_xposition[i] < 8 && escape_yposition[i] < 8)) {
		//		escape_xposition[i] = rand() % 10;
		//		escape_yposition[i] = rand() % 10;
		//	}
		//	//탈출구 좌표 설정
		//	map[i][escape_xposition[i]][escape_yposition[i]] = 8;
		//}




		while (inputEasy) { //이지모드

			// 초기화
			player.pos.x = 0;
			player.pos.y = 0;

			// 현재 스테이지의 플레이어 위치 입력



			for (stage_count; stage_count < 3;)
			{
				system("cls");

				stage[stage_count].field[player.pos.x][player.pos.y].stat.value = 9;

				//맵 출력하는 for문
				cout << "＃ : 문(열쇠로 열기) / ■,□ : 벽 / ♣ : 열쇠(지나가면 자동 습득) / Ｅ : 탈출구 / ● : 플레이어" << endl;
				cout << "현재 스테이지 : " << stage_count + 1 << endl;
				cout << "이동 횟수 : " << move_count << endl;
				(haveKey) ? cout << "열쇠 ○" << endl : cout << "열쇠 ×" << endl;

				cout << "\n■■■■■■■■■■■■\n";

				// 맵 그리기
				for (int x = 0; x < 10; x++)
				{
					cout << "■";
					for (int y = 0; y < 10; y++)
					{
						if (player.pos.x - 1 <= x && player.pos.x + 1 >= x && player.pos.y - 1 <= y && player.pos.y + 1 >= y)
						{
							switch (stage[stage_count].field[x][y].stat.value)
							{
							case 0: // 평지
								cout << "  ";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 1: // 벽
								cout << "■";
								stage[stage_count].field[x][y].isMove = false;
								break;
							case 2: // 벽 잔상
								cout << "□";
								stage[stage_count].field[x][y].isMove = false;
								break;
							case 3: // 숲
								cout << "  ";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 4: // 평지?
								cout << "  ";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 5: // 열쇠
								cout << "♣";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 6: // 늪
								cout << "  ";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 7: // 문
								cout << "＃";
								stage[stage_count].field[x][y].isMove = false;
								break;
							case 8: // 탈출구
								cout << "Ｅ";
								stage[stage_count].field[x][y].isMove = true;
								break;
							case 9: // 플레이어
								cout << "●";
								stage[stage_count].field[x][y].isMove = true;
								break;
							default:
								break;
							}
						}
						else 
						{
							cout << "  ";
						}
					}
					cout << "■";
					cout << endl;
				}
				cout << "■■■■■■■■■■■■\n\n";
				//for (x = 0; x < 10; x++) {
				//	cout << "■";
				//	for (y = 0; y < 10; y++) {

				//		if (map[stage_count][x][y] == 0 || map[stage_count][x][y] == 4) {
				//			cout << "  ";
				//		}
				//		else if (map[stage_count][x][y] == 8) {
				//			cout << "Ｅ";
				//		}
				//		else if (map[stage_count][x][y] == 9) {
				//			cout << "●";
				//		}
				//		else if (map[stage_count][x][y] == 2) {
				//			cout << "□";
				//		}
				//		else if (map[stage_count][x][y] == 1) {
				//			if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
				//			{
				//				cout << "■";
				//				map[stage_count][x][y] = 2;
				//			}
				//			else
				//			{
				//				cout << "  ";
				//			}
				//		}
				//		else if (map[stage_count][x][y] == 7) {
				//			if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
				//			{
				//				cout << "＃";
				//			}
				//			else
				//			{
				//				cout << "  ";
				//			}
				//		}
				//		else if (map[stage_count][x][y] == 5) {
				//			if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
				//			{
				//				cout << "♣";
				//			}
				//			else
				//			{
				//				cout << "  ";
				//			}
				//		}
				//	}
				//	cout << "■";
				//	cout << endl;
				//}

				

				//if (map[stage_count][player_xposition][player_yposition] == map[stage_count][escape_xposition[stage_count]][escape_yposition[stage_count]]) {
				//	stage_count++;
				//	total_move_count += move_count;
				//	move_count = 0;
				//	break;
				//}




				cout << "이동 => w : 위 / s : 아래 / a : 왼쪽 / b : 오른쪽" << endl;
				cout << "r : 현재 스테이지 재시작 / f : 전체 재시작 / e : 열쇠 사용" << endl;
				//탈출구 좌표랑 플레이어 좌표가 일치할때 프로그램 종료
				//키 입력 받아서 swtich문으로 이동
				input_move_key = _getch();
				if (input_move_key >= 65 && input_move_key <= 90) { //입력한게 대문자였을경우 소문자로 변환
					input_move_key += 32;
				}
				switch (input_move_key) {
				case 'w': //위쪽 이동
					if (player.pos.x > 0 && stage[stage_count].field[player.pos.x - 1][player.pos.y].isMove)
					{
						stage[stage_count].field[player.pos.x][player.pos.y].stat.value = 0;
						player.pos.x--;
						move_count++;
					}
					break;
				case 's': //아래쪽 이동
					if (player.pos.x < 9 && stage[stage_count].field[player.pos.x + 1][player.pos.y].isMove)
					{
						stage[stage_count].field[player.pos.x][player.pos.y].stat.value = 0;
						player.pos.x++;
						move_count++;
					}
					break;
				case 'a': //왼쪽 이동
					if (player.pos.y > 0 && stage[stage_count].field[player.pos.x][player.pos.y - 1].isMove)
					{
						stage[stage_count].field[player.pos.x][player.pos.y].stat.value = 0;
						player.pos.y--;
						move_count++;
					break;
				case 'd': //오른쪽 이동
					if (player.pos.y < 9 && stage[stage_count].field[player.pos.x][player.pos.y + 1].isMove)
					{
						stage[stage_count].field[player.pos.x][player.pos.y].stat.value = 0;
						player.pos.y++;
						move_count++;
					}
					}
					break;
					//	if (player_xposition != 0 && (map[stage_count][player_xposition - 1][player_yposition]) != 1 && (map[stage_count][player_xposition - 1][player_yposition]) != 2 && (map[stage_count][player_xposition - 1][player_yposition]) != 7) { //위쪽으로 이동할 수 없는 경우 무시
					//		if (map[stage_count][player_xposition - 1][player_yposition] == 5) 
					//		{
					//			haveKey = true;
					//		}
					//		map[stage_count][player_xposition][player_yposition] = 0;
					//		player_xposition--;
					//		move_count++;
					//	}
					//	break;
					//case 'a': //왼쪽 이동
					//	if (player_yposition != 0 && (map[stage_count][player_xposition][player_yposition - 1]) != 1 && (map[stage_count][player_xposition][player_yposition - 1]) != 2 && (map[stage_count][player_xposition][player_yposition - 1]) != 7) { //왼쪽으로 이동할 수 없는 경우 무시
					//		if (map[stage_count][player_xposition][player_yposition - 1] == 5) {
					//			haveKey = true;
					//		}
					//		map[stage_count][player_xposition][player_yposition] = 0;
					//		player_yposition--;
					//		move_count++;
					//	}
					//	break;
					//case 's': //아래쪽 이동
					//	if (player_xposition != 9 && (map[stage_count][player_xposition + 1][player_yposition]) != 1 && (map[stage_count][player_xposition + 1][player_yposition]) != 2 && (map[stage_count][player_xposition + 1][player_yposition]) != 7) { //아래로 이동할 수 없는 경우 무시
					//		if (map[stage_count][player_xposition + 1][player_yposition] == 5) {
					//			haveKey = true;
					//		}
					//		map[stage_count][player_xposition][player_yposition] = 0;
					//		player_xposition++;
					//		move_count++;
					//	}
					//	break;
					//case 'd': //오른쪽 이동
					//	if (player_yposition != 9 && (map[stage_count][player_xposition][player_yposition + 1]) != 1 && (map[stage_count][player_xposition][player_yposition + 1]) != 2 && (map[stage_count][player_xposition][player_yposition + 1]) != 7) { //오른쪽으로 이동할 수 없는 경우 무시
					//		if (map[stage_count][player_xposition][player_yposition + 1] == 5) {
					//			haveKey = true;
					//		}
					//		map[stage_count][player_xposition][player_yposition] = 0;
					//		player_yposition++;
					//		move_count++;
					//	}
					//	break;
				}

				// 키먹
				if (stage[stage_count].field[player.pos.x][player.pos.y].stat.value == 5)
				{
					haveKey = true;
				}

				if (stage[stage_count].field[player.pos.x][player.pos.y].stat.value == 5)
				{
					haveKey = true;
				}

				// 탈출지점 도착
				if (stage[stage_count].field[player.pos.x][player.pos.y].stat.value == 8)
				{
					stage_count++;
					total_move_count += move_count;
					move_count = 0;
					break;
				}

				if (input_move_key == 'e') { //열쇠 사용
					if (haveKey) {
						for (x = 0; x < 10; x++) {
							for (y = 0; y < 10; y++) {
								if (stage[stage_count].field[x][y].stat.value == 7
									&& player.pos.x - 1 <= x && player.pos.x + 1 >= x && player.pos.y - 1 <= y && player.pos.y + 1 >= y)
								{
									stage[stage_count].field[x][y].stat.value = 0;
									haveKey = false;
								}
							}
						}
					}
				}

				if (input_move_key == 'r')
				{
					move_count = 0;
					break;
				}

				if (input_move_key == 'r')
				{
					move_count = 0;
					total_move_count = 0;
					stage_count = 0;
					break;
				}
				//if (input_move_key == 'r') { //스테이지 재시작
				//	if (stage_count == 1) {
				//		map[1][stage2_key_x][stage2_key_y] = 5;
				//	}
				//	else if (stage_count == 2) {
				//		map[2][stage3_key_x][stage3_key_y] = 5;
				//	}
				//	map[stage_count][player_xposition][player_yposition] = 0;
				//	for (int v = 0; v < 3; v++) {
				//		for (int w = 0; w < 10; w++) {
				//			for (int z = 0; z < 10; z++) {
				//				if (map[v][w][z] == 2) {
				//					map[v][w][z] = 1;
				//				}
				//			}
				//		}
				//	}
				//	if (stage_count == 1) {
				//		map[stage_count][stage2_door1.pos.x][stage2_door1.pos.y] = 7;
				//		map[stage_count][stage2_door2.pos.x][stage2_door2.pos.y] = 7;
				//	}
				//	if (stage_count == 2) {
				//		map[stage_count][stage3_door1.pos.x][stage3_door1.pos.y] = 7;
				//		map[stage_count][stage3_door2.pos.x][stage3_door2.pos.y] = 7;
				//		map[stage_count][stage3_door3.pos.x][stage3_door3.pos.y] = 7;
				//	}
				//	move_count = 0;
				//	haveKey = false;
				//	break;
				//}

				//if (input_move_key == 'f') { //전체 재시작
				//	for (int v = 0; v < 3; v++) {
				//		for (int w = 0; w < 10; w++) {
				//			for (int z = 0; z < 10; z++) {
				//				if (map[v][w][z] == 2) {
				//					map[v][w][z] = 1;
				//				}
				//			}
				//		}
				//	}
				//	map[1][stage2_key_x][stage2_key_y] = 5;
				//	map[2][stage3_key_x][stage3_key_y] = 5;
				//	map[stage_count][player_xposition][player_yposition] = 0;
				//	stage_count = 0;
				//	player_xposition = 0; //전체 재시작 할때 모든 스테이지 전부 좌표 재지정
				//	player_yposition = 0;
				//	for (int i = stage_count; i < 3; i++) {
				//		map[i][player_xposition][player_yposition] = 9;
				//		map[i][escape_xposition[i]][escape_yposition[i]] = 8;
				//		move_count = 0;
				//		total_move_count = 0;
				//	}
				//	map[1][stage2_door1.pos.x][stage2_door1.pos.y] = 7;
				//	map[1][stage2_door2.pos.x][stage2_door2.pos.y] = 7;
				//	map[2][stage3_door1.pos.x][stage3_door1.pos.y] = 7;
				//	map[2][stage3_door2.pos.x][stage3_door2.pos.y] = 7;
				//	map[2][stage3_door3.pos.x][stage3_door3.pos.y] = 7;
				//	haveKey = false;
				//	break;
				//}
				//map[stage_count][player_xposition][player_yposition] = 9;

			}
			if (stage_count == 3) {
				system("cls");
				cout << endl;
				cout << "            ■    ■    ■■    ■    ■  ■■■" << endl;
				cout << "             ■  ■   ■    ■  ■    ■  ■    ■" << endl;
				cout << "               ■     ■    ■  ■    ■  ■■■" << endl;
				cout << "               ■     ■    ■  ■    ■  ■  ■" << endl;
				cout << "               ■       ■■      ■■    ■    ■" << endl;
				cout << endl;
				cout << "  ■■■■    ■■■    ■■■    ■■    ■■■    ■■■■" << endl;
				cout << "  ■        ■        ■        ■    ■  ■    ■  ■" << endl;
				cout << "  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■" << endl;
				cout << "  ■              ■  ■        ■    ■  ■        ■" << endl;
				cout << "  ■■■■  ■■■      ■■■  ■    ■  ■        ■■■■" << endl;
				cout << endl;
				cout << "    ■■■  ■        ■■■■    ■■    ■■■    ■  ■" << endl;
				cout << "  ■        ■        ■        ■    ■  ■    ■  ■  ■" << endl;
				cout << "  ■        ■        ■■■■  ■■■■  ■■■    ■  ■" << endl;
				cout << "  ■        ■        ■        ■    ■  ■  ■          " << endl;
				cout << "    ■■■  ■■■■  ■■■■  ■    ■  ■    ■  ■  ■" << endl << endl;
				cout << "          모든 스테이지 탈출에 성공하셨습니다." << endl;
				cout << "            총 " << total_move_count << "회만에 탈출에 성공했습니다." << endl;
				break;
			}
		}
	}


	//while (!inputEasy) { //하드모드
	//	player_xposition = 0;
	//	player_yposition = 0;
	//	for (int i = stage_count; i < 3; i++) {
	//		map[i][player_xposition][player_yposition] = 9;
	//	}
	//	for (stage_count; stage_count < 3;) {
	//		system("cls");
	//		//맵 출력하는 for문
	//		cout << "＃ : 문(열쇠로 열기) / ■,□ : 벽 / ♣ : 열쇠(지나가면 자동 습득) / Ｅ : 탈출구 / ● : 플레이어" << endl;
	//		cout << "현재 스테이지 : " << stage_count + 1 << endl;
	//		cout << "이동 횟수 : " << move_count << endl;
	//		(haveKey) ? cout << "열쇠 ○" << endl : cout << "열쇠 ×" << endl;

	//		cout << "\n■■■■■■■■■■■■\n";
	//		for (x = 0; x < 10; x++) {
	//			cout << "■";
	//			for (y = 0; y < 10; y++) {

	//				if (map[stage_count][x][y] == 0 || map[stage_count][x][y] == 4) {
	//					cout << "  ";
	//				}
	//				else if (map[stage_count][x][y] == 8) {
	//					cout << "Ｅ";
	//				}
	//				else if (map[stage_count][x][y] == 9) {
	//					cout << "●";
	//				}
	//				else if (map[stage_count][x][y] == 1) {
	//					if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
	//					{
	//						cout << "■";
	//					}
	//					else
	//					{
	//						cout << "  ";
	//					}
	//				}
	//				else if (map[stage_count][x][y] == 7) {
	//					if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
	//					{
	//						cout << "＃";
	//					}
	//					else
	//					{
	//						cout << "  ";
	//					}
	//				}
	//				else if (map[stage_count][x][y] == 5) {
	//					if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
	//					{
	//						cout << "♣";
	//					}
	//					else
	//					{
	//						cout << "  ";
	//					}
	//				}
	//			}
	//			cout << "■";
	//			cout << endl;
	//		}
	//		cout << "■■■■■■■■■■■■\n\n";

	//		if (map[stage_count][player_xposition][player_yposition] == map[stage_count][escape_xposition[stage_count]][escape_yposition[stage_count]]) {
	//			stage_count++;
	//			total_move_count += move_count;
	//			move_count = 0;
	//			break;
	//		}
	//		cout << "이동 => w : 위 / s : 아래 / a : 왼쪽 / b : 오른쪽" << endl;
	//		cout << "r : 현재 스테이지 재시작 / f : 전체 재시작 / e : 열쇠 사용" << endl;
	//		//탈출구 좌표랑 플레이어 좌표가 일치할때 프로그램 종료
	//		//키 입력 받아서 swtich문으로 이동
	//		input_move_key = _getch();
	//		if (input_move_key >= 65 && input_move_key <= 90) { //입력한게 대문자였을경우 소문자로 변환
	//			input_move_key += 32;
	//		}
	//		switch (input_move_key) {
	//		case 'w': //위쪽 이동
	//			if (player_xposition != 0 && (map[stage_count][player_xposition - 1][player_yposition]) != 1 && (map[stage_count][player_xposition - 1][player_yposition]) != 7) { //배열에서[0][]일경우 위쪽으로 이동할 수 없어야함
	//				if (map[stage_count][player_xposition - 1][player_yposition] == 5) {
	//					haveKey = true;
	//				}
	//				map[stage_count][player_xposition][player_yposition] = 0;
	//				player_xposition--;
	//				move_count++;
	//			}
	//			break;
	//		case 'a': //왼쪽 이동
	//			if (player_yposition != 0 && (map[stage_count][player_xposition][player_yposition - 1]) != 1 && (map[stage_count][player_xposition][player_yposition - 1]) != 7) { //배열에서 [][0]일경우 왼쪽으로 이동 할 수 없어야함
	//				if (map[stage_count][player_xposition][player_yposition - 1] == 5) {
	//					haveKey = true;
	//				}
	//				map[stage_count][player_xposition][player_yposition] = 0;
	//				player_yposition--;
	//				move_count++;
	//			}
	//			break;
	//		case 's': //아래쪽 이동
	//			if (player_xposition != 9 && (map[stage_count][player_xposition + 1][player_yposition]) != 1 && (map[stage_count][player_xposition + 1][player_yposition]) != 7) { //배열에서 [10][]일경우 아래쪽으로 이동 할 수 없어야함
	//				if (map[stage_count][player_xposition + 1][player_yposition] == 5) {
	//					haveKey = true;
	//				}
	//				map[stage_count][player_xposition][player_yposition] = 0;
	//				player_xposition++;
	//				move_count++;
	//			}
	//			break;
	//		case 'd': //오른쪽 이동
	//			if (player_yposition != 9 && (map[stage_count][player_xposition][player_yposition + 1]) != 1 && (map[stage_count][player_xposition][player_yposition + 1]) != 7) { //배열에서 [][10]일경우 오른쪽으로 이동 할 수 없어야함
	//				if (map[stage_count][player_xposition][player_yposition + 1] == 5) {
	//					haveKey = true;
	//				}
	//				map[stage_count][player_xposition][player_yposition] = 0;
	//				player_yposition++;
	//				move_count++;
	//			}
	//			break;
	//		}
	//		if (input_move_key == 'e') { //열쇠 사용
	//			if (haveKey) {
	//				for (x = 0; x < 10; x++) {
	//					for (y = 0; y < 10; y++) {
	//						if (map[stage_count][x][y] == 7) {
	//							if (player_xposition - 1 <= x && player_xposition + 1 >= x && player_yposition - 1 <= y && player_yposition + 1 >= y)
	//							{
	//								cout << "  ";
	//								map[stage_count][x][y] = 4;

	//							}
	//						}
	//					}
	//					haveKey = false;
	//				}
	//			}
	//		}
	//		if (input_move_key == 'r') { //스테이지 재시작

	//			if (stage_count == 1) {
	//				map[1][stage2_key_x][stage2_key_y] = 5;
	//			}
	//			else if (stage_count == 2) {
	//				map[2][stage3_key_x][stage3_key_y] = 5;
	//			}
	//			map[stage_count][player_xposition][player_yposition] = 0;
	//			move_count = 0;
	//			if (stage_count == 1) {
	//				map[1][stage2_door1.pos.x][stage2_door1.pos.y] = 7;
	//				map[1][stage2_door2.pos.x][stage2_door2.pos.y] = 7;
	//			}
	//			if (stage_count == 2) {
	//				map[2][stage3_door1.pos.x][stage3_door1.pos.y] = 7;
	//				map[2][stage3_door2.pos.x][stage3_door2.pos.y] = 7;
	//				map[2][stage3_door3.pos.x][stage3_door3.pos.y] = 7;
	//			}
	//			haveKey = false;
	//			break;
	//		}
	//		if (input_move_key == 'f') { //전체 재시작

	//			map[1][stage2_key_x][stage2_key_y] = 5;
	//			map[2][stage3_key_x][stage3_key_y] = 5;
	//			map[stage_count][player_xposition][player_yposition] = 0;
	//			stage_count = 0;
	//			player_xposition = 0; //전체 재시작 할때 모든 스테이지 전부 좌표 재지정
	//			player_yposition = 0;
	//			map[1][stage2_door1.pos.x][stage2_door1.pos.y] = 7;
	//			map[1][stage2_door2.pos.x][stage2_door2.pos.y] = 7;
	//			map[2][stage3_door1.pos.x][stage3_door1.pos.y] = 7;
	//			map[2][stage3_door2.pos.x][stage3_door2.pos.y] = 7;
	//			map[2][stage3_door3.pos.x][stage3_door3.pos.y] = 7;
	//			for (int i = stage_count; i < 3; i++) {
	//				map[i][player_xposition][player_yposition] = 9;
	//				map[i][escape_xposition[i]][escape_yposition[i]] = 8;
	//				move_count = 0;
	//				total_move_count = 0;
	//			}
	//			haveKey = false;
	//			break;
	//		}
	//		map[stage_count][player_xposition][player_yposition] = 9;
	//	}
	//	if (stage_count == 3) {
	//		system("cls");
	//		cout << endl;
	//		cout << "            ■    ■    ■■    ■    ■  ■■■" << endl;
	//		cout << "             ■  ■   ■    ■  ■    ■  ■    ■" << endl;
	//		cout << "               ■     ■    ■  ■    ■  ■■■" << endl;
	//		cout << "               ■     ■    ■  ■    ■  ■  ■" << endl;
	//		cout << "               ■       ■■      ■■    ■    ■" << endl;
	//		cout << endl;
	//		cout << "  ■■■■    ■■■    ■■■    ■■    ■■■    ■■■■" << endl;
	//		cout << "  ■        ■        ■        ■    ■  ■    ■  ■" << endl;
	//		cout << "  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■" << endl;
	//		cout << "  ■              ■  ■        ■    ■  ■        ■" << endl;
	//		cout << "  ■■■■  ■■■      ■■■  ■    ■  ■        ■■■■" << endl;
	//		cout << endl;
	//		cout << "    ■■■  ■        ■■■■    ■■    ■■■    ■  ■" << endl;
	//		cout << "  ■        ■        ■        ■    ■  ■    ■  ■  ■" << endl;
	//		cout << "  ■        ■        ■■■■  ■■■■  ■■■    ■  ■" << endl;
	//		cout << "  ■        ■        ■        ■    ■  ■  ■          " << endl;
	//		cout << "    ■■■  ■■■■  ■■■■  ■    ■  ■    ■  ■  ■" << endl << endl;
	//		cout << "          모든 스테이지 탈출에 성공하셨습니다." << endl;
	//		cout << "            총 " << total_move_count << "회만에 탈출에 성공했습니다." << endl;
	//		break;
	//	}
	//}
}