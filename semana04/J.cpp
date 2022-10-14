#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b){
    int aux;
    vector<int> u(a),v(b);

    for(int i = 0;i<a;i++){
        cin >> aux;
        u[i] = aux;
    }

    for(int i = 0;i<b;i++){
        cin >> aux;
        v[i] = aux;
    }

    // sort(u.begin(), u.end());
    // sort(v.begin(), v.end());

    int i = 0, j = 0,cont = 0;

    while(i < u.size() and j < v.size()){
        if(u[i] == v[j]) {i++; j++; cont++;}
        else if(u[i] < v[j]){i++;}
        else{j++;}
    }
    // cout << i << " " << j << "\n";
    // if(i!=u.size())cont+=(u.size()-i);
    // if(j!=v.size())cont+=(v.size()-j);
    cout << cont << "\n";
}

int main(){
    int n,m;
    // cin >> n;
    while(true){
        cin >> n >> m;
        if(n+m == 0) break;
        solve(n,m);
    }
}