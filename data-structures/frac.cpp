#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c;

struct frac {
    int numerador, denominador;

    frac(int n = 0, int d = 1) {
        if (d == 0) throw std::invalid_argument("Denominador não pode ser zero");
        int g = std::gcd(n, d);  // Simplificar a fração no construtor
        numerador = n / g;
        denominador = d / g;
        if (denominador < 0) {  // Garantir que o denominador seja positivo
            numerador = -numerador;
            denominador = -denominador;
        }
    }

    frac operator+(const frac& other) const {
        int n = numerador * other.denominador + other.numerador * denominador;
        int d = denominador * other.denominador;
        return frac(n, d);
    }

    frac operator-(const frac& other) const {
        int n = numerador * other.denominador - other.numerador * denominador;
        int d = denominador * other.denominador;
        return frac(n, d);
    }

    frac operator*(const frac& other) const {
        return frac(numerador * other.numerador, denominador * other.denominador);
    }

    frac operator/(const frac& other) const {
        return frac(numerador * other.denominador, denominador * other.numerador);
    }

    bool operator<(const frac& other) const {
        return numerador * other.denominador < other.numerador * denominador;
    }

    bool operator==(const frac& other) const {
        return numerador == other.numerador && denominador == other.denominador;
    }

    friend std::ostream& operator<<(std::ostream& os, const frac& f) {
        os << f.numerador << '/' << f.denominador;
        return os;
    }
};

void solve(){

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--)
        solve();

}
