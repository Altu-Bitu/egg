//6�� ��� 3�� �̻� �������� ���¼�
//N��° ���� ���� ���ϱ�
//666��/�ڿ� ���� �ٿ������鼭 �������� ����.
//Ȥ�� 666���� 6,669,999���� ��� ����


#include <iostream>
#include<string>

using namespace std;

int endNumber(int n) {
    int cnt = 0; //������ ���� ī��Ʈ�ϴ� ����
    //666(ù ������ ����)���� ��� ����� �� ���ϱ�
    for (int i = 666;; i++) {
        string s = to_string(i); //to_string:���� -> ���ڿ��� ġȯ cf)stoi:����->����
        if (s.find("666") != s.npos) 
            //s.find: "666"�� ��ġ�� ã�Ƽ� ��ȯ. s.npos�� ���ڿ��� ��. (666������ ���ƴ�)
            cnt++; //ī����+1
        if (cnt == n) //n��° ���ڶ��
            return i; //����
    }
}

int main() {
    int n;

    //�Է�
    cin >> n;

    //����+���
    cout << endNumber(n) << '\n';

    return 0;
}