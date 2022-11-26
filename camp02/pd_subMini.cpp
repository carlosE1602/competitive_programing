#include <bits/stdc++.h>

using namespace std;

int main(){
    int v[8] = {-4,-6,5,4,2,-4,9,2};


    // int mini = 0;
    int f[9]; f[0] = 0;

    for(int i = 0;i<8;i++){
        f[i+1] = min(f[i]+v[i], v[i]);
    }
    int minimo = f[1], idx = 1;
    for(int i = 2;i<9;i++) {
        // cout << f[i] << " ";
        if(minimo > f[i]){
            minimo = f[i];
            idx = i;
        }
    }
    // cout << "\n";
    cout << "\n\n";
    cout << idx << " " << minimo << "\n";
    cout << "\n\n";
    
    int id = idx-1; //id to v

    int aux = f[idx] - v[id];

    bool contido[8] = {0};
    contido[id] = true;

    while(idx >0 and aux == f[idx-1]){
        // cout << id+1 << "\n";
        contido[id-1] = true;
        idx--;id--; aux = f[idx] - v[id];
    }    

    for(int i = 0;i<8;i++){
        if(contido[i]){
            cout << v[i] << " ";
        }
    }
    cout << "\n";
}

//x é o vetor com n elementos
// SCSM(x,n):
//     F[9]
//     F[0] = 0

//     //relacao de recorrencia
//     for i = 0 until n-1 do:
//         F[i+1] = min(F[i], F[i]+x[i])

//     minimo = //menor valor de F, exceto o F[0]
//     idx = //indice de x com valor minimo

//     //conjunto dos elementos da menor subsequencia
//     contido = {x[idx]}

//     while F[idx] - x[idx] == F[idx-1]:
//         //adicona o x[idx] no conjunto dos contidos
//         contidos U {x[idx]}
//         idx--;

//     return contidos, minimo