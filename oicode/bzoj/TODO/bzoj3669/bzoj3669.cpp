/*
* by kriaeth 2018/1/13
* ���� ��������һ�����벻�����...
* spfa��̬�ӵ�...ò�ƻ�ͦ���ʵ�qwq
*/
// spfa��̬�ӵ�...
// status AC (Ϊɶû��ac��...
/*
��ſ�����ô�ܽ�
���˿���� Ȼ���ٿ�ʼд��...(�Ͼ��Լ���û��ʡѡ��ˮƽ
����ǳ���spfa�Ķ�̬�ӵ�����
��̬�ӵ�/�ߵ�ʱ�� ��������dist
ֱ��push��ǰ�ߵ�������Ͷ�...
�Ժ�Ӧ�ÿ��Զ�����...
++spfaɧ����
���� �����Ǹ��������ټӵ�
*/

#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>

namespace solve 
{
	const int maxn = 1e5 + 5;

	struct Edge 
	{
		int from, to, a, b;

		Edge(){}

		// Edge(int t, int a, int b) 
		// {
		// 	to = t, a = a, b = b;
		// }

		Edge(int f, int t, int ax, int bx) 
		{
			from = f, to = t, a = ax, b = bx;
		}

		bool operator < (const Edge (&e)) const
		{
			return a >= e.a;
		}
	};

	int n, m;
	int xi, yi, ai, bi;
	std::vector<Edge> edges[maxn];
	std::priority_queue<Edge> tempo;
	std::queue<int> proc;
	int dis[maxn];
	std::bitset<maxn> vis;

	int res = 1e9;

	template<typename T>
	inline T min(T a, T b) 
	{
		return a < b ? a : b;
	}

	template<typename T>
	inline T max(T a, T b)
	{
		return a < b ? b : a;
	}
	
	inline void read(int &val)
	{
		val = 0; char c = getchar();
		while(!isdigit(c)) c = getchar();
		while(isdigit(c)) {val = val * 10 + c - '0'; c = getchar();}
	}

	inline void addedge(int xi, int yi, int ai, int bi, bool add)
	{
		if(add)
		{
			edges[xi].push_back(Edge(xi, yi, ai, bi));
			edges[yi].push_back(Edge(yi, xi, ai, bi));
		}
		else {
		    Edge curr(xi, yi, ai, bi);
			tempo.push(curr);
		}
	}

	inline int spfa(const Edge (&e)) 
	{
		proc.push(e.from);
		proc.push(e.to);

		vis[e.from] = true;
		vis[e.to] = true;
        
		while(!proc.empty()) 
		{
			int curr = proc.front();
			proc.pop();
			vis[curr] = false;
			
			for (int i = edges[curr].size() - 1; i >= 0; --i) 
			{
				Edge tempo = edges[curr][i];
				if(max(dis[curr], tempo.b) < dis[tempo.to]) {
    				dis[tempo.to] = max(dis[curr], tempo.b);
    				if(!vis[tempo.to])
    				{
    					vis[tempo.to] = true;
    					proc.push(tempo.to);
    				}
				}
			}
		}
		return dis[n];
	}
	inline void init() 
	{
		for (register int i = 0; i < maxn; ++i) dis[i] = 1e9;
		read(n); read(m);
		for (register int i = 0; i < m; ++i) 
		{
			read(xi); read(yi); read(ai); read(bi);
			addedge(xi, yi, ai, bi, false);
		}
	}

	inline void solve()
	{
		init();
		proc.push(1);
		vis[1] = true;
		dis[1] = 0;
		while(!tempo.empty()) 
		{
			Edge curr = tempo.top();
			tempo.pop();
			addedge(curr.from, curr.to, curr.a, curr.b, true);
			res = min(res, spfa(curr) + curr.a);
		}
		if(res == 1e9) std::cout << -1 << std::endl;
		else std::cout << res << std::endl;
	}
}

int main() 
{
	solve::solve();	
}
