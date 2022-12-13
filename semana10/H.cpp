#include <bits/stdc++.h>

using namespace std;

void solve(){
    string number;
    cin >> number;
    int soma = 0;
    int contMultiplo = 0;

    bool flag = false;

    for(auto c: number){
        int n = c - '0';
        soma += n;

        if(n % 3 == 0) contMultiplo++;
    }

    for(int i = 0;i<number.size();i++){
        int n = number[i] - '0';

        if((soma - n) % 3 == 0){
            flag = true;
        }
    }

    if(number.size() == 1){
        cout << 'S' << "\n";
        return;
    }
    if(soma % 3 == 0){
        contMultiplo % 2 == 0 ? cout << "T\n" : cout << "S\n";
    }else if(flag){
        contMultiplo % 2 == 0 ? cout << "S\n" : cout << "T\n";
    }else cout << "T\n"; 

}

int main(){
    int n; cin >> n;
    int t = 1;
    while(n--){
        cout << "Case " << t++ << ": ";
        solve();
    }
}