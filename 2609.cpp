#include <iostream>

using namespace std;

//O(n)����
int gcdBad(int a, int b) {
	//�� �� �� ������ �������� �ϳ��� �����ϸ� ����� �ִ��� �Ǵ�
	for (int i = min(a, b); i > 1; i--) {
		//����� �����ϸ� ����-->�ִ�����
		if(a % i == 0 && b % i == 0) {
			return 1;
		}
		return 1; //������ ������ �ִ����� 1
	}
}
//����Լ��� ������ ��Ŭ���� ȣ����
int gcdRecursion(int a, int b) {
	if (b == 0) //b�� 0�̸�
		return a; //a�� �ִ�����
	//a%b���� ������ b�� �ڸ� �ٲ㼭 ȣ��
	return gcdRecursion(b, a % b);

}


int main() {
	int a, b;

	//�Է�
	cin >> a >> b;

	//����
	//int g = gcdBad(a, b); //O(n)�Լ�
	int g = gcdRecursion(max(a, b), min(a, b)); //a>b�ǰ� �Լ� ȣ���Ѵ�
	int l = (a * b) / g;

	//���
	cout << g << '\n' << l << '\n';

	return 0;

}