// 220411_Review.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//  [ C++ 문법 ]
  
    //(주석) : 실행(컴파일) 되지 않고 설명만을 위해 사용되는 문법
    /*
        1. 여러 줄
        2. 주석
        3. 처리
    */
/*
    [ C++ 문법을 사용할 때 주의해야 할 점 ]
    
    1. 대/소문자를 구분해야 한다
    ▶ main / Main / mAIN / maIN

    2. 띄어쓰기를 통해 요소를 구분한다
    ▶ #include(요소) <iostream>(요소) 

    3. 실행문의 마무리는 세미콜론(;)으로 한다.
    ▶ int input_key;
*/

/*
    =====================================[ 변  수 ]=====================================
    
    데이터를 저장할 메모리공간을 할당 받는다.
    ▶ int(데이터타입) input_key(변수명);
    ▶ int(데이터타입) key(변수명) =(대입연산자) 10(값);


    [ 데이터 타입 ]

    1. 정수형 (0, 1, 2, ... , -1, -2, ... )
       int
       short
       long
       long long
       __int8, __int16, __int32, __int64, ...

    2. 실수형 (1.01, 1.02, ... )
       float
       double
       long double

    3. 문자형
       char

    4. 문자열
       string


    [ 변수명 이름 짓기 규칙 (표기법) ]

    1. 헝가리안 표기법
    - 데이터 타입의 약자를 접두어로 붙인다.
    int nMaxCount = 10;

    2. 카멜 표기법
    - 첫 단어를 제외한 단어의 접두어를 대문자로 한다.
    int maxCount = 10;

    3. 파스칼 표기법
    - 모든 단어의 접두어를 대문자로 한다.
    int MaxCount = 10;

    4.
    int token_max_count = 10;

    * 변수명으로 사용하면 혼나요 (변수명만으로 데이터를 확인하기 어려움)
    int nn = 10; (x)
    int cmprs = 10; (x) 


    < 문법적 규칙 >
    1. 대/소문자를 구분한다
    2. 알파벳, 숫자, _(언더바)만 사용한다.
      2.1 숫자는 가장 앞에 올 수 없다.


    [ 변수의 4가지 속성 ]
    1) 이름 : input_key  
    2) 크기 : 4byte  
    3) 값 : 10    
    4) 메모리 주소 : ?? (설정은 되어 있는데 아직 모름)
       * &input_key 를 출력하면 메모리 주소를 알 수 있다.
       * 00000006381BF8A4 : 메모리 주소는 0~F로 되어 있는 16진수의 16자리로 구성되어 있음

    ====================================================================================
*/

/*
    =====================================[ 연산자 ]=====================================

    데이터를 가공(연산)하는 모든 명령어에 필요한 것들
    1) 어떤 종류의 연산자인가?
    2) 우선순위 : 어떤 순서로 연산이 되는가?
    3) 결합순서 : 좌측부터 연산하는가, 우측부터 연산하는가?

    1. 사칙연산 (좌측부터 연산된다)
    + : 더하기
    - : 빼기
    * : 곱하기
    / : 나누기     11 / 3 → 3 (몫)
    % : 나머지     11 % 3 → 2 (나머지)

    계산 우선순위 : (*, /, %) > (+, -)

    2. 대입 연산자 (우측부터 연산된다)
    = : 왼쪽 항에 오른쪽 항의 값을 대입(복사)한다.
    a = b + c; -> a = (b + c);

    3. 복합대입 연산자
    += : a += b;     → a = (a + b);
    -= : a -= b;     → a = (a - b);
    *= : a *= b;     → a = (a * b);
    /= : a /= b;     → a = (a / b); (b == 0; run time error)
    %= : a %= b;     → a = (a % b); (데이터타입이 정수형이 아닐 때)

    4. 증감 연산자
    - 특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용하는 연산자

    5. 관계 연산자
    - 두 항의 값을 비교한 결과가 참이면 true(1), 거짓이면 false(0)를 출력
    
    a < b
    a > b
    a <= b
    a >= b
    a == b
    a != b

    * boolalpha : 0(flase), 1(true)를 문자로 표기 ( != noboolalpha : 표기 끄기 )


    6. 논리 연산자
    왼쪽 항과 오른쪽 항의 값을 각각 참과 거짓으로 연산해서 두 값을 비교해서 참과 거직을 반환하는 연산자

    && : 논리곱 (AND)
         a && b : a의 결과 값이 참이고 b의 결과 값이 참일 경우 1(true)를 반환한다.

    || : 논리합 (OR)
         a || b : a의 결과 값이 참이거나 b의 결과 값이 참일 경우 1(true)를 반환한다.

    ! : 논리부정 (NOT)
    !a : a의 결과 값이 참이면 거짓을 반환, 거짓이면 참을 반환

    
    7. 삼항연산자
    a ? b : c;
    a의 결과 값이 참이면 b실행문이 동작, 거짓이면 c실행문이 동작

    ====================================================================================
*/

/*
    =====================================[ 난  수 ]=====================================

    난수 (랜덤값)
    
    rand(); // 0 ~ 32767 사이의 랜덤한 값이 반환된다.
    함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 정해진다.
    기본적으로 seed : 1로 세팅되어 있다.

    srand(time(NULL)); // 실행된 시간값을 시드로 랜덤값 가져옴 (완전한 랜덤은 아님)

*/

/*
    실습1. 3~7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자. (3,7포함) 
    실습2. 가장 작은 값과 큰 값을 입력 받아서 그 사이의 임의의 값을 출력하는 프로그램을 작성하자.
    실습3. 프로그램을 실행하면 내부적으로 1~9 사이의 숫자가 정답으로 정해진다.
           유저가 1~9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false를 출력한다.

    ====================================================================================
*/

/*
    =====================================[ 제어문 ]=====================================

    <제어구조>
    
    1. 조건문 : 특정 조건에 따라서 실행문을 실행할지 안 할지 제어 : if / switch
    2. 반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행 제어 : for / while

    [ 조건문 ]

    1_1. if 문
    
    if (조건식)
    {
        실행문1; // 참일 경우
    }
    else if (조건식2)
    {
        실행문3; // 조건식 거짓, 조건식2 참인 경우
    }
    else
    {
        실행문2; // 거짓일 경우
    }

    // 실습1. 
    정수를 하나 입력 받아서
    입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다." 출력
    10 이하 9 초과 이면 "9보다 크빈다." 출력
    9이 이하 6 초과 이면 "6보다 큽니다."
    그 이외에는 "6보다 작거나 같습니다."

    
    1_2. switch 문

    switch (정수형 변수)
    {
        case 정수1:
            실행문1;
        break;

        case 정수2:
            실행문2;
        break;

        default:
            실행문3; // 해당하는 정수값이 없을 때
        break;
    }

    // 실습1.
    당신의 고향은 어디입니까?
    1. 서울 2. 양평 3. 광주 4. 대전 5. 제주도
    _입력을 받음

    안녕하세요. 당신의 고향은 서울이군요.



    [ 반복문 ]

    2_1. while

    while (조건식)
    {
        실행문; // 조건식이 참일 경우 반복해서 실행
        조건식을 바꾸는 실행문; // while문을 중단시키는 첫번째 방법

        if (조건식)
        {
            break; // while문을 중단시키는 두번째 방법
        }
    }

    do-while
    do // 최초 1회 실행은 무조건
    {
        실행문;
     }
    while (조건식); // 조건식을 판단하고 do를 다시 실행할지 판단


    2_2. for

    for ( (1)초기식; (2)조건식; (3)증감식)
    {
        (4)실행문;
    }
    
    진행 순서 : (1) -> (2) -> (4) -> (3) -> (2) -> (4) -> (3) -> 반복



    ====================================================================================
*/

#include <iostream> // iostream의 라이브러리를 쓰겠다!
#include <string>

using namespace std;



int main()
{
    srand(time(NULL));

#pragma region for문실습

    // 10부터 1까지 차례대로 출력되는 코드를 작성해 보자 10 9 8 7
    for (int i = 10; i > 0; i--)
    {
        cout << "1~10 : " << i << endl;
    }

    // 100미만의 3의 배수를 차례대로 출력되는 코드를 작성해 보자 3 6 9 12
    for (int i = 1; 3 * i < 100; i++)
    {
        cout << "3의 배수 : " << 3 * i << endl;
    }
    // 이런 방법도 있다.
    //for (int i = 3; i < 100; i += 3)
    //{
    //    cout << "3의 배수 : " << i << endl;
    //}

    // 1000미만의 2의 승수를 차례대로 출력되는 코드를 작성해보자. 1 2 4 8 16
    // pow(2,i)
    for (int i = 0; pow(2,i) < 1000; i++)
    {
        cout << "2의 승수 : " << pow(2, i) << endl;
    }
    // pow()를 사용하지 않아도 이렇게 간단하게도 할 수 있다.
    // for (int i = 1; i < 1000; i *=2)
    // {
    //     cout << "2의 승수 : " << i << endl;
    // }

    // [실습4] 구구단을 출력해 보자
    cout << "\n[실습 4-1]" << endl;
    for (int i = 1; i < 10; i++)
    {
        cout << 2 << " * " << i << " = " << (2 * i) << endl;
    }

    cout << "\n[실습 4-2]" << endl;
    for (int i = 2; i < 10; i++)
    {
        cout << i << "단" << endl;
        for (int j = 1; j < 10; j++)
        {
            cout << i << " * " << j << " = " << (i*j) << endl;
        }
        cout << endl;
    }

    cout << "\n[실습 4-3]" << endl;
    for (int i = 2; i < 10; i += 3) // i : 단
    {
        for (int j = 0; j < 10; j++) // j : 곱하는 값
        {
            // 그려주는 곳
            for (int k = 0; k < 3; k++) // k : 한 줄에 3개씩 그려야 하니까 묶어줄게
            {
                if (j == 0 && (i + k) < 10) // 0줄이면 단을 써줄거야!! 근데 10단은 없어~
                {
                    cout << "[ " << i + k << " 단 ]\t";
                }
                else // 0줄이 아닐때만 들어와라 
                {
                    if (i + k < 10) // 10단을 넘지 않도록 
                    {
                        printf("%d * %d = %2d\t", i + k, j, (i + k) * j);
                        
                        // 이렇게 해도 됩니다.
                        // cout << i + k << " * " << j << " = " << ((i+k) * j) << "\t";
                    }
                }
            }
            cout << endl; // 다음 줄로
        }
        cout << endl; // i + k 단을 다 그리고 다음 줄로
    }

    /*
    2단 3단 4단
    5단 6단 7단
    8단 9단
    */

#pragma endregion

#pragma region while문실습2
    int correctQuizAnswer = rand() % 9 + 1;
    // 난수실습 3을 while문을 사용하여 정답을 맞출 때 까지 반복되는 프로그램으로 수정하기
    int yourQuizAnswer;
    cout << "미리보는 정답 : " << correctQuizAnswer << endl;

    while (true)
    {
        cout << "1~9 사이의 값을 입력해 주세요 : ";
        cin >> yourQuizAnswer;

        if (correctQuizAnswer == yourQuizAnswer)
        {
            cout << "정답입니다!!" << endl;
            break;
        }
        else if (yourQuizAnswer < 1 || yourQuizAnswer > 9)
        {
            cout << "범위를 벗어난 수를 입력하였습니다. 다시 입력해 주세요." << endl;
        }
        else
        {
            cout << "당신은 틀렸습니다. 다시 도전해 보세요. " << endl;
        }
    }

    int correctQuizAnswer2 = rand() % 9 + 1;
    cout << "미리보는 정답2 : " << correctQuizAnswer2 << endl;

    int yourQuizAnswer2 = -1; // 초기식

    while (yourQuizAnswer2 != correctQuizAnswer2)
    {
        cout << "1~9 사이의 값을 입력해 주세요2 : ";
        cin >> yourQuizAnswer2;

        if (correctQuizAnswer2 == yourQuizAnswer2)
        {
            cout << "정답입니다!!" << endl;
        }
        else if (yourQuizAnswer2 < 1 || yourQuizAnswer2 > 9)
        {
            cout << "범위를 벗어난 수를 입력하였습니다. 다시 입력해 주세요." << endl;
        }
        else
        {
            cout << "당신은 틀렸습니다. 다시 도전해 보세요. " << endl;
        }
    }
    

#pragma endregion

#pragma region while문실습
    // while 1
    int count;
    cin >> count;

    while (count > 0)
    {
        cout << "HelloWorld" << endl;
        count--;

    }

    // while 2
    int count2;
    cin >> count2;
    while (true)
    {
        cout << "HelloWorld if" << endl;
        count2--;

        if(count2 <= 0)
        {
            break;
        }
    }

    // do_while
    int count3;
    cin >> count3;
    do
    {
        cout << "HelloWorld do_while" << endl;
        count3--;

    } while (count3 > 0);
#pragma endregion

#pragma region switch문실습
    int selectNumber;

    cout << "당신의 고향은 어디입니까?\n 1.서울 2.양평 3.광주 4.대전 5.제주도" << endl;
    cin >> selectNumber;

    switch (selectNumber) 
    {
        case 1: // 서울
            cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
            break;

        case 2: // 양평
            cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
            break;

        case 3: // 광주
            cout << "안녕하셨지라. 당신의 고향은 광주이군요." << endl;
            break;

        case 4: // 대전
            cout << "안녕하세유. 당신의 고향은 대전이군요." << endl;
            break;

        case 5: // 제주도
            cout << "안녕하수꽝. 당신의 고향은 제주도이군요." << endl;
            break;

        default:
            cout << "5개 중에 선택해 주세요." << endl;
            break;
    }

    // switch문 -> if문 으로 표현하기
    if (selectNumber == 1) // 서울
    {
        cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
    }
    else if (selectNumber == 2) // 양평
    {
        cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
    }
    else if (selectNumber == 3) // 광주
    {
        cout << "안녕하셨지라. 당신의 고향은 광주이군요." << endl;
    }
    else if (selectNumber == 4) // 대전
    {
        cout << "안녕하세유. 당신의 고향은 대전이군요." << endl;
    }
    else if (selectNumber == 5) // 제주도
    {
        cout << "안녕하수꽝. 당신의 고향은 제주도이군요." << endl;
    }
    else
    {
        cout << "5개 중에 선택해 주세요." << endl;
    }
    cout << endl;
#pragma endregion

#pragma region if문실습
    int inputNumber;

    cout << "아무 값이나 입력해 주세요 : " << endl;
    cin >> inputNumber;

    if (inputNumber > 10) 
    {
        cout << "입력된 숫자가 10보다 큽니다." << endl;
    }
    else if (inputNumber > 9) 
    {
        cout << "9보다 큽니다." << endl;
    }
    else if (inputNumber > 6)
    {
        cout << "6보다 큽니다." << endl;
    }
    else
    {
        cout << "6보다 작거나 같습니다" << endl << endl;
    }
#pragma endregion
    
#pragma region 난수실습0
    // 실습 0
    //출력
    cout << "rand()의 크기 : " << sizeof(rand()) << endl;
    cout << endl;
#pragma endregion

#pragma region 난수실습1
    // 실습 1
    //출력
    cout << "[실습 1]" << endl;
    cout << "답 : " << rand() % 5 + 3 << endl;
    cout << endl;
#pragma endregion

#pragma region 난수실습2
    // 실습 2
    cout << "[실습 2]" << endl;
    
    int value1; // 첫번째 값
    int value2; // 두번째 값

    //입력
    cout << "첫번째 값을 입력해 주세요 : ";
    cin >> value1;
    cout << "두번째 값을 입력해 주세요 : ";
    cin >> value2;
    
    //출력
    (value2 <= value1) ? // 최소, 최대 값이 
        cout << "답 : " << rand() % (value1 - value2 + 1) + value2 << endl :
        cout << "답 : " << rand() % (value2 - value1 + 1) + value1 << endl;

    cout << endl;
#pragma endregion

#pragma region 난수실습3
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
#pragma endregion



    // srand(time(NULL));

    cout << rand() << endl;  // 41이 나옴


    (10 < 5) ? std::cout << "10이 5보다 크다." : std::cout << "10이 5보다 작다." << std::endl;
    std::cout << !- 300 << std::endl;

    int input_key = 10;
    float testFloat = 5.3f;
    float testFloat2 = 5.3;
    char testCharacter = 'a';
    std::string testString = "Hello";

    std::cout << "Hello World!\n";
    // std::cin >> input_key;

    std::cout << "input_key의 메모리 주소 : " << &input_key << std::endl;
    std::cout << "int_key++ : " << input_key++ << std::endl; // 10 : 출력 후 1을 증가시킴 -> 11
    std::cout << "++int_key : " << ++input_key << std::endl; // 12 : 11에서 1을 증가시킨 후 출력
    std::cout << "int_key-- : " << input_key-- << std::endl; // 12 : 출력 후 1을 감소 시킴 -> 11
    std::cout << "--int_key : " << --input_key << std::endl; // 10 : 11에서 1을 감소시킨 후 출력


    int player_count; //플레이어 숫자
    int player_maxcount = 4; // 최대 플레이어 수
    int player_mincount = 2; // 최소 플레이어 수
    int now_turnID; // 현재 턴 플레이어id
    int win_grade = 15; // 승리 점수
    int player_havetoken; // 플레이어 소지 토큰(10개 제한)

    
    std::cout << std::boolalpha << ((10 < 5) == 0) << std::endl; // 10 < 5 가 0(false) 이고, 0(false) == 0 이라 1(true)를 출력한다.
    std::cout << std::noboolalpha << ((10 < 5) == 0) << std::endl;

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
