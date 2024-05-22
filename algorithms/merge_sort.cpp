#include <bits/stdc++.h>
using namespace std;
#define int long long

int inversions;

void mergesort(vector<int> &atual){
    int n = atual.size();
    if(n == 1){
        return;
    }
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        auto &ref = (i < n / 2 ? a : b);
        ref.push_back(atual[i]);
    }
    mergesort(a);
    mergesort(b);
    int pa = 0, pb = 0, pt = 0;
    while(pa < a.size() && pb < b.size()){
        if(a[pa] <= b[pb]){
            atual[pt++] = a[pa++];
        }
        else{
            inversions += (a.size() - pa);
            atual[pt++] = b[pb++];
        }
    }
    while(pa < a.size()){
        atual[pt++] = a[pa++];
    }
    while(pb < b.size()){
        atual[pt++] = b[pb++];
    }
}

void work(){
    int n;
    cin >> n;
    inversions = 0;
    vector<int> control(n);
    for(int &x : control){
        cin >> x;
    }
    mergesort(control);
    cout << inversions << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        work();
    }
}
