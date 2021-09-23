#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//�����佺�׳׽��� ü���� K��° ����� �� ���ϴ� �Լ�
int isPrime(int n, int k) {
	vector<bool> is_prime(n + 1, true); //()���� �ʱ�ȭ ����
	int cnt = 0; //ī��Ʈ ����
	//i*i������ �˻��ϸ� k��° �������� ���� ������ �̻��� �Ҽ��� ��� ��� ����.
	//���� i*i<n�� �ƴ϶� i<=n���� ������.
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) { //i�� �Ҽ����
			for (int j = i; j <= n; j += i) { //�������� i��°�� ī���� �����ϴϱ� i���� ����
				//������ ������ ���� �̹� ���������ϱ� �ð��������� i*i�Ⱦ���
				if (!is_prime[j]) //�̹������� �����
					continue; //ī���þ���
				is_prime[j] = false; //������������
				if (++cnt == k) //ī����+1
					return j; //k��° ����� �� ����
			}
		}
	}

	//k��° ����� �� ������ -1����
	return -1;

}

int main() {
	int n, k;

	//input
	cin >> n >> k;

	//����+���
	cout << isPrime(n, k) << '\n';

	return 0;
}