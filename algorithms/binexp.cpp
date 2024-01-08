#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 1e9 + 7;
 
int binexp(int base, int expo){
    int res = 1;
    while(expo){
        if(expo & 1){
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        expo >>= 1;
    }
    return res;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
}
