#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
	//아스키 코드: A = 65, Z = 90, a = 97, z = 122

	char correct;
	char input_key;

	//랜덤시간
	srand(time(NULL));

	correct = rand() % 26 + 65;

	cout << " 알파뱃을 골라주세요. " << endl;

	// for 반복

	for (int i = 0; i < 5; i++)
	{
		input_key = _getch();

		cout << correct << endl;

		if (input_key >= 97 && input_key <= 122) 
		{
			input_key -= 32; // 왜 32인지 모르겠다...
		}

		if (input_key == correct)
		{
			cout << " 정답입니다! " << endl;
			break;
		}
		
		else if (i < 4)
		{
			cout << " 틀렸습니다. 남은 기회는 " << 4 - i << " 번 남았습니다. " << endl;
			input_key > correct ? cout << " A 쪽으로 " << endl : cout << " Z 쪽으로 " << endl; 
		}
		else
		{
			cout << "정답은 " << (char)correct << " 였습니다.... " << endl;
		}
	}

}
