#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, g, value;
    cin >> a >> g;
    int A[a];

    priority_queue<int, vector<int> , greater<int>> menores;
    priority_queue<int, vector<int> > maiores;


    for(int i =0;i<a;i++){
        cin >> A[i];
    }
    int inicio = 0;
    for(int j = 0;j<g;j++){
        cin >> value;
        for(int k = inicio;k<value;k++){
            menores.push(A[k]);
            if(!maiores.empty()){
                int m = maiores.top();
                int p = menores.top();
                if(m > p){
                    maiores.push(p);
                    menores.push(m);
                    maiores.pop();
                    menores.pop();
                }
            }
            
        }

        inicio = value;
        int aux = menores.top();
        cout << aux<< "\n";
        maiores.push(aux);
        menores.pop();

    }


}

int main(){
    int n;
    string aux;
    cin >> n;
    while(true){
        if(n == 0) break;
        getline(cin, aux);
        solve();
        if(n!=1) cout << "\n";
        n--;
        
    }
}