// 220405_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
 //주석 : 실행되지 않고 설명만을 위해 사용되는 문법 (단축키 : 생성:Ctrl+K+C , 제거:Ctrl+K+U) 
/*
  여러 줄 짜리
  주석을
  사용하고
  싶을 때
*/

/*
    [#include <iostream> 이란??]

    #include를 이용해서 다른 소스파일의 내용을 불러올 수 있다.
    <iostream>의 std::cout 기능을 정의해 둔 것을 사용함

    사용법
        #include "파일명.h"    <- C 라이브러리 파일 포함, 우리가 만든 소스파일을 포함시킬 때
        #include <파일명>      <- C++ 라이브러리 파일 포함

    #include를 사용하는 문법은 소스파일의 가장 상단에 위치해야 한다

    iostream = i(input:입력) o(output:출력) stream
*/

/*
    [C++ 프로그래밍 언어가 가지는 표현적 특성]

    1) 대 / 소문자를 구분하자
        main, Main, mAIN, maIN << 컴파일러가 대/소문자가 다른 4가지 모두 다른 것으로 처리한다.

    2) 띄어 쓰기를 통해 각 요소를 구분한다
        std::cout, <<, "Hello World!\n"; 3가지 요소로 구분한다
        (int num = 3; 이라면 int, num, =, 3; 의 4가지 요소로 구분)

    3) 실행문의 끝을 ;(세미콜론)으로 마무리한다.
*/

// #include <fstream>
#include <iostream> 
#include<string>

using namespace std;

int main()
// int : 함수를 통해 나오는 데이터 타입 (정수형 데이터)
// main() : main이라는 함수 이름, ()함수에 들어가는 값
// {} : 함수에서 지지고 볶는 공간
{
    // 변수 : 데이터를 저장하는 메모리공간에 붙여진 이름

    /*
        1) 이름(num)   2) 값(3)    3) 메모리주소(?)    4) 크기(데이터타입)
        데이터 타입이 나뉜 이유 : 변수마다 처리하는 방식이 다르기 때문 + 효율적으로 메모리공간을 사용하기 위함

        [정수형 변수를 저장하는 데이터타입]
        변수                    byte                      기억범위
        short                    2                    -32768 ~ 32767
        unsigned short           2                         0 ~ 65535
        int                      4               -2147483648 ~ 2147438647
        unsigned int             4                         0 ~ 4294967295
        long               4(Cpu최적화된 크기)    -2147483648 ~ 2147438647
        unsigned long      4(Cpu최적화된 크기)              0 ~ 4294967295
        long long                8    –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807

        4byte = 32bit가 기본
        64bit 컴에서 long은 8byte 크기 됨

        byte(bit)로 크기 계산하기
        1byte(8bit)
        128  64   32   16   8    4    2    1
        0     0    0    0   0    0    0    0

        1. 각 데이터 타입에는 어떤 것들이 있는지
        2. 각 데이터 타입별로 크기는 어떻게 되고 표현할 수 있는 숫자의 범위는 어떻게 되는지
    */
    std::cout << "\n[정수형]";
    int num = 3; // int(정수형 데이터 타입) num(변수의 이름)

    // short
    std::cout << "\n";
    short maxShortNum = SHRT_MAX; // 32767; 
    short minShortNum = SHRT_MIN; // -32768

    std::cout << " maxShortNum : " << maxShortNum << std::endl;
    std::cout << " minShortNum : " << minShortNum << std::endl;
    std::cout << " short 크기 : " << sizeof(short) << "Byte" << std::endl;
    std::cout << " minShortNum 크기 : " << sizeof(minShortNum) << "Byte" << std::endl;

    // unsigned short
    std::cout << "\n";
    unsigned short maxUShortNum = USHRT_MAX; // 65535

    std::cout << " maxUShortNum : " << maxUShortNum << std::endl;
    std::cout << " maxUShortNum 크기 : " << sizeof(maxUShortNum) << "Byte" << std::endl;

    // int
    std::cout << "\n";
    int maxInt = INT_MAX; // 2147438647
    int minInt = INT_MIN; // -2147483648

    std::cout << " maxInt : " << maxInt << std::endl;
    std::cout << " maxInt의 크기 : " << sizeof(maxInt) << "Byte" << std::endl;

    std::cout << " __int8 : " << sizeof(__int8) << "Byte" << std::endl;
    std::cout << " __int16 : " << sizeof(__int16) << "Byte" << std::endl;
    std::cout << " __int32 : " << sizeof(__int32) << "Byte" << std::endl;
    std::cout << " __int64 : " << sizeof(__int64) << "Byte" << std::endl;

    // long, long long
    std::cout << "\n";
    int maxLong = LONG_MAX; // 2147438647
    int minLong = LONG_MIN; // -2147483648

    std::cout << " maxLong : " << maxLong << std::endl;
    std::cout << " minLong : " << minLong << std::endl;
    std::cout << " maxLong : " << sizeof(maxLong) << "Byte    " << std::endl;
    std::cout << " long long : " << sizeof(long long) << "Byte" << std::endl;


    /*
        [실수형 변수를 저장하는 데이터타입]
        변수명                   byte                     기억범위
        float                     4             -1.2*(10^38) ~ 3.4*(10^38)
        = 소수점 7자리까지 표현 가능
        double                    8            -2.2*(10^308) ~ 1.8(10^308)
        = 소수점 15자리까지 표현 가능
        long double               8            -2.2*(10^308) ~ 1.8(10^308) ???
    */
    std::cout << "\n[실수형]";

    // float
    std::cout << "\n";
    std::cout << " float의 크기 : " << sizeof(float) << "byte" << std::endl;

    // double
    std::cout << " double의 크기 : " << sizeof(double) << "byte" << std::endl;
    std::cout << " long double의 크기 : " << sizeof(long double) << "byte" << std::endl;


    /*
        [문자형 변수를 저장하는 데이터타입]
        변수명                   byte                     기억범위
        char                      1                     -128 ~ 127
        unsignedchar              1                        0 ~ 255 ???
        wchar_t                   2                        0 ~ 65535
    */
    std::cout << "\n[문자형]\n";

    // char
    char a = 'a'; // 문자형은 '' 작은 따옴표를 쓴다
    std::cout << " a : " << a << std::endl;
    std::cout << " a-1 : " << a - 1 << std::endl;
    std::cout << " sizeof(a) : " << sizeof(a) << std::endl;



    /*
        [문자열을 저장하는 데이터타입]
        char 변수명[문자수+1] 의 배열을 사용
        * 문자수에 +1 해주는 이유는 \0(null)이 기본으로 들어가 있기 때문

        string을 쓰기 위해 #include<string> 이거 불러와야 함
    */
    std::cout << "\n[문자열]\n";

    std::string helloText = "Hello World!"; // 문자열은 "" 큰 따옴포를 쓴다
    cout << " helloText : " << helloText << std::endl;
    std::cout << " helloText의 크기 : " << sizeof(helloText) << std::endl;
    std::cout << "\n\n";

    // 예제) "___님 환영합니다"
    std::cout << "\n[이름을 입력해 주세요]\n";

#include<string> // #include<string> 이거 선언해야 string 쓸 수 있음
    string name;     // name이라는 문자열 변수를 선언한다

    cin >> name; // name에 입력하겠다.

    std::cout << "\n[결과]\n";

    cout << name << "님 환영합니다." << std::endl;



    //std::cin >> num; //입력을 받는 함수 cin >> 변수

    //std::cout << num << ". Hello World!\n"; 
    //std::cout << "1. Hello World!\n";
    //std::cout << "2. Hello World!\n";
    //std::cout << "3. Hello World!\n";

    // H/W : 노션에 내용 정리하기
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
