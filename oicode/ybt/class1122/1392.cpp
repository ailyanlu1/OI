#include <bits/stdc++.h>
using namespace std;
struct edge {
	int x, y, value;
	bool operator < (const edge (&a)) const {
		return this->value < a.value;
	}
} p[90005];
int father[90005];
inline int find(int v) {
	if(father[v] != v) father[v] = find(father[v]);

	return father[v];
}
inline void unionn(int a, int b) {
	int r1 = find(a), r2 = find(b);
	father[r1] = r2;
}
int main() {
	memset(father, 0, sizeof(father));
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k, tot = 0;
	cin >> n >> k;

	for(register int i = 0; i <= n; ++i) {
		father[i] = i;
	}

	for (register int rp = 0; rp < k; ++rp) {
		cin >> p[rp].x >> p[rp].y >> p[rp].value;
	}

	sort(p, p + k);
	int maxn = 0, times = 0;

	for(register int i = 0; i < k; ++i) {
		if(find(p[i].x) != find(p[i].y)) {
			maxn = max(p[i].value, maxn);
			unionn(p[i].x, p[i].y);
			++times;
		}
	}

	cout << times << " " << maxn << endl;
	return 0;
}