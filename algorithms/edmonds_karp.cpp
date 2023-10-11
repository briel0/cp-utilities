#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
vector<int> pai;
vector<vector<int>> cap;

//checa se existe caminho entre init e dest e devolve o menor custo nele
int reach(int init = 1, int dest = n){
  queue<int> fila;
  fila.push(init);
  int atual = LLONG_MAX;
  while(!fila.empty()){
    int node = fila.front();
    fila.pop();
    for(int i = 1; i <= n; i++){
      int cap_atual = cap[node][i];
      if(cap_atual <= 0 || pai[i] != -1){
        continue;
      }
      atual = min(atual, cap_atual);
	    pai[i] = node;
      if(i == n){
        return atual;
      }
      fila.push(i);
    }
  }
  return 0;
}
 
//atualiza o total enquanto há caminho
int cost(int init = 1, int dest = n){
  int total = 0;
  int atual;
  while(atual = reach()){
    int node = dest;
    while(node != init){
      cap[pai[node]][node] -= atual;
      cap[node][pai[node]] += atual;
      node = pai[node];
    }
    total += atual;
    pai.assign(n + 1, -1);
  }
  return total;
}
 
signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int m;
  cin >> n >> m;
  pai.assign(n + 1, -1);
  cap.assign(n + 1, vector<int>(n + 1, 0));
  
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    cap[a][b] += c;
  }
  
  cout << cost();
 
}
