// 220415_TodayStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

using namespace std;

#include <iostream>
#include <string>

struct score
{
    int kor;
    int eng;
    int math;
};

struct student
{
    string name; // 클래스도 쓸 수 있다.
    int age; // 기본 자료형도 쓸 수 있다.
    string homeTown;
    int pride;
    int monthlyScore[12]; // 변수도 쓸 수 있다.
    score myScore; // 구조체도 쓸 수 있다.
} seoyeon, jaehyuk ; // 중괄호와 세미콜론 사이에 변수를 미리 선언할 수 있다.

// name, age, korScore, rank라는 하위 변수를 가지고 있는 student라는 구조체를 정의한다.

int main()
{
    std::cout << "Hello World!\n";

    /*
        구조체
        1. 절차적
        2. 구조적
        3. 객체지향적

        ### 추상화 ###
        C언어에서 코드를 추상화 하는데 사용되는 삼총사 
        - 배열, 구조체, 함수

        추상화??? 실제 세계 ( 현상 )를 간략화/기호화/보편화 해서 표현한 것
        코드에서 추상화가 필요한 이유 : 결국 코드는 사람이 짜는 것이기 때문에
        다른 사람이 코드를 해석하기 편리해야 하고
        다른 사람이 인수인계받아서 유지보수하기 편리해야 하고
        다른 사람들과 함께 공동으로 코드를 만들기 편리해야 하고
    
        1) 배열 : 속성이 동일한 여러개의 데이터를 같은 이름과 순서를 지정한 연속된 번호로
                  서로 연관되어 있음을 표시함으로써 추상화함

        2) 구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화

        3) 함수 : 프로세스(코드)를 특정 기능 단위로 묶어서 추상화

        최악의 추상화 -> 추상화 단계를 상승시키는 과정

        //string a, b, c; // << 최악의 추상화
        //string a[3]; // << 위의 것보다는 좀 낫다
        //string name1, name2, name3; // << 아니면 이런 식으로든지
        //string studentName[3]; // 위의 것보다는 의도가 명료하게 드러나기 때문에 좋은 추상화
    */

    /*
        구조체란???
        - 변수를 모아 놓은 집합체
        - 특정 변수들이 무언가의 하위 개념으로 묶일 수 있을 때
        - studentName[10], studentAge[10], studentKorScore[10], ....
        - '학생'의 'xxx' : '학생'이라는 공통점이 있다
        - 이름, 나이, 국어점수, 석차 등등을 '학생'이라는 구조체로 묶어서 사용

        1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 정의한다.
           ( 해당 함수의 바깥쪽 앞(위) )

        int main(){} // 이놈이 지금 우리가 쓰고 있는 유일한 함수

        2. 구조체 정리의 방법
        struct 구조체 변수명
        {
            구조체 안에 들어갈 하위 변수
            ( 위의 예시에 따르면 이름, 나이, 국어점수, 석차 등 )
        };
        //세미콜론
        
        구조체는 일종의 우리가 세롭게 만든 데이터형이다.

        구조체 안에 들어갈 수 있는 하위변수는 무엇이 있을까????
        당연히 int/bool/float 같은 기본 자료형들은 모두 사용 가능
        string <- 클래스도 쓸 수 있고

        3. 구조체의 선언과 초기화
        기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
        int score[3] = {50,80,100};
        구조체 변수도 다음과 같이 선언과 동시에 초기화할 수 있다.

        player.HP = player.HP - moster[n].dmg;
        플레이어 HP = 플레이어 HP - 몬스터n 데미지
        <- 주석 없이 코드를 배우지 않은 사람에게도 어느정도의 가독성이 확보된다.
    */
    
    student minseop; // 새롭게 만든 데이터형의 minseop이라는 변수 선언
    minseop.name = "심민섭";
    minseop.age = 34;
    minseop.homeTown = "인천";
    minseop.pride = 100;
    minseop.myScore.eng = 79;
    minseop.myScore.kor = 95;
    minseop.monthlyScore[0] = 80;
    minseop.monthlyScore[1] = 95;

    // 초간단 실습 : student 구조체를 사용해서 자기 자신의 정보를 입력해 보자

    student jj;
    jj.name = "안중재";
    jj.age = 32;
    jj.homeTown = "경기도 광주시";
    jj.pride = 100;
    jj.myScore.math = 99;
    jj.monthlyScore[10] = 1;
    
    cout << jj.name << endl;
    cout << jj.age << endl;
    cout << jj.homeTown << endl;
    cout << jj.pride << endl;
    cout << jj.myScore.math << endl;
    cout << jj.monthlyScore[10] << endl;

    score myScore = { 50,80,100 }; // 구조체 순서대로 초기화할 수 있다
    // monster a = { "고블린", 79, 55.12f, true, 100 };
    cout << myScore.eng << ", " << myScore.kor << ", " << myScore.math;

    /*
        과제 : 미궁탈출 게임의 업데이트
        사용할 수 있는 모든 요소에 구조체를 활용해서 소스코드를 개선해 보세요.

        tile : 지형 정보를 넣고 (숲, 늪, 평지)
        
        - 지형 상태
        
        player : 피로도를 넣고
        - 

        플레이어가 어느 지형에 있는지, 플레이어의 피로도가 얼마인지 ( 숲 -1, 늪 -3, 평지 0 )
    */




}
