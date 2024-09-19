#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 1e9 + 7;
 
class modint {
private:
    int value;
    static int binexp(int base, int expo, int mod){
        int res = 1;
        while(expo) {
            if(expo & 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            expo >>= 1;
        }
        return res;
    }
 
public:
    modint(int v = 0) : value(v % MOD) {
        if(value < 0) {
            value += MOD;
        }
    }
 
    modint& operator = (int v) {
        value = v % MOD;
        if(value < 0) {
            value += MOD;
        }
        return *this;
    }
 
    modint operator + (const modint& other) const {
        return modint(value + other.value);
    }
 
    modint& operator += (const modint& other) {
        value = (value + other.value) % MOD;
        return *this;
    }
 
    modint operator - (const modint& other) const {
        return modint(value - other.value);
    }
 
    modint& operator -= (const modint& other) {
        value = (value - other.value + MOD) % MOD;
        return *this;
    }
 
    modint operator * (const modint& other) const {
        return modint((value * other.value) % MOD);
    }
 
    modint& operator *= (const modint& other) {
        value = (value * other.value) % MOD;
        return *this;
    }
 
    modint operator / (const modint& other) const {
        return *this * other.inv();
    }
 
    modint& operator /= (const modint& other) {
        *this *= other.inv();
        return *this;
    }
 
    modint inv() const {
        return modint(binexp(value, MOD - 2, MOD));
    }
 
    int get() const {
        return value;
    }
 
    friend ostream& operator << (ostream& os, const modint& mi) {
        os << mi.value;
        return os;
    }
 
    friend istream& operator >> (istream& is, modint& mi) {
        int v;
        is >> v;
        mi = v;
        return is;
    }
};
 
vector<modint> fatorial, inverso;
 
void precomputeFactorials(int T) {
    fatorial.resize(T);
    inverso.resize(T);
    fatorial[0] = fatorial[1] = 1;
    for(int i = 2; i < T; i++) {
        fatorial[i] = fatorial[i - 1] * i;
    }
    inverso[T - 1] = fatorial[T - 1].inv();
    for(int i = T - 1; i >= 1; i--) {
        inverso[i - 1] = inverso[i] * i;
    }
}
 
modint binomial(int a, int b) {
    if(b > a) {
        return 0;
    }
    return fatorial[a] * inverso[b] * inverso[a - b];
}
 
void work() {
    int a, b;
    cin >> a >> b;
    cout << binomial(a, b) << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    const int T = 2e6 + 1;
    precomputeFactorials(T);
 
    int t = 1;
    //cin >> t;
    while(t--) {
        work();
    }
}
