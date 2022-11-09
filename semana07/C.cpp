#include <bits/stdc++.h>

using namespace std;

string s1,s2;

int tab[1010][1010];


void solve(){
    memset(tab,0,sizeof(tab));
    
    int n = s1.size(), m = s2.size();
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                tab[i][j] = 1 + tab[i-1][j-1];
            }else{
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
            // cout << tab[i][j] << " ";
        } 
        // cout << "\n";
    }

    cout << tab[n][m] << "\n";

}

int main(){
    while(getline(cin,s1)){
        getline(cin,s2);
        solve();
    }
}