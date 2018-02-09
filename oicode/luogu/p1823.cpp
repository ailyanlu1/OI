#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 500005;

int n, cnt;
long long ans;
int height[maxn];
int q[maxn];
int time[maxn];

inline void push(int val)
{
	q[cnt++] = val;
}

inline void pop()
{
	--cnt;
}

inline bool empty()
{
	return (cnt == 0);
}

int main()
{
	cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		while(cnt != 0 && q[cnt - 1] < t) {
			// �����һ��С����һ��
			// ��ô��һ���ܹ�����ȫ��֮ǰ��
			// Ȼ�����ǰ��һ�� Ȼ���pop���� ֱ����һ�����Լ����
			ans += time[cnt - 1];
			pop();
		}
		if(cnt == 0) {
			// ���һ����û���� �ǾͰѵ�ǰ�ļӽ�ȥ
			push(t);
			time[cnt - 1] = 1;
		} else if(q[cnt - 1] == t) {
			// ���ǰһ���˺��Լ���ͬ
			// ��ǰһ�����ܹ��࿴��һ����
			// ��Ҳ++
			ans += time[cnt - 1];
			++time[cnt - 1];
			// ��һ��Ҳ�ܿ�����һ��qwq...
			if(cnt != 1) ++ans;
		} else {
			++ans;
			push(t);
			time[cnt - 1] = 1;
		}
	}
	cout << ans << endl;
}