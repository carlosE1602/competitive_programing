#include <iostream>
#include<string.h> //memset
using namespace std;

void solve(int pedidos[][2], int n){
    // cout << "teste\n";
    int combinacao;
    bool satisfaz = true;

    // for(int j = 0;j<n;j++){
    //         cout << pedidos[j][1] << " " << pedidos[j][0] << "\n";

    // }

    for(int i = 0;i< (1<<16);i++){
        satisfaz = true;
        for(int j = 0;j<n;j++){
            if((pedidos[j][1]&i) || (pedidos[j][0]&(~i))) continue;
            else{
                // cout << "nao satisfez o cliente " << i << "\n";
                satisfaz = false;
                break;
            }
        }
        if(satisfaz){
            combinacao = i;
            break;
        }
    }
    // cout << combinacao <<" \n";
    if(!satisfaz){
        cout << "No pizza can satisfy these requests.\n";
        return;
    }
    cout << "Toppings: ";
    for(int i = 0;i<16;i++){
        if(combinacao & (1<<i)){
            cout << char('A' + i);
        }
    }
    cout << "\n";


}

int main(){
    string s;
    int n = 0;
    int pedidos [12][2] = {0}; // 0 = não deve incluir 1 = deve incluir
    while(cin >> s){
        if(s[0] == '.'){
            solve(pedidos, n);
            n = 0;
            // memset(pedidos, 0, sizeof(int)*12);
            for(int i = 0;i<12;i++){pedidos[i][0] = 0; pedidos[i][1] = 0;}
            continue;
        }
        for(int i = 0;s[i] != ';';i+=2){
            int pos = s[i+1] - 'A';
            // cout << (1<<pos) <<" ";
            if(s[i] == '+'){
                pedidos[n][1] |= (1<<pos);
            }
            else{
                pedidos[n][0] |= (1<<pos);

            }
        }
        n++;
    }

    // solve(4);
}