// #include <stdio.h>
// #include <stdlib.h>
// 如果我写的没有问题的话...可以把下面两行去掉并且把上面的注释取了
#include <bits/stdc++.h>
using namespace std;
bool cmpare(char c1, char c2) {
	char l[4];
	int indexc1, indexc2;
	// 不知道c语言怎么写...
	l[0] = 'H', l[1] = 'S', l[2] = 'D', l[3] = 'C';

	// 用一个比较容易看懂的写法吧...
	for (int i = 0; i < 4; ++i) {
		if(l[i] == c1) indexc1 = i;

		if(l[i] == c2) indexc2 = i;
	}

	return indexc1 < indexc2;
}
struct poker {
	int x;
	char typ;
	bool operator < (const poker (&a)) const {
		if(typ == a.typ) return x < a.x;
		else return cmpare(typ, a.typ);
	}
	bool operator == (const poker (&a)) const {
		if(typ == a.typ && x == typ.x) return true;

		return false;
	}
};
poker a[5], b[5];
void convert(poker *s) {
	for (int i = 0; i < 3; ++i) {
		char c[10];
		int vali;
		scanf("%s", c);
		s[i].typ = c[0];

		if(isdigit(c[1])) {
			sscanf(&c[1], "%d", &vali); // 可能有错
		} else {
			// 这时候将字符转化为数字
			if(c[1] == 'J') vali = 11;

			if(c[1] == 'Q') vali = 12;

			if(c[1] == 'K') vali = 13;

			if(c[1] == 'A') vali = 14;
		}

		s[i].x = vali;
	}
}
void init() {
	// 下面的是初始化 分别把第一排的和第二排的初始化为一个数字
	convert(a);
	convert(b); // 应该是这么写的吧...
	sort(a, a + 3);
	sort(b, b + 3);
}
void final_cmp() {
	for (int i = 0; i < 3; ++i) {
		if(a[i] == b[i]) continue;
		else {
			return a < b;
		}
	}

	return true;
}
int main() {
	init();

	if(final_cmp())
		printf("Winner is A!");
	else
		printf("Winner is B!");

	for (int i = 0; i < 3; ++i) {
		cout << a[i].typ << a[i].x << " ";
	}

	for (int i = 0; i < 3; ++i) {
		cout << b[i].typ << b[i].x << " ";
	}

	return 0;
}