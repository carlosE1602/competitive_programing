#include <bits/stdc++.h>
using namespace std;

int R,n;
double I,E;

/*A ideia é tracar o triangulo entre o centro C do circulo de fora
juntamente com o centro de dois circulos menores adjacentes c1, c2
o angulo c1Cc2 é de 2*pi/n, pois é possível colocar */

void solve(){
    double totalArea = M_PI*R*R;
    double r = R*(sin(M_PI/n))/(1 + sin(M_PI/n));
    double circles = n*(M_PI*r*r);

    double c_angulo = M_PI*(1.0*(n-2)/(2*n));
    double setor_circular = 0.5*(r*r*c_angulo);

    double triangulo = 0.5*(r*r/tan(M_PI/n));

    if(n==1){
        r = R;
        I = 0.0;
        E = 0.0;
    }else{
        I = 2*n*triangulo - 2*n*setor_circular;
        E = totalArea - circles - I;
    }
cout << fixed << setprecision(10) << r << " " << I << " " << E  << "\n";
}

int main(){
    while(cin >> R>> n){
        solve();
    }
}
