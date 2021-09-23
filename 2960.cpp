#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//에라토스테네스의 체에서 K번째 지우는 수 구하는 함수
int isPrime(int n, int k) {
	vector<bool> is_prime(n + 1, true); //()안은 초기화 조건
	int cnt = 0; //카운트 변수
	//i*i까지만 검사하면 k번째 지워지는 수가 제곱근 이상의 소수일 경우 겸사 못함.
	//따라서 i*i<n이 아니라 i<=n까지 돌린다.
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) { //i가 소수라면
			for (int j = i; j <= n; j += i) { //문제에서 i번째도 카운팅 포함하니까 i부터 시작
				//제곱수 이전의 수는 이미 다지워지니까 시간감축위해 i*i안쓴다
				if (!is_prime[j]) //이미지워진 수라면
					continue; //카운팅안함
				is_prime[j] = false; //안지워졌으면
				if (++cnt == k) //카운팅+1
					return j; //k번째 지우는 수 리턴
			}
		}
	}

	//k번째 지우는 수 없으면 -1리턴
	return -1;

}

int main() {
	int n, k;

	//input
	cin >> n >> k;

	//연산+출력
	cout << isPrime(n, k) << '\n';

	return 0;
}