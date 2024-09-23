#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x : a){
        cin >> x;
    }
    int len = sqrt(n) + 1;
    vector<int> b(len);
    for(int i = 0; i < n; i++){
        b[i / len] += a[i];
    }
    while(q--){
        char op;
        cin >> op;
        if(op == '?'){
            int l, r, ans = 0;
            cin >> l >> r;
            l--, r--;
            int cl = l / len, cr = r / len;
            if(cl == cr){
                for(int i = l; i <= r; i++){
                    ans += a[i];
                }
            }
            else{
                for(int i = l, end = (cl + 1) * len - 1; i <= end; i++){
                    ans += a[i];
                }
                for(int i = cl + 1; i <= cr - 1; i++){
                    ans += b[i];
                }
                for(int i = cr * len; i <= r; i++){
                    ans += a[i];
                }
            }
            cout << ans << '\n';
        }
        else{
            int i, v;
            cin >> i >> v;
            i--;
            b[i / len] -= a[i];
            a[i] = v;
            b[i / len] += a[i];
        }
    }
}
