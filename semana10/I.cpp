#include <bits/stdc++.h> 

using namespace std;

int n,aux;

void solve(){
    int x = 0;

    for(int i = 0;i<n;i++){
        cin >> aux;

        x ^= aux;
    }

    if(x != 0) cout << "Yes\n";
    else cout << "No\n";
}

int main(){

    while(cin >> n){
        if(n == 0) break;

        solve();
    }
}