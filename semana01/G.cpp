#include <bits/stdc++.h>

using namespace std;

void solve(int n){

    int cont[n+1];
    int values[n+1];
    memset(cont,0,sizeof(int)*(n+1));

    for(int i = 1;i<n+1;i++){
        cin >> values[i];
    }

    if(n == 1){cout << "Jolly\n"; return;}

    for(int i = 1;i<n;i++){
        int idx = abs(values[i]-values[i+1]);

        if(idx > n-1 or idx == 0){
            cout << "Not jolly\n";
            return;
        } 
        cont[idx]++;
    }

    for(int i = 1;i<n;i++){
        if(cont[i] != 1){
            cout << "Not jolly\n";
            return;
        }
    }

    cout << "Jolly\n";
}

int main(){
    int n;
    while(true){
        if(!(cin >> n)) break;
        solve(n);
    }
}