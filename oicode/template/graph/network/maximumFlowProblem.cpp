/* 
5 ��ʾ�ڵ���� ����1��Դ�� 5�ǻ��
6��ʾ�ߵĸ���( 
5 6
1 2 4
2 4 3
4 5 5
1 3 6
3 5 4
2 3 2
*/
#include <bits/stdc++.h>
using namespace std;
struct edge {
	int to, val, c = 0;
};
const int maxn = 1000;
const int inf = 1e9;
int past[maxn]; // ����ǰ���ڵ� 
vector<edge> graph[maxn]; // ͼ 
vector<edge> revgraph[maxn]; // �����ͼ revgraph[i] 
// ��ʾ��i�ĵ� 
int n, m;
void dfs(int val);
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int a, b, c, i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		edge curr;
		curr.to = b, edge.val = c;
		graph[a].push_back(curr);
		curr.to = a;
		revgraph[b].push_back(curr);
	}
	return 0;
}
void dfs(int val) {
	if(val == n) {
		
	} 
	int si = graph[val].size();
	for (int i = 0; i < si; ++i) {
		dfs(graph[val][i].to);
	}
} 
