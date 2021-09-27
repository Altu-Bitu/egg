//6이 적어도 3개 이상 연속으로 들어가는수
//N번째 종말 숫자 구하기
//666앞/뒤에 숫자 붙여나가면서 오름차순 정렬.
//혹은 666부터 6,669,999까지 모두 점검


#include <iostream>
#include<string>

using namespace std;

int endNumber(int n) {
    int cnt = 0; //종말의 숫자 카운트하는 변수
    //666(첫 종말의 숫자)부터 모든 경우의 수 구하기
    for (int i = 666;; i++) {
        string s = to_string(i); //to_string:숫자 -> 문자열로 치환 cf)stoi:문자->숫자
        if (s.find("666") != s.npos) 
            //s.find: "666"의 위치를 찾아서 반환. s.npos는 문자열의 끝. (666있으면 끝아님)
            cnt++; //카운팅+1
        if (cnt == n) //n번째 숫자라면
            return i; //리턴
    }
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산+출력
    cout << endNumber(n) << '\n';

    return 0;
}