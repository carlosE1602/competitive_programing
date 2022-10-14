#include <iostream>
#include <set>

using namespace std;

void solve(){
    int n, total;
    int aux, aux1, aux2;
    set<int> repetidos;
    cin >> n;
    aux1 = n;
    while(true){
        total = 0;
        while(aux1 != 0){
            // cout << aux1 << "\n";
            aux = aux1%10;
            total += (aux*aux);
            aux1 = aux1/10;
        }
        // cout << total << "\n";
        if(repetidos.count(total) != 0){
            cout << n << " is an Unhappy number.\n";
            break;
        }
        repetidos.insert(total);
        aux1 = total;
        // if(total == n){
        //     cout << n << "is an Unhappy number\n";
        //     break;
        // }
        if(total == 1){
            cout << n << " is a Happy number.\n";
            break;
        }
    }
}

int main(){
    int i = 1;
    int n;
    cin >> n;
    while(n--){
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
}