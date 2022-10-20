#include <bits/stdc++.h>
using namespace std;


void solve(int k){
    int n; cin >>n; int aux;
    vector<int> tracks(n);
    for(int i =0;i<n;i++){
        cin >> tracks[i];
    }

    int max = 0, result = 0;
    for(int i = 0;i<(1<<n);i++){
        aux = 0;
        for(int j = 0;j<20;j++){
            if((1<<j)&i){
                aux+=tracks[j];
                // cout << tracks[i] <<" ";
            }
            // cout << bool((1<<j)&i) << " ";
            if(aux > k){
                // i+= (1<<j);
                break;
            }
        }
        // cout << "\n";
        
        if(max <= aux && aux <= k){max = aux; result = i;}
        // cout << aux <<"\n";
        // cout << "\n";

    }

    for(int k = 0;k<20;k++){
        if((1<<k)&result){
            cout << tracks[k] <<" ";
        }
    }
    cout << "sum:" << max << "\n";

}

int main() {
	int n;
    while(cin >> n){
        solve(n);
    }
}