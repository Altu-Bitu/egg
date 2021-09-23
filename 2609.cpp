#include <iostream>

using namespace std;

//O(n)연산
int gcdBad(int a, int b) {
	//두 수 중 작은거 기준으로 하나씩 감소하며 공약수 있는지 판단
	for (int i = min(a, b); i > 1; i--) {
		//공약수 존재하면 리턴-->최대공약수
		if(a % i == 0 && b % i == 0) {
			return 1;
		}
		return 1; //끝까지 없으면 최대공약수 1
	}
}
//재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b) {
	if (b == 0) //b가 0이면
		return a; //a가 최대공약수
	//a%b구한 다음에 b랑 자리 바꿔서 호출
	return gcdRecursion(b, a % b);

}


int main() {
	int a, b;

	//입력
	cin >> a >> b;

	//연산
	//int g = gcdBad(a, b); //O(n)함수
	int g = gcdRecursion(max(a, b), min(a, b)); //a>b되게 함수 호출한다
	int l = (a * b) / g;

	//출력
	cout << g << '\n' << l << '\n';

	return 0;

}