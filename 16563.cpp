//N개 자연수 k를 소인수분해. 소인수를 오름차순으로 배열
//에라토스테네스의 체 사용: 소수를 구하는 과정을 활용!
//소수가 아니라서 지워지면 어느 소수에 의해 지워진건지까지 저장
//2-->4/8/..들의 prime에 2 저장. 3-->6/9/... 이미값이 존재하면 갱신X. 9의 prime에만 3저장.
//K=8이다: 8/prime[8] - 4(출력) - 4/prime[4] - 2(출력) ==prime[2]일 경우 종료 후 저장.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 5000000;

//소수 경로 저장후 리턴
vector<int> isPrime() {
	vector<int> prime(SIZE + 1, 0); //5000000까지 되야하니까 +1 해준다

	/* 그냥 에라토스 구현시
	for(int i=2; i<=sqrt(SIZE);) //i*i<SIZE도 가능. sqrt는 제곱수구해주는애
		if (prime[i]) {  //i가 소수라면
			for (int j = i * i; j <= SIZE; j++) {  //i의 배수를 지움
				prime[j] == false;
			}
		}
	*/


//먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장.
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	//소수판별
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) {  //i가 소수일때
			for (int j = i * i; j <= SIZE; j += i) {
				prime[j] = i; //i의 배수들은 i를 인수로 가지니깐 걔네들 배열에 i저장
				if (prime[j] == j) {  //저장된 소수가 없으면(예를 들어 2의 배수 싹 지우고 3에 왔을때)
					prime[j] == i;  //걔는 소수겠지
				}
			}
		}
	}

	return prime;
}


int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	//입력
	cin >> n;

	//최대크기까지의 소수 경로 저장-->각각 해주면 비효율적이니깐
	//위에서 말한 소수저장 표를 미리 만들어둔다.
	vector<int> prime = isPrime();


	//입력-연산-출력
	while (n--) { //n번 입력 받았으니 0~n-1까지 반복
		//소인수분해할 수 입력
		cin >> k;
		//소인수분해 결과 출력
		while (k > 1) { //k가 1이 될때까지 반복
			cout << prime[k] << ' ';  //처음에 해당칸에 있는 소수 출력
			k = k / prime[k];  //그리고 그 소수로 나누면 나머지 나오겠지. 그럼 그 나머지애의 칸에있는 소수 또출력.
		}
		cout << '\n';
	}
	return 0;
}