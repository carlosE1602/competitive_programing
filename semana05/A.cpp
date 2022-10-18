#include <bits/stdc++.h>

using namespace std;

int ref(double x, int y){
    int aux = 1;

    while(aux*x <= y) aux++;
    return aux;
}

void solve(){
    int l,w, a;
    cin >> l >> w >> a;
    if(a == 0){cout << 1.000 << "\n"; return;}
    double radian = (M_PI/180.0) * a;

    // cout << radian << "\n";

    double step = w/tan(radian);
    double dist = w/sin(radian);

    // cout << step << " " << dist << "\n";


    // cout << dist << "\n";
    
    //qtd reflexoes
    int r = ref(step,l)-1;    
    // cout << step << " " << r << " " << "\n";
    //sobra sem refletir exato
    double resto = l - step*(r);

    // cout << "resto: " << resto  << " " << l - step*(r+1)<< "\n";
    // cout << "reflexoes " << r << "\n";
    double endPoint = 0;
    //pode ter resto em cima ou embaixo
    if((r+1)%2 == 0){
        // cout << "aqu\n";
        endPoint = w - resto*tan(radian);
    }
    else{
        endPoint = resto*tan(radian);
    }
    // cout << endPoint << "\n";
    double A = (r*dist)+(resto/cos(radian));
    double B = sqrt((endPoint*endPoint) + (l*l));
    // cout << A << " " << B << "\n";
    cout << fixed << setprecision(3) << A/B << "\n";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}
