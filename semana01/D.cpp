#include <bits/stdc++.h>

using namespace std;

void solve(string &s){
    int cont = 0;
    // cout << s.size() << "\n";
    for(int i = 0;i<s.size();i++){
        for(int j = i+1;j<=s.size();j++){
            // cout << i << " " << j << "\n";
            string aux(s.begin() + i,s.begin()+j);
            string aux1 = aux;
            std::reverse(aux.begin(),aux.end());
            // cout << aux1 << " " << aux << "\n";
            if(aux != aux1 and aux.size() > cont) cont = aux.size();
        }
    }

    cout << cont << "\n";
}

int main(){
    string s;

    while(cin >> s){
        solve(s);
    }
}