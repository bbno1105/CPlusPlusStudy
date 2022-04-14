#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{

	/*

			**********
			**********
			**********
			**********
			**********
			**********
			**********
			**********
			**********
			**********


			1. 플레이어를 만들어준다.
			2. 맵을 만들어준다.
			3. 위치를 랜덤으로 지정한다.
			3. 사용자 키를 입력하여 움직일 수 있게 한다.
			4. system(cls);


	 
	*/

	// 움직이는 좌표 지정

	srand(time(NULL));
	int map[20][20] = { 0, };
	int player_x = 0;
	int player_y = 0;
	//int escape_x = 0;
	//int escape_y = 0;
    int input_key = 0;


	// 랜덤으로 플레이어 위치 10x10 에 생성

	//int player_x = rand() % 10;
	//int player_y = rand() % 10;


	// 랜덤으로 10x10 위치에 생성
	int escape_x = rand() % 10;
	int escape_y = rand() % 10; 
	
	// 탈출구가 0,0 제외, 1,0 또는 0,1 도 가능해야 한다. 
	

	// 가짜 탈출구

	int fake_x = rand() % 10;
	int fake_y = rand() % 10;

	while (escape_x == 0 && escape_y == 0)
	{
			escape_x = rand() % 10 ;
			escape_y = rand() % 10 ;
	}
	
	while (fake_x == 0 && fake_y == 0)
	{
		fake_y = rand() % 10;
		fake_x = rand() % 10;
	}

	while (true)
	{
		system("cls");

		// 플레이어 제어, 도착지 설정, 맵 설정
	
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == player_x && j == player_y)
					cout << "●";

				else if (i == escape_x && j == escape_y)
					cout << "◎";
				
				else if (i == fake_x && j == fake_y)
					cout << "◎";

				else
					cout << "○";
			}
			cout << endl;


		}
		


		

		// 키 지정

		switch (_getch())
		{
		case 119: //w
			if (player_x > 0 )
			{
				player_x -= 1;
			}
			break;
		case 115: //s
			if (player_x < 9)
			{
				player_x += 1;
			}
			break;
		case 100: //d
			if (player_y < 9)
			{
				player_y += 1;
			}
			break;
		case 97: //a
			if (player_y > 0)
			{
				player_y -= 1;
			}
			break;
		default:
			break;
		}

		if ((player_x == escape_x) && (player_y == escape_y))
		{
			system("cls");
			cout << endl;
			cout << " #####  #      #####    ##    ####   " << endl;
			cout << " #      #      #       #  ##  #   #  " << endl;
			cout << " #      #      #####  #    #  ####   " << endl;
			cout << " #      #      #      ######  #   #  " << endl;
			cout << " #####  #####  #####  #    #  #   #  " << endl;
			break;

		}

		else if ((player_x == fake_x) && (player_y == fake_y))
		{
			system("cls");
			cout << " #####    ##    #   ##  #####   #  " << endl;
			cout << " #       #  #   # ##    #       #  " << endl;
			cout << " #####  #    #  ##      #####   #  " << endl;
			cout << " #      ######  # ##    #          " << endl;
			cout << " #      #    #  #   ##  #####   #  " << endl;
			break;
		}


		
		

		
	
		
	}

}

