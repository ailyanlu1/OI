#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct sd {
	int num, d; //�յ㣬����
};
const int inf = 0xfffffff;
sd mp[200005];
int layer[200005];//��¼����
vector<int>head[200005];
bool bfs(int u, int st)
{
	memset(layer, 0, sizeof(layer));
	queue<int>q;
	q.push(u);
	layer[u] = 1; //��Ϊ��һ��
	int now;

	while(!q.empty()) {
		now = q.front(); //ȡ���������еĵ�
		q.pop();

		for(int j = head[now].size() - 1; j >= 0; j--) {
			int order = head[now][j];
			int end = mp[order].num;

			if(!mp[order].d/*������ı�Ϊ0��û��������������*/ || layer[end]/*����Ѿ�����㣬����*/)
				continue;

			layer[end] = layer[now] + 1; //������1
			q.push(end);//�ѱ�ǵĵ�������
		}
	}

	return layer[st];//����յ��ܷ񵽴�
}
int dfs(int u, int mn, int t)
{
	if(u == t) return mn; //��������غϣ�����mn

	int ret = 0; //��¼���߹��ı�

	for(int i = head[u].size() - 1; i >= 0; i--) {
		int j = head[u][i]; //��¼���
		int end = mp[j].num; //��¼�յ�
		int now = mp[j].d; //��¼����

		if(!now/*����Ϊ0������*/ || layer[end] - 1 != layer[u]/*������һ��Ļ�������*/) continue;

		int tmp = dfs(end, min(now, mn - ret/*��¼��������Сֵ*/), t);

		if(!tmp/*����Ϊ0������*/) continue;

		mp[j].d -= tmp; /*����߼�*/
		mp[j ^ 1].d += tmp; /*����߼�*/
		ret += tmp; /*������*/

		if(ret == mn) return ret;
	}

	return ret;
}
int dinic(int u, int t)
{
	int ans = 0;

	while(bfs(u, t)) { //���յ��ܵ���ʱ
		ans += dfs(u, inf, t); //�𰸼�
	}

	return ans;
}
int main()
{
	int cnt = 0, m, n, s, t;
	scanf("%d%d%d%d", &m, &n, &s, &t);

	for(int u, v, w, i = 1; i <= n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		mp[cnt].num = v, mp[cnt].d = w; //���߱�ţ��յ�Ϊv������Ϊ����������������
		head[u].push_back(cnt++);//u�����Ϊcnt�ı� ����ʾu��v����������Ϊw �ñ߱��Ϊcnt
		mp[cnt].num = u, mp[cnt].d = 0; //��������
		head[v].push_back(cnt++);
	}

	printf("%d", dinic(s, t));
	return 0;
}
