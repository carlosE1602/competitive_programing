#include <bits/stdc++.h>
#include<string.h>
#include<stdio.h>

using namespace std;

void dfs(int id, vector<vector<int>> &m, bool visitados[]){
    visitados[id] = true;
    for(auto &vizinho:m[id]){
        if(!visitados[vizinho]){
            dfs(vizinho,m,visitados);
        }
    }

}

void solve(){
    string max;
    cin >> max;
    int n = max[0] - 'A' +1;
    // cin >> max;

    vector<vector<int>> m(n);
    string s;
    getline(cin,s);
    while(getline(cin,s)){
        
        if(s.size() == 0) break;
        
        m[s[0] - 'A'].push_back(s[1] - 'A');
        m[s[1] - 'A'].push_back(s[0] - 'A');

    }

    bool visitados[n] = {}; int cont = 0;

    for(int i = 0;i<n;i++){
        if(!visitados[i]){
            cont++;
            dfs(i,m,visitados);
        }
    }

    cout << cont << "\n";
}

int main(){
    int n; cin >> n;
    string aux;
    getline(cin,aux);
    while(n--){
        solve();
        if(n!=0) cout << "\n";
    }
    return 0;
}