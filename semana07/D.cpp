#include <bits/stdc++.h>

using namespace std;
    
int n;
int tab[1000][1000];
int aux;
void solve(){

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> aux;
            if(j > 0) aux += tab[i][j-1];
            if(i > 0) aux += tab[i-1][j];
            if(i > 0 and j > 0) aux-= tab[i-1][j-1];
            tab[i][j] = aux;
        }
    }

    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    int maxValue = -127*10000;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = i;k<n;k++){
                for(int l = j;l<n;l++){
                    aux = tab[k][l];
                    if(j > 0) aux -= tab[k][j-1];
                    if(i > 0) aux -= tab[i-1][l];
                    if(i > 0 and j > 0) aux+= tab[i-1][j-1];
                    maxValue = max(maxValue, aux);
                }
            }
        }
    }

    cout << maxValue << "\n";
}

int main(){
    while(cin >> n) solve();
}