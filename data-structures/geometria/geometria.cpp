#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tipo double
#define vetor ponto

struct ponto{
    tipo x, y;
    ponto() : x(0), y(0) {}
    ponto(tipo _x, tipo _y) : x(_x), y(_y) {}

    vetor operator + (vetor o){
        return vetor(x + o.x, y + o.y);
    }
    vetor operator - (vetor o){
        return vetor(x - o.x, y - o.y);
    }
    vetor operator * (tipo o){
        return vetor(x * o, y * o);
    }
    vetor operator / (tipo o){
        return vetor(x / o, y / o);
    }
    tipo operator * (vetor o){
        return x * o.x + y * o.y;
    }
    //NORMA (MODULO) do produto vetorial
    tipo operator ^ (vetor o){
        return x * o.y - y * o.x;
    }
};

bool ccw(vetor a, vetor b){
    return (a ^ b) >= 0;
}

tipo norma(vetor a){
    return sqrt(a.x * a.x + a.y * a.y);
}

tipo qnorma(vetor a){
    return a.x * a.x + a.y * a.y;
}

vetor tovec(ponto a, ponto b){
    return vetor(b.x - a.x, b.y - a.y);
}

vetor projection(ponto p, ponto p1, ponto p2){
    vetor base = tovec(p1, p2);
    double fator = (base * tovec(p1, p)) / qnorma(base);
    return p1 + base * fator;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}
