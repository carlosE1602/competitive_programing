#include <bits/stdc++.h>

using namespace std;

#define ll long long int
ll m[1000][1000];
int n;

void solve(){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin >> m[i][j];
    
    vector<ll> v(n+5);
    vector<ll> r(n+5);


    bool visitados[n] ={};

    int aux;
    for(int i =0;i<n;i++){
        cin >> aux;
        v[i] = aux-1;
    }
    
    for(int k = n-1;k>=0;k--){
        int pos = v[k];
        ll soma = 0;

        visitados[pos] = true;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++){
                m[i][j] = min(m[i][j],m[i][pos]+m[pos][j]);
                if(!visitados[i] or !visitados[j]) continue;
                soma+=m[i][j];
            }
        r[k] = soma;
    }

    for(int i = 0;i<n;i++){
        cout << r[i];
        if(i != n-1) cout << " ";
        // else cout << "\n";
    }
}


int main(){
    cin >> n;
    solve();
}

