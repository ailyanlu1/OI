#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
namespace BST {
    const int maxn = 1e5 + 5;
    struct node {
        int val, lson, rson, father, size, rtag; // remove tag
        node() : val(0), lson(0), rson(0), father(0), size(0) {}
    };
    node t[maxn];
    vector<int> templ;
    int cnt = 1, root = 1;
    inline void print(int k, bool typ) {
        if (t[k].lson) print(t[k].lson, typ);
        if (!typ) cout << t[k].val << " ";
        else templ.push_back(t[k].val);
        if (t[k].rson) print(t[k].rson, typ);
    }
    inline void pushup(int k) {
        t[k].size = t[t[k].lson].size + t[t[k].rson].size + 1;
    }
    inline void insert(int k, int val) {
        // root -> k = 0
        if (cnt == 1) {
            t[cnt++].val = val; t[cnt].size = 1; t[cnt].father = 0;
            pushup(k); return;
        }
        node &curr = t[k];
        bool uselson = val <= curr.val;
        if (val <= curr.val) {
            if (curr.lson == 0) {
                t[cnt].val = val;
                curr.lson = cnt;
                t[cnt].father = k;
                t[cnt].size = 1;
                ++cnt;
            } else insert(curr.lson, val);
        } else {
            if (curr.rson == 0) {
                t[cnt].val = val;
                curr.rson = cnt;
                t[cnt].father = k;
                t[cnt].size = 1;
                ++cnt;
            } else insert(curr.rson, val);
        }
        pushup(k);
    }
    inline void subreb(int &k, int l, int r) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        k = ++cnt;
        t[k].val = templ[mid];
        subreb(t[k].lson, l, mid - 1);
        subreb(t[k].rson, mid + 1, r);
        t[t[k].lson].father = t[t[k].rson].father = k; // TODO
        pushup(k);
    }

    inline void rebuild(int k) {
        templ.clear();
        print(k, true); // ????????????????lst(???)
        subreb(k, 0, templ.size() - 1);
    }
    inline int find(int k, int val) {
        if(t[k].val == val) return k;
        if(val <= t[k].val && t[k].lson) return find(t[k].lson, val);
        else if(t[k].rson) return find(t[k].rson, val);
    }
    inline int getkth(int k, int val) {
        // by LittleRewriter
        if(t[t[k].lson].size + 1 == val) return t[k].val;
        else if(t[k].lson && val <= t[t[k].lson].size) return getkth(t[k].lson, val);
        else if(t[k].rson && val >= t[t[k].lson].size + 2) return getkth(t[k].rson, val - t[t[k].lson].size - 1);
    }
}

int main() {
    using namespace BST;
    int n;
    cin >> n;
    for (int k, i = 0; i < n; ++i) {
        cin >> k;
        insert(root, k);
    }
    for (int i = 1; i < cnt; ++i) {
        cout << t[t[i].father].val << " " <<t[i].size << " " << t[i].val << endl;
    }
    // cout << getrank(root, 3) << endl;
    print(root, false);
    cout << endl;
    cout << getkth(root, 3) << endl;
}
/*
5
2 8 9 6 4
*/
