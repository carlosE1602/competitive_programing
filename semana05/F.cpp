#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> pecas;
pair<int,int> inicio, fim;
bool hasSolution = false;

bool geraArranjo(pair<int,int> curr,bool c[], int n, int k, int curr_pos,int dir){
    if(k > n){return false;}
    if(k==n){
        int compara = dir == 0 ? pecas[curr_pos].second: pecas[curr_pos].first;
        if(compara == fim.first){return true;}
        return false;
    }
    for(int i = 0;i<pecas.size();i++){
        if(!c[i]){//nao foi usada
            if(pecas[i].first == curr.second){//se pode ser colocada nessa posicao
                c[i] = true;
                if(geraArranjo(make_pair(pecas[i].first,pecas[i].second),c,n,k+1, i,0)){return true;}
                c[i] = false;

            }else if(pecas[i].second == curr.second){//se pode ser colocada na posicao flipada

                c[i] = true;
                if(geraArranjo(make_pair(pecas[i].second,pecas[i].first),c,n,k+1,i,1)){return true;};
                c[i] = false;
            }
        }
    }
    return false;
}

void solve(int n, int m){
    cin >> inicio.first >> inicio.second;
    cin >> fim.first >> fim.second;

    pecas.clear(); pecas.resize(m);
    for(int i =0;i<m;i++){
        cin >> pecas[i].first >> pecas[i].second;
    }
    bool usados[1000] = {0};

    bool solution = geraArranjo(make_pair(inicio.first,inicio.second),usados,n,0,-1,0); 
    if(solution) cout << "YES\n";
    else cout << "NO\n";   
}

int main(){
    int n,m;
    while(true){
        cin >> n;
        if(n == 0) break;
        cin >> m;
        solve(n,m);
    }
    return 0;
}