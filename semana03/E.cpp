#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string &s){
    string sr(s.rbegin(), s.rend());
    // cout << s << " " << sr <<"\n";
    return sr == s;
}

void solve(){
    string s,s1,aux;
    long long int aux1, aux2;
    cin >> s;
    long long int cont = 0, soma;

    do{
        s1 = s;
        reverse(s.begin(), s.end());
        aux1 = stoi(s); aux2 = stoi(s1);
        soma = aux1+aux2;
        aux = to_string(soma);
        s = aux;

        cont++;

    }while(!isPalindrome(aux));

    cout << cont << " " << aux << "\n";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}