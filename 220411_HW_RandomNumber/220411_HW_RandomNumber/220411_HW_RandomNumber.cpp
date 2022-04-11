
/*
    [220411] 난수 실습!

    실습0. rand()의 크기는 몇 byte인가요? 
    실습1. 3~7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자. (3,7포함)
    실습2. 가장 작은 값과 큰 값을 입력 받아서 그 사이의 임의의 값을 출력하는 프로그램을 작성하자.
    실습3. 프로그램을 실행하면 내부적으로 1~9 사이의 숫자가 정답으로 정해진다.
           유저가 1~9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false를 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    
    // 실습 0
    cout << "[실습 0]" << endl;

    cout << "rand()의 크기 : " << sizeof(rand()) << endl;
    cout << endl;

    // 실습 1
    cout << "[실습 1]" << endl;
    
    cout << "답 : " << rand() % 5 + 3 << endl;
    cout << endl;


    // 실습 2
    cout << "[실습 2]" << endl;

    int value1; // 첫번째 값
    int value2; // 두번째 값

    cout << "첫번째 값을 입력해 주세요 : ";
    cin >> value1;
    cout << "두번째 값을 입력해 주세요 : ";
    cin >> value2;

    (value2 <= value1) ? // 최소, 최대 값이 
        cout << "답 : " << rand() % (value1 - value2 + 1) + value2 << endl :
        cout << "답 : " << rand() % (value2 - value1 + 1) + value1 << endl;

    cout << endl;


    // 실습 3
    cout << "[실습 3]" << endl;
    int correctAnswer = rand() % 9 + 1;

    int yourAnswer;
    cout << "1~9 사이의 값을 입력해 주세요 : ";
    cin >> yourAnswer;
    (1 <= yourAnswer && yourAnswer <= 9) ? // 정확한 수를 입력 했는가?
        ((correctAnswer == yourAnswer) ?   // 선택한 값이 랜덤한 숫자와 같은가?
            cout << "정답입니다!!" << endl :
            cout << "당신은 틀렸습니다. 정답은 " << correctAnswer << "입니다." << endl) :
        cout << "범위를 벗어난 수를 입력하였습니다." << endl;

}
