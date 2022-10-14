#include <bits/stdc++.h>

using namespace std;

void solve(int n,int k){
    int soma = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x; soma+=x;
    }
    int total = 0;
    while(true){
        if(round((soma+total*k)/double(n+total)) == k){
            cout << total << "\n";
            return;
        }else total++;
    }


}

int main(){
    int n, k;

    while(cin >> n >> k){
        solve(n,k);
    }
}