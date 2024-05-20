#include <bits/stdc++.h>
using namespace std;

//1-INDEXED

int n;
vector<int> bit;

//PRA SOMAR VAI SUBTRAINDO O BIT MENOS SIGNIFICATIVO
int sum(int pos){
    int ans = 0;
    while(pos > 0){
        ans += bit[pos];
        pos -= pos & (-pos);
    }
    return ans;
}

//PRA ATUALIZAR VAI SOMANDO O BIT MENOS SIGNIFICATIVO
//NAO ESQUECER DE TIRAR O VALOR ANTIGO (O QUE NO CASO SERIA UM UPDATE COM O INVERSO DO ATUAL)
void update(int pos, int novo){
    while(pos <= n){
        bit[pos] += novo;
        pos += pos & (-pos);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    bit.resize(n + 1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        update(i, p);
    }
    
}
