#include <bits/stdc++.h>
using namespace std;

string aux;

void solve(int n){
    map<string, int> m;
    int contTotal = 0;
    while(true){

        getline(cin, aux);
        if(aux == "") break;
        contTotal++;
        m[aux]++;

    } 
    for(auto &i:m) cout << i.first << " " << fixed << setprecision(4) << (i.second*1.0)/contTotal*100 << "\n";
    if(n!=0) cout << "\n";
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, aux);
    while(n--){
        solve(n);
    }
}