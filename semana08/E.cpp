#include <bits/stdc++.h>

using namespace std;

int _a, _b, frente;

void solve(int n){
    vector<vector<int>> m(n);
    for(int i = 1;i<n;i++){
        cin >> _a >> _b;
        _a--; _b--;
        cout << _a << " " << _b << "\n";
        m[_a].push_back(_b);
        m[_b].push_back(_a);
    }
    cout << "fora\n";

    int t; cin >> t;
    cout << t << "\n";
    for(int i = 0;i<t;i++){
        cout << "Entra\n";
        t--;
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << a << " " << b << "\n";
        queue<int> fila;
        cout << "proximo\n";

        vector<int> vA(n,-1);
        vector<int> vb(n,-1);

        fila.push(a);
        vA[a] = 0;
        int dist = 0;
        while(!fila.empty()){
            frente = fila.front(); fila.pop();
            dist++;
            for(auto &i:m[frente]){
                vA[i] = dist;
                fila.push(i);
            }
        }

        for(auto &i:vA) cout << i << " ";
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