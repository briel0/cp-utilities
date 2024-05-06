#include <bits/stdc++.h>
using namespace std;

//defina a operação previamente
//RMQ nesse caso
int op(int a, int b){
    return min(a, b);
}

vector<int> original, seg;
int a, b, n, _new, idx; 
// a -> left, b-> right, _new-> novo valor, idx-> posicao

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

void update(int node = 1, int l = 1, int r = n){
    if(l == r){
        seg[node] = _new;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid){
        update(2*node, l, mid);
    }
    else{
        update(2*node + 1, mid + 1, r);
    }
    seg[node] = op(seg[2*node], seg[2*node + 1]);
}

int query(int node = 1, int l = 1, int r = n){
    if(l > b || r < a) return INT_MAX; //ELEMENTO NEUTRO
    if(l >= a && r <= b) return seg[node];
    int mid = (l + r) / 2;
    return op(query(2*node, l, mid), query(2*node + 1, mid + 1, r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> n >> q;
    
    original.resize(n + 1);
    seg.resize(4*n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> original[i];
    }
    
    build();
    
    while(q--){
        char o;
        cin >> o;
        if(o == 'U'){ //update
            cin >> idx >> value;
            update();
        } 
        else{ //query
            cin >> a >> b;
            cout << query() << '\n';
        }
    }
    
}
/*
*/
