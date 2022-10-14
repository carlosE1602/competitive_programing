#include <bits/stdc++.h>

using namespace std;

void solve(string & a, string & b){
    auto it = a.rbegin();
    auto it1 = b.rbegin();
    int aux,aux1, cont = 0, resto = 0;

    while(it != a.rend() and it1 != b.rend()){
        aux = *it - '0';
        aux1 = *it1 - '0';

        // cout << aux << " " << aux1 << "\n";
        if(aux+aux1+resto >= 10) cont++;
        resto = (aux1+aux+resto)/10;
        it++; it1++;

    }
    if(it != a.rend()){
        while(it!= a.rend()){
            aux = *it - '0';
            if(aux+resto >= 10) cont++;
            resto = (aux+resto)/10;
            it++;
        }
    }else if(it1 != b.rend()){
        while(it1 != b.rend()){
            aux = *it1 - '0';

            if(aux+resto >= 10) cont++;
            resto = (aux+resto)/10;
            it1++;
        }
    }
    // if(resto == 1){
    //     if
    // }
    if(cont == 0) cout << "No ";
    else cout << cont << " ";

    cout << "carry operation";
    if(cont > 1) cout << "s.\n";
    else cout << ".\n";
}

int main(){
    string a,b;
    
    
    while(cin >> a >> b){
        if(a == "0" and b == "0") break;
        solve(a,b);
    }


}