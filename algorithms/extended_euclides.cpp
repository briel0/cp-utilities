#include <bits/stdc++.h>
using namespace std;
#define int long long

int x, y, ans;
void exgcd(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        ans = a;
        return;
    }
    int xa, ya;
    exgcd(b, a % b);
    xa = y;
    ya = x - y * (a / b);
    x = xa;
    y = ya;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}
