#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::pair;

inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read()) {
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
// �������� ???
// ����������
/*
���˾��ÿ�����ôʵ��
����һ��ͼ�����ϲ��鼯ά��
�ֿ�����...
ά��һ��һά���飬Ȼ��ÿ������������֮���м��һ��С���Աߵ�
���Թ���һ�����飬ÿ�β���֮���м�-1...
Ȼ������ߵ���������������ֵ...
����...ʱ�临�Ӷ�O(NM), ��ը...
���԰�����ѧǰ׺��..
��ô�;��ò�ֿ��Խ����
��..��Ŀ���qwq

���ģ����
������Ϊ��Ŀ����ܼ򵥰�ģ��ɾ��...ģ��̫�Ӵ���
����˵��ǰ׺��...��ȷ�е��񣬵�ǰ׺����ǰ׺�ͣ�����ǲ�ְ�qwq...
���ǲ�ֺ�.jpg
���Ĳ��ֶ���ע��
 */
inline void swap(int &a, int &b) {
    int c = b; b = a, a = c;
}

const int maxn = 1e5;
int n, i, h, r;
int a, b;
int sub[maxn];
std::set<pair<int, int> > vis;
int main()
{
    read(n); read(i); read(h); read(r);
	for (int qwq = 0; qwq < n; ++qwq) 
	{
		read(a); read(b);
		if(a > b) swap(a, b);
		// md����˵Ҫ���ذ�!!!
		if(vis.count(pair<int, int>(a, b))) continue;
		else vis.insert(pair<int, int>(a, b));
		// ----------------------
		--sub[a + 1]; // ��ֹ���
		++sub[b]; // ��ֹ���
		// ----------------------
	}
	for (int i = 1; i <= n; ++i) {
		// ----------------------
		h += sub[i];
		// ----------------------
		cout << h<< endl;
	}
	return 0;
}
