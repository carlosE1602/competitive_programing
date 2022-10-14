#include <bits/stdc++.h>
using namespace std;

long mdc(long p, long q, long &x, long &y)
{
    long x1,y1; /* coeficientes anteriores */
    long m; /* valor do mdc(p,q) */
    if (q > p) return mdc(q,p,y,x);
    if (q == 0) {
        x = 1;
        y = 0;
        return p;
    }
    m = mdc(q, p%q, x1, y1);
    x = y1;
    y = (x1 - floor(p/q)*y1);
    return m;
}

void solve(int n){
    long x,y,gcd;
    int c1,n1,c2,n2;
    cin >> c1 >> n1 >> c2 >> n2;
    gcd = mdc(n1,n2,x,y);
    cout << gcd << "\n";
    if(n%gcd != 0){ cout << "failed\n"; return;}

    long new_mdc = n/gcd;
    x *= new_mdc;
    y *= new_mdc; 
        cout << x << " " << y << "\n";
    
    // int i = 1;
    // while(x<0 or y<0){
    //     x += n2/gcd * i;
    //     y -= n1/gcd * i;
    //     cout << x << " " << y << "\n";
    //     i++;
    // }

    //     cout << x << " " << y << "\n";

}

int main(){
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        solve(n);
    }
}