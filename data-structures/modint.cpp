#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

class modint{
private:
    int value;

    static int binexp(int base, int expo, int mod) {
        int res = 1;
        while(expo){
            if(expo & 1){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            expo >>= 1;
        }
        return res;
    }

public:

    modint(int v = 0) : value(v % MOD){
        if(value < 0){
            value += MOD;
        }
    }

    modint& operator = (int v){
        value = v % MOD;
        if(value < 0){
            value += MOD;
        }
        return *this;
    }

    modint operator + (const modint& other) const {
        return modint(value + other.value);
    }

    modint& operator += (const modint& other){
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

    modint operator ^ (int expo) const {  // Definindo potenciação
        return modint(binexp(value, expo, MOD));
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

void work() {
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        work();
    }
  
}
