#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0;i<n;i++) cin >> v[i];
    int soma = 0;
    sort(v.begin(), v.end());
    int M = n/2;
    for(int i = 0;i<n;i++){
        soma += abs(v[M]-v[i]);
    }

    cout << soma << "\n";
}

int main(){
   int n;
    cin >> n;
   while(n){
        n--;

        solve();
   } 
}