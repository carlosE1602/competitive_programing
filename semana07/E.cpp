#include <bits/stdc++.h>

using namespace std;

int m,c,k;
int preco [25][25];
bool tab [220][25];

void solve(){
    cin >> m >> c;
    for(int i =0;i<c;i++){
        cin >> preco[i][0];
        k = preco[i][0];
        for(int j =1;j<=k;j++){
            cin >> preco[i][j];
            // cout << preco[i][j] << "\n";
        }
    }
    // return;
    memset(tab,false,sizeof(tab));

    for(int i = 1;i<=preco[0][0];i++){
        tab[m-preco[0][i]][0] = true;
    }
    // for(int i = 0;i<c;i++) cout << preco[0][i] << " ";
    
    for(int j = 1;j<c;j++){
        for(int i = 0;i<m;i++){
            if(tab[i][j-1]){
                for(int l = 1;l<=preco[j][0];l++){
                    if(i - preco[j][l] >= 0)
                        tab[i-preco[j][l]][j] = true;
                }
            }
        }
    }


    int aux = 0;
    for(int i = 0;i<= m and !tab[i][c-1];i++) aux++;

    if(aux == m+1) cout << "no solution\n";
    else cout << m-aux << "\n";

}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}