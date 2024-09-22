#include <bits/stdc++.h>
using namespace std;
#define int long long

int combina(int a, int b){
    return a + b;
}

struct SegmentTree {
    vector<int> original, seg;
    int n;

    SegmentTree(int size) : original(size + 1), seg(4 * size + 1){
        n = size;
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
            seg[node] = combina(seg[2 * node], seg[2 * node + 1]);
        }
    }

    void update(int idx, int _new, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l == r){
            seg[node] = _new;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid){
            update(idx, _new, 2 * node, l, mid);
        }
        else{
            update(idx, _new, 2 * node + 1, mid + 1, r);
        }
        seg[node] = combina(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int a, int b, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l > b || r < a){
            return 0;
        }
        if(l >= a && r <= b){
            return seg[node];
        }
        int mid = (l + r) / 2;
        return combina(query(a, b, 2 * node, l, mid), query(a, b, 2 * node + 1, mid + 1, r));
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    SegmentTree seg(n);
    
}
