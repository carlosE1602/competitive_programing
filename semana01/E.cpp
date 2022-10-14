#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<vector<int>> m(n);
    int capacidades[n];
    for( int i = 0;i<n;i++){
        cin >> capacidades[i];
    }

    for(int i = 0;i<n;i++){
        vector<int> aux;
        for(int j = 0;j<capacidades[i];j++){
            int x;
            cin >> x;
            aux.push_back(x);
        }
        m[i] = aux;
    }
    vector<int> tempos;
    int k = 0;
    for(auto &i:m){
        int soma = capacidades[k]*15;
        for(auto &j:i) soma+= 5*j;
        k++;
        tempos.push_back(soma);
    }

    int it = 0;

    for(int i = 0;i<tempos.size();i++){
        if( tempos[i] < tempos[it]) it = i;
    }

    cout << tempos[it] << "\n";
}


int main(){

    int n;

    cin >> n;

    solve(n);

}