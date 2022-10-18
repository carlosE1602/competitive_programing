#include <bits/stdc++.h>

using namespace std;

void solve(int k){
    vector<int> v(k);

    for(int i = 0;i<k;i++){
        cin >> v[i];
    }

    for(int i = 0;i<k-5;i++){
        for(int j = i+1;j<k-4;j++){
            for(int l = j+1;l<k-3;l++){
                for(int m = l+1;m<k-2;m++){
                    for(int n = m+1;n<k-1;n++){
                        for(int o = n+1;o<k;o++){
                            cout << v[i] << " " << v[j] << " " << v[l] << " " << v[m] << " " << v[n] << " " << v[o] << "\n"; 
                        }
                    }
                }
            }
        } 
    }
}

int main(){
    int n;
    int it = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        if(it != 0){
            cout << "\n";
        }
        solve(n);
        
        it++;
    }
    return 0;
}