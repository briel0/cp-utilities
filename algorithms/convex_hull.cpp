#include <bits/stdc++.h>
using namespace std;
#define int long long

//ESSE CÓDIGO RETORNA OS INDEX DE CADA PONTO DO HULL
//ADAPTAR CONFORME A NECESSIDADE
//CUIDADO COM OS PONTOS COLINEARES
//;)

struct point{
    int x, y;
    point(){
        x = y = 0;
    }
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point outro) const {
    if(x != outro.x){
        return x < outro.x;
    }
        return y < outro.y;
    }
};

struct vec{
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) {}
};

vec tovec(const point &a, const point &b){
    return vec(b.x - a.x, b.y - a.y);
}

int cross(vec a, vec b){ 
    return (a.x * b.y) - (a.y * b.x);
}

bool ccw(point p, point q, point r){
    return cross(tovec(p, q), tovec(p, r)) >= 0;
}

vector<pair<int, point>> graham(vector<pair<int, point>> inicial){
    int n = inicial.size(), k = 0;
    vector<pair<int, point>> control(2 * n);

    sort(inicial.begin(), inicial.end(),
    [&](pair<int, point> a, pair<int, point> b){
        return a.second < b.second;
    });

    for(int i = 0; i < n; i++){
        auto &[_, ponto] = inicial[i];
        while(k >= 2 && !ccw(control[k - 2].second, control[k - 1].second, ponto)){
            k--;
        }
        control[k++] = inicial[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--){
        auto &[_, ponto] = inicial[i];
        while(k >= t && !ccw(control[k - 2].second, control[k - 1].second, ponto)){
            k--;
        }
        control[k++] = inicial[i];
    }
    control.resize(k);
    return control;
}

signed main(){
    int n;
    cin >> n;
    vector<pair<int, point>> initial;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        initial.push_back({i, point(x, y)});
    }
    vector<pair<int, point>> ans = graham(initial);
    set<int> res;
    for(auto &[idx, _] : ans){
        res.insert(idx);
    }
    for(auto &x : res){
        cout << x << ' ';
    }
}
