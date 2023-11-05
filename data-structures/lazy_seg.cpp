#include <bits/stdc++.h>
using namespace std;

//segtree with lazy prop for sum queries

int la, lb, _new, n;
vector<int> seg, lazy, original;

int op(int a, int b){
    return a + b;
}

void build(int node = 1, int l = 1, int r = n){
    if(l == r){
        seg[node] = original[l];
    }
    else{
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node + 1, mid + 1, r);
        seg[node] = op(seg[2*node], seg[2*node + 1]);
    }
}

void prop(int node, int l, int r){
    if(!lazy[node]) return;
    seg[node] += (r - l + 1) * lazy[node]; //(r - l + 1) o "suficiente" para ser distribuido nos nós restantes, alterar a depender da operação 
    if(l != r){
        lazy[2*node] += lazy[node];
        lazy[2*node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

int query(int node = 1, int l = 1, int r = n){
    prop(node, l, r);
    if(l > lb || r < la) return 0;
    if(l >= la && r <= lb) return seg[node];
    int mid = (l + r) / 2;
    return op(query(2*node, l, mid), query(2*node + 1, mid + 1, r));
}

void update(int node = 1, int l = 1, int r = n){
    prop(node, l, r);
    if(l > lb || r < la) return;
    if(l >= la && r <= lb){
        lazy[node] += _new;
        prop(node, l, r);
    }
    else{
        int mid = (l + r) / 2;
        update(2*node, l, mid);
        update(2*node + 1, mid + 1, r);
        seg[node] = op(seg[2*node], seg[2*node + 1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> n >> c;
        lazy.assign(4*n + 1, 0);
        seg.assign(4*n + 1, 0);
        while(c--){
            int o;
            cin >> o;
            if(!o){
                cin >> la >> lb >> _new;
                update();
            }
            else{
                cin >> la >> lb;
                cout << query() << '\n';
            }
        }
    }

}
