// #include <stdio.h>
// #include <stdlib.h>
// �����д��û������Ļ�...���԰���������ȥ�����Ұ������ע��ȡ��
#include <bits/stdc++.h>
using namespace std;
bool cmpare(char c1, char c2)
{
	char l[4];
	int indexc1, indexc2;
	// ��֪��c������ôд...
	l[0] = 'H', l[1] = 'S', l[2] = 'D', l[3] = 'C';

	// ��һ���Ƚ����׿�����д����...
	for (int i = 0; i < 4; ++i) {
		if(l[i] == c1) indexc1 = i;

		if(l[i] == c2) indexc2 = i;
	}

	return indexc1 < indexc2;
}

struct poker {
	int x;
	char typ;
	bool operator < (const poker (&a)) const
	{
		if(typ == a.typ) return x < a.x;
		else return cmpare(typ, a.typ);
	}
};
poker a[5], b[5];
void convert(int *s)
{

}
void init()
{
	// ������ǳ�ʼ�� �ֱ�ѵ�һ�ŵĺ͵ڶ��ŵĳ�ʼ��Ϊһ������
	for (int i = 0; i < 3; ++i) {
		char c[10];
		int vali;
		scanf("%s", c);
		a[i].typ = c[0];

		if(isdigit(c[1])) {
			sscanf(&c[1], "%d", &vali); // �����д�
		} else {
			// ��ʱ���ַ�ת��Ϊ����
			if(c[1] == 'J') vali = 11;

			if(c[1] == 'Q') vali = 12;

			if(c[1] == 'K') vali = 13;

			if(c[1] == 'A') vali = 14;
		}

		a[i].x = vail;
	}

	for (int i = 0; i < 3; ++i) {
		char c[10];
		int vali;
		scanf("%s", c);
		b[i].typ = c[0];

		if(isdigit(c[1])) {
			sscanf(&c[1], "%d", &vali); // �����д�
		} else {
			// ��ʱ���ַ�ת��Ϊ����
			if(c[1] == 'J') vali = 11;

			if(c[1] == 'Q') vali = 12;

			if(c[1] == 'K') vali = 13;

			if(c[1] == 'A') vali = 14;
		}

		b[i].x = vail;
	}

	sort(a, a + 3);
	sort(b, b + 3);
}
int main()
{
	init();

	return 0;
}
