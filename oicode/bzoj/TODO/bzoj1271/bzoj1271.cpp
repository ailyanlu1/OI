// ��Ŀ�����Ǻܼ򵥵�
/*
������ô��
��Ȼ�ܹ�ֻ��һ��������
��ô������������������������ż��
��Ȼ��λ�ã���ô�Ϳ��Զ���
���ֳ��������λ�þͶ�����
��Ŀ�Ƚϼ򵥣�template������
�뵽�˶����ǵ�һ������...����������ôͳ��ÿһ��λ�õ�..
emmmmm......��ô������...����ˣ�
emmmmm��ÿcheckһ�ζ�Ҫ������һ��ôqwq...�����е����ӣ��Ͼ��Ƕ���
O(nlogn)
 */
#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int maxn = 200005;
int t, n;
int s[maxn], e[maxn], d[maxn];
inline bool check(int val)
{
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if(s[i] <= val) {
			if(e[i] <= val) count += (e[i] - s[i]) / d[i] + 1;
			else count += (val - s[i]) / d[i] + 1;
		}
	}
	return (count % 2 != 0);
}

int main() 
{
	t = read();
	for (int rp = 0; rp < t; ++rp)
	{
		n = read();
		for (int i = 1; i <= n; ++i) {
			s[i] = read(); e[i] = read(); d[i] = read();
		}
    	// init finished
    	int l = 1, r = n, mid = (l + r) >> 1;
    	while(true) 
    	{
    		int mid = (l + r) >> 1;
    		if(check(mid))
    		{
    			l = mid + 1;
    		}
    		else {
    			r = mid;
    		}
    		if(l == r) break;
    	}
    	cout << l << endl;
	}
}