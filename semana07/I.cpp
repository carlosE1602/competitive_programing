#include <bits/stdc++.h>

using namespace std;

int tab[1010];

int n, p;

void solve(){
    memset(tab,0,sizeof(tab));
    cin >> n;
    for(int i = 0;i<n;i++){
        int valor, peso;
        cin >> valor >> peso;

        for(int j = 31; j >= peso; j--){
            tab[j] = max(tab[j], tab[j-peso]+valor);
            // cout << tab[j] << " ";
        }
        // cout << "\n";
        for(int i = 0;i<31;i++){
            cout << tab[i] << " ";
        }cout << "\n";

    }
    
    cin >> p;
    int total = 0;
    for(int i = 0;i<p;i++){
        int value; cin >> value;
        total += tab[value];
    }
   
    cout << total << "\n";

}

int main(){
    int n; cin >> n;
    while(n--) solve();
}