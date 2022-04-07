// 220406_HW_MyInfoVariable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
        ---------------- 오늘의 과제 ----------------
        
        1. 자기 자신을 분석해서
        2. 여러가지 타입의 변수로 정의한다
        총 20개의 변수를 정의하기
        
        예) 
            이름 : ...
            나이 : ...
            키 : ...
            혈액형 : ...
            MBTI : ...
        
        -------------------------------------------

        - string 이름
        - int 나이
        - int 생월
        - int 생일
        - float 키

        - string 혈액형
        - string MBTI
        - string 집주소_도
        - string 집주소_시
        - float 통학시간

        - string 전화번호
        - string 이메일 주소
        - string 블로그 주소
        - string 좋아하는 음식
        - string 싫어하는 음식

        - string 개발자 이름
        - string 개발자 메일
        - string 출시한 게임
        - string 출시한 게임 주소
        - float 개발 기간(월)

    */

    // 변수 선언과 초기화
    string name = "안중재";
    int age = 32;
    int birthMonth = 11;
    int birthDay = 5;
    float height = 174.2f;

    string bloodType = "O";
    string MBTI = "INTJ";
    string homeAddressState = "경기도";
    string homeAddressCity = "광주시";
    float commutingTime = 1.5f;

    string phoneAddress = "010-3159-5663";
    string mailAddress = "bbno1105@gmail.com";
    string blogAddress = "bbno.tistory.com";
    string favoriteFood = "초밥";
    string leastFavoriteFood = "매운음식";

    string developerName = "BBNO";
    string developerMailAddress = "bbnoproject@gmail.com";
    string gameName = "슬라임 여행기";
    string gameDownloadAddress = "play.google.com/store/apps/details?id=com.BBNO.SlimeWalker";
    float projectDuration = 6.0f;


    // 내 정보 출력
    std::cout << "이름 : " << name << endl;
    std::cout << "나이 : " << age << endl;
    std::cout << "생일 : " << birthMonth << "월 " << birthDay << "일" << endl;
    std::cout << "키 : " << height << "cm" << endl;

    std::cout << "혈액형 : " << bloodType << endl;
    std::cout << "MBTI : " << MBTI << endl;
    std::cout << "사는 지역 : " << homeAddressState << " " << homeAddressCity << endl;
    std::cout << "통학시간 : " << commutingTime << "시간" << endl;

    
    std::cout << "핸드폰 번호 : " << phoneAddress << endl;
    std::cout << "메일 주소 : " << mailAddress << endl;
    std::cout << "블로그 주소 : " << blogAddress << endl;
    


    std::cout << "개발자 이름 : " << developerName << endl;
    std::cout << "개발자 메일 : " << developerMailAddress << endl;
    std::cout << "출시한 게임 : " << gameName << endl;
    std::cout << "다운로드 주소 : " << gameDownloadAddress << endl;
    std::cout << "개발 기간 : " << projectDuration << "개월" << endl;





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
