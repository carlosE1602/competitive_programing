#include <iostream>

using namespace std;

int s,o;


int gcd(int a, int b){

    if(a<b){
        int t = a;
        a = b;
        b = t;
    }

    if(b == 0){
        return 0;
    }

    if(a%b == 0 or a/b >1) return 1;

    return 1 + gcd(b,a-b);

}

void solve(){
    int r = gcd(s,o);

    if(r%2 != 0) cout << "Stan wins\n";
    else cout << "Ollie wins\n";
}

int main(){
    while(cin >> s >> o){
        if(s+o == 0) break;
        solve();
    }
}