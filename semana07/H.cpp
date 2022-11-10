#include <bits/stdc++.h>

using namespace std;

int tab[1000][1000], values[1000][1000];
int r,c;
int vizinhos[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};


void dp(int i,int j){
    if(tab[i][j] == 0){
        for(int k = 0;k<4;k++){
            int x = i + vizinhos[k][0], y = j + vizinhos[k][1];
            
            if(x >= 0 and x<r and   y>= 0 and y < c){

                if(values[i][j] > values[x][y]){
                    dp(x,y);
                    tab[i][j] = max(tab[i][j], tab[x][y]);

                } 
            }   
        }
        tab[i][j]++;
        
    }
}

void solve(){
    string name;
    cin >> name;
    cin >> r >> c;

    memset(tab,0,sizeof(tab));

    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
            cin >> values[i][j];

    
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++)
            dp(i,j);
    }

    int result = 0;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            result = max(result,tab[i][j]);
        }
    }
    cout << name << ": " << result << "\n";

}

int main(){
    int n; cin >> n;
    while(n--) solve();
}