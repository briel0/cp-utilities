#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> z(string s){
    int n = s.size();
    vector<int> ans(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(i < r){
            ans[i] = min(r - i, ans[i - l]);
        }
        while(i + ans[i] < n && s[ans[i]] == s[i + ans[i]]){
            ans[i]++;
        }
        if(i + ans[i] > r){
            l = i;
            r = i + ans[i];
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> control = z(s);
    
}
