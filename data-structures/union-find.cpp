#include <bits/stdc++.h>
using namespace std;

struct disjointset{
    vector<int> p, s; 
    
    disjointset(int n) : p(n + 1), s(n + 1){
        iota(p.begin(), p.end(), 0);
    }
    
    int find_set(int v){
        return (p[v] == v ? v : p[v] = find_set(p[v])); 
    }
    
    void union_set(int v, int q){
        v = find_set(v);
        q = find_set(q);
        if(v != q) {
            if(s[v] < s[q]) { 
                swap(v, q);
            }
            p[q] = v;
            s[v] += s[q];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
}
