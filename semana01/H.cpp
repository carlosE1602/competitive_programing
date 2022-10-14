#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<int> v(n);
    cin >> v[0];

    int max = v[0], min = v[0];
    for(int i = 1;i<n;i++){
        cin >> v[i];
    }

    // v.push_back(v.front());
    int cont = 0;

    for(int i = 1;i<n-1;i++){
        if(v[i] < v[i+1] and v[i] < v[i-1]) cont++;
        else if(v[i] > v[i+1] and v[i] > v[i-1] ) cont++;
        // cout << v[i-1] << " " << v[i] << " " << v[i+1] << " " << cont << "\n";
    }

    if(v[0] > v[1] and v[0] > v[n-1] or (v[0] < v[1] and v[0] < v[n-1]) ) cont ++;
    if(v[n-1] > v[0] and v[n-1] > v[n-2] or (v[n-1] < v[0] and v[n-1] < v[n-2]) ) cont ++;

    cout << cont << "\n";
}

int main(){
    int n;

    while(true){
        cin >> n;
        if(!n) return 0;
        solve(n);
    }
}