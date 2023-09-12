#include <bits/stdc++.h>
using namespace std;

int p[] //parenting
int s[] // size of sets

int find_set(int v){
    if(p[v] == v){
        return v;
    }
    return p[v] = find_set(p[v]); 
    //reconstruindo a árvore de forma a "subir mais rápido"
}

void union_set(int v, int q){
    v = find_set(v);
    q = find_set(q);
    if(v != q){
        if(s[v] < s[q]){ // o v é o de maior tamanho
            swap(v, q);
        }
        //o parente do de menor tamanho se torna o de maior
        p[q] = v;
        s[v] += s[q];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
}
