#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 26;

struct node{
    struct node* children[N];
    int count = 0, prefixcount = 0;
    node(){
        count = 0;
        prefixcount = 0;
        for(int i = 0; i < N; i++){
            children[i] = NULL;
        }
    }
};

void coloca(node* root, string &key){
    node* current = root;
    for(auto &c : key){
        if(current->children[c - 'a'] == NULL){
            node* novo = new node();
            current->children[c - 'a'] = novo;
        }
        current = current->children[c - 'a'];
        current->prefixcount++;
    }
    current->count++;
}

int prefixtem(node* root, string &key){
    node* current = root;
    for(auto &c : key){
        if(current->children[c - 'a'] == NULL){
            return 0;
        }
        current = current->children[c - 'a'];
    }
    return current->prefixcount;
}

bool wordtem(node* root, string &key){
    node* current = root;
    for(auto &c : key){
        if(current->children[c - 'a'] == NULL){
            return false;
        }
        current = current->children[c - 'a'];
    }
    return current->count > 0;
}

bool deleta(node* root, string &key){
    node* current = root;
    node* lastword = NULL;
    char lastchar = 'a';
    for(auto &c : key){
        if(current->children[c - 'a'] == NULL){
            return false;
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(current->children[i] != NULL){
                cnt++;
            }
        }
        if(cnt > 1){
            lastword = current;
            lastchar = c;
        }
        current = current->children[c - 'a'];
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(current->children[i] != NULL){
            cnt++;
        }
    }
    if(cnt > 0){
        current->count--;
        return true;
    }
    if(lastword != NULL){
        lastword->children[lastchar] = NULL;
        return true;
    }
    root->children[key[0]] = NULL;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    node* init = new node();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        coloca(init, s);
    }
    while(q--){
        string s;
        cin >> s;
        cout << prefixtem(init, s) << '\n';
    }
}
