#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegmentTree{
    int n;
    vector<int> seg, lazy, original;

    SegmentTree(int size) : n(size){
        original.assign(n + 1, 0);
        seg.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    int op(int a, int b){
        return a + b;
    }

    void build(int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l == r){
            seg[node] = original[l];
        }
        else{
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            seg[node] = op(seg[2 * node], seg[2 * node + 1]);
        }
    }

    void prop(int node, int l, int r){
        if(!lazy[node]){
            return;
        }
        seg[node] += (r - l + 1) * lazy[node];
        if(l != r){
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    int query(int la, int lb, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        prop(node, l, r);
        if(l > lb || r < la){
            return 0;
        }
        if(l >= la && r <= lb){
            return seg[node];
        }
        int mid = (l + r) / 2;
        return op(query(la, lb, 2 * node, l, mid), query(la, lb, 2 * node + 1, mid + 1, r));
    }

    void update(int la, int lb, int _new, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        prop(node, l, r);
        if(l > lb || r < la){
            return;
        }
        if(l >= la && r <= lb){
            lazy[node] += _new;
            prop(node, l, r);
        }
        else{
            int mid = (l + r) / 2;
            update(la, lb, _new, 2 * node, l, mid);
            update(la, lb, _new, 2 * node + 1, mid + 1, r);
            seg[node] = op(seg[2 * node], seg[2 * node + 1]);
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    SegmentTree seg(n + 1);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l++;
            seg.update(l, r, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            l++;
            cout << seg.query(l, r) << '\n';
        }
    }
}
