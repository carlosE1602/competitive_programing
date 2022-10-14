#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
string aux;
bool solve(int n,int k){
    v.clear();
    for(int i =0;i<n;i++){
        cin >> aux;
        v.push_back(aux.size());
    }
    sort(v.begin(), v.end());
    int cont;
    double media;

    for(int i = 0;i<n;i+=k){
        cont = 0;
        for(int j = i;j<(i+k);j++){
            cont+=v[j];
        }

        media = cont/(k*1.0);

        for(int j = i;j<(i+k);j++){
            if(fabs(v[i]-media)-2 > 10e-9) return false;
        }
    }
    return true;
}

int main(){
    int a,b, i =1;
    while(true){
        cin >> a >> b;
        if(a+b == 0) break;
        else if(i!=1) cout << "\n";
        cout << "Case " << i++ << ": "; 
        if(solve(a,b)) cout << "yes\n";
        else cout << "no\n";
    }
}