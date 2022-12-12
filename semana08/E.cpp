#include <bits/stdc++.h>

using namespace std;

int _a, _b, frente;

void solve(int n){
    vector<vector<int>> m(n);
    for(int i = 1;i<n;i++){
        cin >> _a >> _b;
        _a--; _b--;
        m[_a].push_back(_b);
        m[_b].push_back(_a);
    }

    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        queue<pair<int,int>> fila;

        vector<int> vA(n,-1);
        vector<int> vB(n,-1);

        fila.push({a,1});
        vA[a] = 0;
        while(!fila.empty()){
            auto frente = fila.front(); fila.pop();
            for(auto &i:m[frente.first]){
                if(vA[i] == -1){
                    vA[i] = frente.second;
                    fila.push({i,frente.second+1});

                }
            }
        }
        fila.push({b,1});
        vB[b] = 0;
        int in = -1, out = -1;
        bool ok = true;
        while(!fila.empty()){
            auto frente = fila.front(); fila.pop();
            if(vA[frente.first] == vB[frente.first]){
                cout << "The fleas meet at " << frente.first+1 << ".\n";
                ok = false;break;
            }
            if((vA[frente.first]-vB[frente.first] )== 1){
                cout << frente.first << "\n";
                if(in == -1) in = frente.first+1;
                else if(out == -1){out = frente.first+1;}
            }
            for(auto &i:m[frente.first]){
                if(vB[i] == -1){
                    vB[i] = frente.second;
                    fila.push({i,frente.second+1});

                }
            }
        }

        if(ok){

        cout << "The fleas jump forever between " << in << " " << out << ".\n";
        }
        for(auto &i:vA) cout << i << " ";
        cout << "\n";

        for(auto &i:vB) cout << i << " ";
        cout << "\n";
    }

}

int main(){
    int n;
    while(cin >> n){
        if(!n) break;
        solve(n);
    }

    return 0;
}