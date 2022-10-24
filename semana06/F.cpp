#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#define EPS 1e-5
using namespace std;

vector<int> v;
int t;

double eq(double x){
    double acc = 0;

    for(int i = 0;i<=t; i++){
        acc += (v[i]/pow((1.0+x),i));
        // cout << acc <<"\n";
    }
    return acc;
}

double buscaBinariaContinua(double lo, double hi) {
    for(int i=0;i<100;i++) { //mudar! podemos executar X iteracoes, parar quando distancia entre hi e lo for pequena, etc...
        double mid = lo + (hi-lo)/2;
        if(eq(mid) < 0) hi = mid;
        else lo = mid;
    }
    // cout << eq(1) << "\n";
    // cout << eq(0) << "\n";
    // cout << eq(0.7071) << "\n";
    return lo; 
}


void solve(int n){
    v.clear();v.resize(n+1);
    for(int i = 0;i<=n;i++) cin >> v[i];
    t = n;

    double result = buscaBinariaContinua(-1.0,10000);
    if(fabs(eq(result)) <= EPS){
        cout << fixed << setprecision(2) << result << "\n";
    }
    else{
        cout << "No\n";
    }
}

int main(){
    int n;
    while(true){
        cin >> n;
        if(!n) break;
        solve(n);
    }
}