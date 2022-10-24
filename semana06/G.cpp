#include <iostream>
#include <cmath>
#include <iomanip>
#define EPS 1e-4
using namespace std;
int p,q,r,s,t,u;

double eq(double x){
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x*x) + u); 
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


void solve(){
    double result = buscaBinariaContinua(0.0,1.0);
    if(fabs(eq(result)) <= EPS){
        cout << fixed << setprecision(4) << result << "\n";
    }else cout << "No solution\n";

}

int main(){
    while(cin >> p >> q >> r >> s >> t >> u){
        solve();
    }
}