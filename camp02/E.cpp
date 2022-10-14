#include <bitset>    // mais eficiente que vector<bool>!
#include <vector>
#include <set>
#include <iostream>
#define ll long long int
using namespace std;

ll _tam_crivo;       // ll definido com: typedef long long ll;
bitset<10000010> bs; // 10^7 + extra bits, suficiente para maioria
set<int> primos;  // lista de primos

void crivo(ll limite)
{                            // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset();
    bs.flip(); // todos valendo true
    bs.set(0, false);
    bs.set(1, false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++)
        if (bs.test((size_t)i))
        {
            // corta todos os multiplos de i comecando de i*i
            for (ll j = i * i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.insert((int)i); // adiciona na lista de primos
        }
}
int max_crivo = 10e7;
void solve(int n){
    if(n>max_crivo){
        crivo(n);
        max_crivo = n;
    }
    int i,j;
    auto it = primos.begin();
    while(*it < n){
        i = *it;
            // cout << *it << " " << n-i << "\n";
        if(primos.count(n-i) != 0){
            cout << n << " = " << *it << " + " << n-i << "\n";
            return;
        }
        it++;
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main(){
    crivo(1000000);
    int n;
    while(true){
        cin >> n;
        if(n==0)
            break;
        solve(n);
    }
}