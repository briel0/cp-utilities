#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //declarando complexo (ponto)
    complex<double> p1 = {3, 1};
    complex<double> p2 = {2, 2};
    complex<double> sum = p1 + p2;
    
    //real -> X
    //imag -> Y
    cout << sum.real() << ' ' << sum.imag() << '\n';
    
    //tamanho do vetor
    cout << abs(p1) << '\n';
    
    //angulo em relação ao eixo X
    cout << arg(p2) << '\n';
    
    //produto vetorial
    complex<double> product = (conj(a)*b).imag();
    
}
