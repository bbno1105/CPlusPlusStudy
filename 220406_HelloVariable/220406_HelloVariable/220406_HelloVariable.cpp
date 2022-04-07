// 220406_HelloVariable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>


using namespace std;

void addition(int a, int b)
{
    cout << "14 += 3 (2) : " << (a += b) << endl;
}

void subtraction(int a, int b)
{
    cout << "14 -= 3 (2) : " << (a -= b) << endl;
}

void multiplication(int a, int b)
{
    cout << "14 *= 3 (2) : " << (a *= b) << endl;
}

void division(int a, int b)
{
    cout << "14 /= 3 (2) : " << (a /= b) << endl;
}

void remain(int a, int b)
{
    cout << "14 %= 3 (2) : " << (a %= b) << endl;
}

int main()
{
    // 변수
    /*
        1) 이름 : testNum  
        2) 크기 : 4byte  
        3) 값 : 2.8   
        4) 메모리주소 : 0000 0075 87AF FA04 (0~F까지 16진수로 되어있다)
           -> 나중에 포인터 배울 때 자세히 들어감
           -> 메모리 주소를 알고 있으면 변수명 몰라도 접근할 수 있다.
    */

    float testNum = 2.8f; // f를 붙이지 않으면 double형으로 인식하기 때문
    double testNum1 = 2.8;

    cout << "float : " << testNum << endl;
    cout << "double : " << testNum1 << endl;

    cout << "float size : " << sizeof(testNum) << "byte" << endl;
    cout << "float memoryAdress : " << &testNum << endl; // 변수 앞에 & 붙여서 메모리 주소를 확인할 수 있다.


    
    // 실습 1. 상대방 이름과 내 이름, 상대방 나이를 입력 받아서 축하메시지를 출력하는 프로그램을 만들어보자.
    cout << endl; // 구분을 위한 빈칸

    /*
        예시)
            상대방 이름을 입력하세요.
            _홍길동

            본인의 이름을 입력하세요.
            _안중재

            상대방 나이를 입력하세요.
            _24

            안중재 : 홍길동님 24살 생일을 축하합니다.

        ▶ 입력하고 출력한다
        - 입력 : 상대방 이름, 내 이름, 상대방 나이
                (+) 사용자가 입력할 데이터에 대한 안내 메시지 출력
        - 출력 : 축하 메시지 : "(내 이름) : (상대방 이름)님 (상대방 나이)살 생일을 축하합니다."
                데이터 : 내 이름, 상대방 이름, 상대방 나이
    */

    /*
        ☆★☆★☆★☆★☆★ 변수형 이름 규칙 ☆★☆★☆★☆★☆★


        1. C++에서 사용하는 키워드들은 변수명으로 사용할 수 없다.
           int float = 3.4f (X)
        
        2. 알파벳, 숫자, _ 로만 구성할 수 있다.
           int num_3 = 3;

           2-1) 숫자로 변수명을 시작할 수는 없다
                int 3_num = 3; (X)

        3. 대/소문자 구분을 한다.
           int num; int Num; 
           num =! Num

        4. 변수명 사이에는 띄어쓰기를 넣을 수 없다.
           int n um = 3; (X)

        5. 전부 소문자로 작성한다.
        
        6. (과도한) 축약어를 쓰지 않는다.
           int num; (O)
           int n; (X) 변수명만으로 알아보기 힘들다.

           헝가리안 표기법
           카멜 표기법

        ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
    */

    int _3num = 3;

    string sangdaeName; // string sangdaeName, myName 이렇게 한 번에 두개의 변수 선언이 가능하다.
    int sangdaeAge;
    string myName;

    cout << "상대방 이름을 입력하세요." << endl;
    cin >> sangdaeName;

    cout << "\n" << "본인의 이름을 입력하세요." << endl;
    cin >> myName;

    cout << "\n" << "상대방 나이를 입력하세요." << endl;
    cin >> sangdaeAge;

    cout << "\n" << myName << " : " << sangdaeName << "님 " << sangdaeAge << "살 생일을 축하합니다." << endl;

    /*
        H/W 오늘의 과제

        1. 자기 자신을 분석해서
        2. 여러가지 타입의 변수로 정의한다

        예) 
            이름 : ...
            나이 : ...
            키 : ...
            혈액형 : ...
            MBTI : ...

        총 20개의 변수를 정의하기
    */



    /*
        연산자
        데이터를 가공(연산)하는 모든 명령어에 필요한 것들
        1) 어떤 종류의 연산자들이 있는지?
        2) 우선 순위 : 어떤 순서로 연산이 진행되는지?
        3) 결합 순서 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

        1. 사칙연산 : 산술연산자 (좌측부터 연산)
        
        + : 더하기
        - : 빼기
        * : 곱하기
        / : 나누기  11 / 3 = 3;
        % : 나머지  11 % 3 = 2;

        우선순위 : *,/,% > +, -

        2. 대입연산자 (우측부터 연산)
        = : 왼쪽 항에 오른쪽 항의 값을 대입한다.(복사한다)

        3. 복합대입연산자
        += : a += b;    =>    a = a + b;
        -= : a -= b;    =>    a = a - b;
        *= : a *= b;    =>    a = a * b;
        /= : a /= b;    =>    a = a / b;
        %= : a %= b;    =>    a = a % b;  (a와 b는 정수형 타입이어야 한다)
        
        4. 증감연산자
        특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용한다.
        변수의 앞이나 뒤에 ++ / -- 를 붙어서 사용한다.

        5. 관계연산자
        두 값을 비교한 결과가 참(1,true)인지 거짓(0,false)인지 반환하는 연산자

        < : a < b : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
        > : a > b : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
        <= : a <= b : 왼쪽 항의 값이 오른쪽 항의 값보다 같거나 작으면 참을 반환한다.
        >= : a >= b : 왼쪽 항의 값이 오른쪽 항의 값보다 같거나 크면 참을 반환한다.
        == : a == b : 왼쪽 항의 값과 오른쪽 항의 값이 같을 때, 참을 반환한다.
        != : a != b : 왼쪽 항의 값과 오른쪽 항의 값이 다를 때, 참을 반환한다.

    */
    cout << "\n\n";

    int left_value = 11 + 3; //14
    int right_value = 3; 
    // right_value = 0 일 경우 0으로 나눌 수 없어 런타임 오류가 발생한다
    // 오류가 발생한 지점에서 멈춤

    left_value--; // 증감 연상자가 뒤에 붙으면 실행되고난 후에 출력
    cout << "14-- : 출력 = " << left_value-- << " 메모리 = " << left_value << endl; // 출력 : 13 , 메모리 : 14
    ++left_value; // 증감 연상자가 앞에 붙으면 계산되고난 후에 출력
    cout << "++14 : 출력 = " << ++left_value << " 메모리 = " << left_value << endl; // 출력 : 14 , 메모리 : 14

    cout << "\n";


    cout << "14 + 3 : " << left_value + right_value << endl; // 17
    cout << "14 - 3 : " << left_value - right_value << endl; // 11
    cout << "14 * 3 : " << left_value * right_value << endl; // 42
    cout << "14 / 3 : " << left_value / right_value << endl; // 4
    cout << "14 % 3 : " << left_value % right_value << endl; // 2

    cout << "\n";

    cout << "14 += 3 : " << (left_value += right_value) << endl; // 17
    cout << "14 -= 3 : " << (left_value -= right_value) << endl; // 14
    cout << "14 *= 3 : " << (left_value *= right_value) << endl; // 42
    cout << "14 /= 3 : " << (left_value /= right_value) << endl; // 14
    cout << "14 %= 3 : " << (left_value %= right_value) << endl; // 2

    cout << "\n";

    left_value = 14;
    addition(left_value, right_value); //17
    subtraction(left_value, right_value); //11
    multiplication(left_value, right_value); //42
    division(left_value, right_value); //4
    remain(left_value, right_value); //2

    /*
        실습.
        고객의 나이를 입력받아서 미성년자(19세 이하)이면 true를 출력
        성인이면 false를 출력.
    
        아까 입력 받은 나이를 기준으로, 주민등록증 발급 대상(20살만)이면 true를, 아니면 false를 출력.    
    
        + 아홉수(1의 자리가 9인 수)인지 확인해서 true, false를 출력
    */

    cout << "\n\n";

    int yourAge;
    cout << "고객의 나이를 입력하세요 : " ;
    cin >> yourAge;

    cout << boolalpha; // 관계를 true, false로 표시해준다.
    cout << "미성년자 인가요? : "<< (yourAge <= 19) << endl;
    cout << "주민등록증 발급 대상인가요? : " << (yourAge == 20) << endl;
    cout << noboolalpha; // boolalpha 를 no 해준다.
    cout << "아홉수 인가요? : " << ((yourAge % 10) == 9) << endl;

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
