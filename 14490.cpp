//n:m�� �ִ������� ����Ͽ� a:b�� ǥ���ϱ�
//��Ŭ���� ȣ�������~
//�Է¹��� �� stoi: (string --> int) ��ȯ ���!

#include<iostream>

using namespace std;

//�ִ�����: ��Ŭ���� ȣ���� ����Լ�
int gcdRecursion(int a, int b) {
	if (b == 0)	//b�� 0�̸�
		return a;  //a�� �ִ�����
	//a%b ���ϰ� -> b�� �ڸ� �ٲ㼭 ȣ��
	return gcdRecursion(b, a % b);

}


int main() {
	string s;  //���ڿ� �Է¹ޱ� ���� string���� ����

	//�Է�
	cin >> s; //���ڷ� �ѹ��� �Է¹ޱ�

	//�Է����κ��� n, m �����ϱ�
	int index = s.find(':'); //:�� ��ġ�� ã�Ƽ� index�� ����
	int n = stoi(s.substr(0, index)); //substr:0���� index��° ������ ���ڷ� ����
	int m = stoi(s.substr(index + 1, s.length())); //:���� ���ڸ� ���ڷ� ����

		//�ִ����� ���ϱ�
		int g = gcdRecursion(max(n, m), min(n, m));

	//���
	cout << n / g << ':' << m / g << '\n';

	return 0;
}
