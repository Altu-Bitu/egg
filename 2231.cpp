//브루트포스 알고리즘
//가능한 모든 경우를 시도
//입력 범위와 시간복잡도 고려 필요
//총 연산 수(모든경우의수*각경우연산횟수)가 1억 이하인 경우 시도해 볼 것!

//분해합 구하기. n의 가장 작은 생성자 구하기!
//245=245+2+4+5=256. 245는 256의 생성자.
#include <iostream>

using namespace std;

//가장 작은 생성자 리턴
int constructor(int n) {
    //n까지 모든 경우의 수를 고려해서 찾아간다.
    for (int i = 1; i < n; i++) {
        int k = i; //i를 변수로 쓰고 있으므로 k에 저장해서 사용.
        int sum = k; //자기 자신
        while (k > 0) { //각 자리 수의 합
            sum += (k % 10);
            k /= 10;
        }
        if (sum == n) //분해합이 n이라면
            return i; //바로 i리턴.
    }
    return 0; //생성자가 없는 경우
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산 + 출력
    cout << constructor(n) << '\n';

    return 0;
}