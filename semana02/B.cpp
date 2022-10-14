// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

void solve(int n){
    string s;
    cin >> s;

    int cont[100] = {0};
    int leitos[100]= {0};

    int sairam = 0;
    // cout << s << "\n";
    for(int i = 0;i<s.size();i++){
        int pos = s[i] - 'A';
        // cout << c << "\n";
        //nao tem ngm na posição
        if(cont[pos] == 0){
            cont[pos] = 1;
            if(n > 0){
                n--;
                leitos[pos] = 1;
            }else{
                sairam++;
            }
        }else{
            if(leitos[pos]) n++;
        }
    }
    if(sairam == 0){
        cout << "All customers tanned successfully.\n";
    }else{
        cout << sairam << " customer(s) walked away.\n";
    }
}   

int main(){
    int n;

    while(true){
        cin >> n;
        if(!n) return 0;
        solve(n);
    }
}