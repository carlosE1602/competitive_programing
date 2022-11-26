#include <bits/stdc++.h>

using namespace std;

bool verificaBipartido(vector<vector<int>> &adj, int v, int corAtual,vector<int> & cores){
    if(cores[v] != -1){ //se o vertice atual ja foi visitado
        if(cores[v] != corAtual) return false; //se ele esta com uma cor diferente da que eu quero marcar nao e bipartido
        return true; //ja esta colorido com a cor desejada
    }
    cores[v] = corAtual;
    for(auto i:adj[v]){
        int proximaCor = 1 - corAtual;
        bool nBipartido = verificaBipartido(adj,i,proximaCor,cores);
        if(!nBipartido) return false;
    }
    return true;
}

bool eBipartido(vector<vector<int>> &adj){
    vector<int> cores(adj.size(),-1);
    for(int i = 0;i < adj.size();i++){  //verifica se cada cc e bipartido, se for e um k33
        if(cores[i] != -1)continue;
        if(verificaBipartido(adj,i,0,cores)) return true;       //baste que um cc seja k33 pra ter uma garra no grafo
    }
    return false;
}

void solve(int n){
    int l; cin >> l;
    int e1,e2;

    vector<vector<int>> m(n);

    for(int i = 0;i<l;i++){
        cin >> e1 >> e2;

        m[e1].push_back(e2);
        m[e2].push_back(e1);

    }
    bool ehBipartido = true;
    int cores[n]; memset(cores,-1,sizeof(cores));

    for(int i = 0;i<n;i++){
        if(cores[i] == -1){
            if(eBipartido(m)){
                ehBipartido = false;
                break;
            }
        }
    }

    if(ehBipartido) cout << "NOT BICOLORABLE.\n";
    else cout << "BICOLORABLE.\n";
}

int main(){
    int n;
    while(true){cin >> n; if(n==0) break; solve(n);}
}