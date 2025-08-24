#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

struct Matrix {
    int rows, cols;
    vector<vector<int>> m;

    Matrix(int r, int c, bool identity = false) : rows(r), cols(c) {
        m.assign(r, vector<int>(c, 0));
        if (identity) {
            for (int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }

    // Operador de soma
    Matrix operator+(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.m[i][j] = (m[i][j] + other.m[i][j]) % MOD;
            }
        }
        return result;
    }

    // Operador de subtração
    Matrix operator-(const Matrix &other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.m[i][j] = (m[i][j] - other.m[i][j] + MOD) % MOD;
            }
        }
        return result;
    }

    // Operador de multiplicação
    Matrix operator*(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.m[i][j] = (result.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    // Exponenciação binária
    Matrix operator^(long long exp) const {
        Matrix base = *this;
        Matrix result(rows, cols, true); // identidade
        while (exp > 0) {
            if (exp & 1) {
                result = result * base;
            }
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;

        Matrix init(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> init.m[i][j];
            }
        }

        Matrix result = init ^ e;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << result.m[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
