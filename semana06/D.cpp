#include <bits/stdc++.h>

using namespace std;

#define ui unsigned int

ui L,U,N;

void solve(){
    ui ans = 0;

    for(int i = 31;i>=0;i--){
        
        //se o i-esimo bit já estiver ligado, não precisa ativar na solução
        if((1<<i)&N){
            //basta verificar se não ultrapassa o limite inferior
            if((ans + (1<<i)) <= L) ans|=(1<<i);
        }else{
            if((ans+(1<<i)) <= U){
                if(((ans + (1<<i)) | N) > (ans|N)){
                    ans |= 1<<i;
                }
            }
        }
    }
    cout << ans <<"\n";
}

int main(){
    while(cin >> N >> L >> U){
        solve();
    }
}
