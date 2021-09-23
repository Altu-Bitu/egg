//n:m을 최대공약수로 약분하여 a:b로 표현하기
//유클리드 호제법사용~
//입력받을 때 stoi: (string --> int) 변환 사용!

#include<iostream>

using namespace std;

//최대공약수: 유클리드 호제법 재귀함수
int gcdRecursion(int a, int b) {
	if (b == 0)	//b가 0이면
		return a;  //a가 최대공약수
	//a%b 구하고 -> b와 자리 바꿔서 호출
	return gcdRecursion(b, a % b);

}


int main() {
	string s;  //문자열 입력받기 위해 string변수 선언

	//입력
	cin >> s; //문자로 한번에 입력받기

	//입력으로부터 n, m 추출하기
	int index = s.find(':'); //:의 위치를 찾아서 index에 저장
	int n = stoi(s.substr(0, index)); //substr:0부터 index번째 까지를 숫자로 변경
	int m = stoi(s.substr(index + 1, s.length())); //:이후 문자를 숫자로 변경

		//최대공약수 구하기
		int g = gcdRecursion(max(n, m), min(n, m));

	//출력
	cout << n / g << ':' << m / g << '\n';

	return 0;
}
