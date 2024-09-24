#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 26;

// Define o nó da trie
struct Node {
    Node* children[N];
    int count, prefixcount;

    // Construtor para inicializar o nó
    Node() {
        count = 0;
        prefixcount = 0;
        for(int i = 0; i < N; i++){
            children[i] = nullptr;
        }
    }
};

// Define a estrutura Trie que encapsula os nós e operações
struct Trie {
    Node* root;

    // Construtor para inicializar a Trie com uma raiz vazia
    Trie() {
        root = new Node();
    }

    // Função para inserir uma chave na trie
    void coloca(string &key){
        Node* current = root;
        for(auto &c : key){
            if(current->children[c - 'a'] == nullptr){
                current->children[c - 'a'] = new Node();
            }
            current = current->children[c - 'a'];
            current->prefixcount++;
        }
        current->count++;
    }

    // Função para deletar uma chave da trie
    bool deleta(string &key){
        Node* current = root;
        Node* lastword = nullptr;
        char lastchar = 'a';
        
        for (auto &c : key){
            if(current->children[c - 'a'] == nullptr){
                return false;  // Chave não encontrada
            }
            
            // Conta quantos filhos o nó atual possui
            int cnt = 0;
            for(int i = 0; i < N; i++){
                if(current->children[i] != nullptr){
                    cnt++;
                }
            }
            
            // Se tiver mais de um filho, armazena o nó e o caractere
            if(cnt > 1){
                lastword = current;
                lastchar = c;
            }
            current = current->children[c - 'a'];
        }

        // Verifica se o nó atual possui filhos
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(current->children[i] != nullptr){
                cnt++;
            }
        }

        // Se o nó atual ainda tiver filhos, apenas diminui o contador
        if(cnt > 0){
            current->count--;
            return true;
        }

        // Se não, desconecta o último caractere
        if(lastword != nullptr){
            lastword->children[lastchar - 'a'] = nullptr;
            return true;
        }

        // Caso especial: remove o primeiro caractere da palavra
        root->children[key[0] - 'a'] = nullptr;
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    Trie trie;  // Cria a trie
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        trie.coloca(s);  // Insere cada palavra na trie
    }
    
    while (q--){
        string s;
        cin >> s;
    }
}
