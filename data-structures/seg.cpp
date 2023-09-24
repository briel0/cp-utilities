#include <bits/stdc++.h>
using namespace std;

//CONSULTA DE MENOR ELEMENTO EM UM INTERVALO

vector<int> original, seg;
int a, b;

void build(int node, int l, int r){
    if(l == r){
        seg[node] = original[l];
    }
    else{
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node + 1, mid + 1, r);
        seg[node] = min(seg[2*node], seg[2*node + 1]);
    }
}

int query(int node, int l, int r){
    if(l > b || r < a) return INT_MAX;
    if(l >= a && r <= b) return seg[node];
    int mid = (l + r) / 2;
    return min(query(2*node, l, mid), query(2*node + 1, mid + 1, r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    original.resize(n + 1);
    seg.resize(4*n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> original[i];
    }
    
    build(1, 1, n);
    
    while(q--){
        cin >> a >> b;
        cout << query(1, 1, n) << '\n';
    } 
    
}
/*
*/
