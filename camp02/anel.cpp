#include <bits/stdc++.h>

using namespace std;
#define ll long long
set<int> primos;
int _tam_crivo = 100;
bitset<10000010> bs; // 10^7 + extra bits, suficiente para maioria


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

void geraPerm(bool usei[], int perm[], int k,int n){
    if(false){
        return;
    }
    if(k == n-1 and primos.count(perm[n-1] + perm[n]) != 0){
        

        for(int i = 0;i<n;i++){
            cout << perm[i];
            if(i != n-1) cout << " ";
        }cout << "\n";
        return;
    }
    for(int i = 2;i<=n;i++){
        if(!usei[i] and primos.count(perm[k]+i) != 0){
            usei[i] = true;
            perm[k+1] = i;
            geraPerm(usei,perm,k+1,n);
            usei[i] = false;
        }
    }
}

void solve(int n){
    int perm[1000];
    bool usei[1000];
    perm[0] = perm[n] = 1;
    // if(n == 1){
    //     cout << "1\n";
    //     return;
    // }
    geraPerm(usei,perm,0,n);
}

int main(){
    crivo(100);
    int n;
    int caso = 0;
    while(cin >> n){
        caso++;
        if(caso > 1) cout << "\n";
        cout << "Case " << caso << ":\n";
        solve(n);
    }

}