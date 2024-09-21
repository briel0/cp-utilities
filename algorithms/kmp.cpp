#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> kmp(string s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1, j = 0; i < n; i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //matching
    string s, t;
    cin >> s >> t;
    vector<int> pi = kmp(t + '$' + s);
    int ans = count(pi.begin(), pi.end(), t.size());
    cout << ans;
}
