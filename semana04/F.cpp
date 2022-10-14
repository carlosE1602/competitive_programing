#include <bits/stdc++.h>

using namespace std;
#define lli long long int
void print(multiset<lli> m){
    for(auto &i:m) cout << i << " ";
    cout << "\n";
}

void solve(int k){
    multiset<lli> m;
    lli aux, nAux,cont = 0;
    while(k--){
        cin >> aux;
        for(int i = 0;i<aux;i++){
            cin >> nAux;
            m.insert(nAux);
        }
        // print(m);
        auto itMax = --m.end(), itMin = m.begin();
        
        cont+=abs(*itMax-*itMin);
        // m.erase(itMax--,m.end());
        m.erase(itMin);
        m.erase(itMax);
    }
    // for(auto &i:m) cont+=i;
    cout << cont << "\n";
}

int main(){
    int n;
    while(true){
        cin >> n;
        if(!n) break;
        solve(n);
    }
    return 0;
}