#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,aux;
    cin >> a >> b;
    vector<int> u(a),v(b);

    for(int i = 0;i<a;i++){
        cin >> aux;
        u[i] = aux;
    }

    for(int i = 0;i<b;i++){
        cin >> aux;
        v[i] = aux;
    }

    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    int i = 0, j = 0,cont = 0;

    while(i < u.size() and j < v.size()){
        if(u[i] == v[j]) {i++; j++;}
        else if(u[i] < v[j]){cont++; i++;}
        else{cont++; j++;}
    }
    // cout << i << " " << j << "\n";
    if(i!=u.size())cont+=(u.size()-i);
    if(j!=v.size())cont+=(v.size()-j);
    cout << cont << "\n";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}