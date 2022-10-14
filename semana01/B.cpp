#include <bits/stdc++.h>

using namespace std;


void solve(int n,int b,int h, int w){
    vector<int> precosValidos;
    for(int i = 0;i<h;i++){
        int price;
        cin >> price;

        for(int j = 0;j<w;j++){
            int capacidade;
            cin >> capacidade;
            if( capacidade >= n && n*price <= b){
                precosValidos.push_back(price*n);
            }
        }
    }

    if(precosValidos.empty()) cout << "stay home\n";
    else{
        int min = precosValidos[0];

        for(auto &preco:precosValidos){
            if(min > preco) min = preco;
        }
        cout << min << "\n";
    }

    return;
}

int main(){
    int N,B,H,W;

    while(cin >> N >> B >> H >> W){
        solve(N,B,H,W);
    }
}