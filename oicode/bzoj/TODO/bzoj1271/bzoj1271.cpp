// ��Ŀ�����Ǻܼ򵥵�
// statuc: WA???
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
bzoj��ס�ˣ��û�дһдע�� 
 */
#include <bits/stdc++.h>
using namespace std;
// ����������� 
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
// t��ʾ���������� n��ʾ�������� 
int t, n;
// �����������������
 
int s[maxn], e[maxn], d[maxn];
/*
���ֵı��ʾ��ǽ������ֵ�����ת��Ϊ�ж�
���Ի�����ÿһ�����ֵĳ�����Ҫһ���ж�
������logn���ж��������ж����ӵ㶼û�������˵
����ж��ͱȽϸ��� ��O(n)��...
ԭ�����������ɨ�� ֮ǰ���������(��ʵ�����˺��񻹿��Ը��죬����û��Ҫ��
�жϵ�ǰ����֮ǰ���еĸ���
֮ǰ�Ѿ������ˣ�������������ʹ����������ڵ�ǰjudge��֮ǰ�������ż������֮��
������һ�����У���Ϊ���ܹ��ˣ�val�������...
Ϊɶbzoj��û�ð�...
��֮���judge������������� 
�� WA��...����... 
 */ 
inline bool check(long long val)
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
// �����Ƕ��ֵľ��� 
inline long long bina(long long l, long long r) 
{
	while(l < r) {
		long long mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;		
	} 
	return l;
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
    	long long posi = bina(1, n);
    	long long cnt = 0;
    	for (int i = 1; i <= n; ++i) {
    	    // �������󡰼����м�ĵ�����
    	    // ������һ��s[i] <= posi && e[i] >=
    		if(s[i] <= posi && e[i] >= posi && (posi - s[i]) % d[i] == 0) ++cnt;
    	}
    	if(cnt % 2 == 0) cout << "Poor QIN Teng:(" << endl;
    	else cout << posi << " " << cnt << endl;
	}
}
