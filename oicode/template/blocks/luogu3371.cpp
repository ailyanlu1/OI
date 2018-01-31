/*
* by kriaeth
* status: AC
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
namespace solve
{
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
	for (c = read(), iosig = false; !isdigit(c); c = read()) 
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

// ��ǰȫ���Ƕ����Ż�
// ��������
const int maxn = 100005;

int n, m, block_num;
int op, x, y, k;
int block_size;
//-----------
struct valll
{
	int belong, val;

	valll(): belong(0), val(0) {}
};

valll vals[maxn]; // �±�ͳһ��1��ʼ

struct block
{
    // �ھۺܸ�...
	int l, r;
	int this_sum; // this_num ��Զ��ʾ��ǰ����ܺ�
	int t_sum; // t_sum ��Զ�ǵ�ǰ������ӵ�ֵ...
	block(): l(0), r(0), this_sum(0), t_sum(0) {}

	inline pair<int, int> get_range(int ql, int qr)
	{
		static pair<int, int> ret;
		if(ql >= l) 
		{
			if(ql <= r)
				ret.first = ql;
			else ret.first = 0;
		}
		else ret.first = l;
        
		if(qr <= r)
		{
			if(qr >= l)
				ret.second  = qr;
			else ret.second = 0;
		}
		else ret.second = r;
		return ret;
	}
	
    inline void init_this_sum()
    {
        this_sum = 0;
        for (int i = l; i <= r; ++i) 
            this_sum += vals[i].val;
    }
    
	inline long long get_sum(int ql, int qr)
	{
		// ��ȡ�������ڵ�һ�εĳ���
		// TODO
		pair<int, int> qwq = get_range(ql, qr);
		if(qwq.first == l && qwq.second == r) return this_sum;
		long long summ = 0;
		for (int i = qwq.first; i <= qwq.second; ++i) summ += vals[i].val;
		// cout << t_sum << endl;
		summ += (t_sum * (qwq.second - qwq.first + 1));
		return summ;
	}

	inline void modify_range(int ql, int qr, int k)
	{
		// ����ǰ����Ļ�..ֱ��ȫ�ӣ�������ǰ����Ļ����ͼ�һ�� 
		auto t = get_range(ql, qr);
		if(t.first == l && t.second == r) t_sum += k;
		else for (int i = t.first; i <= t.second; ++i) vals[i].val += k;
		this_sum += ((t.second - t.first + 1) * k);
		// lazy_tag.push(pair<pair<int, int>, int>(get_range(ql, qr), k));
	}
};
//-----------
block *blocks;

inline void init()
{
	read(n); read(m);
    block_size = int(sqrt(n));
	for (register int i = 1; i <= n; ++i) read(vals[i].val);
	// ��ʼ����Ҫ�Ŀ�ĸ���...����ʼ���鱾��, ���ö�̬����
	block_num = n % block_size == 0 ? n / block_size : n / block_size + 1;
	blocks = new block[block_num + 5];
	// ��ʼ��blocks�����Ҷ˵�
	int curr = 1;
	for (int i = 1 ; i <= block_num; ++i)
		blocks[i].l = curr, blocks[i].r = (curr += block_size) - 1;
	blocks[block_num].r = n;
	// ��������val���ڵ�blocks ���ҳ�ʼ��blocks�ڲ���ǰ׺�������sum����
	for (int i = 1; i <= block_num; ++i)
	{
		for (int j = blocks[i].l; j <= blocks[i].r; ++j)
			vals[j].belong = i;
		blocks[i].init_this_sum();
	}
}

inline void modify_range(int ql, int qr, int k)
{
    for (int i = vals[ql].belong; i <= vals[qr].belong; ++i)
		blocks[i].modify_range(ql, qr, k);
}

inline long long get_sum(int ql, int qr)
{
    long long summ = 0;
    for (int i = vals[ql].belong; i <= vals[qr].belong; ++i)
		summ += blocks[i].get_sum(ql, qr);
	return summ;
}
inline void solve()
{
    init();
	for (int i = 0; i < m; ++i)
	{
		read(op); read(x); read(y);
		if(op == 1)
		{
			read(k);
			modify_range(x, y, k);
		}
		if(op == 2)
			std::printf("%lld\n", get_sum(x, y));
	}
	
}
}

int main()
{
	solve::solve();
	return 0;
}