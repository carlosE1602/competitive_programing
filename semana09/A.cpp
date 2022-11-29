#include <bits/stdc++.h>

using namespace std;
// #define INF 9999999
int n,r;
int m[1000][1000];



int solve(){

    int a,b,peso;
    memset( m, 0, sizeof( m ) );
    // memset( dp,0 , sizeof( dp ) );

    for(int i = 0;i<r;i++){
        cin >> a >> b >> peso;
        // a--; b--;
        m[a][b] = peso;
        m[b][a] = peso;
    }


    // for(int i = 1;i<n+1;i++){
    //     for(int j = 1;j<n+1;j++)
    //         cout << m[i][j] << " ";
    //     cout << "\n";
    // }
    cin >> a >> b >> peso;
    
 
    // cout << a << " " << b <<"\n";
    n++;
    for(int k = 1;k<n;k++){
        for(int i = 1;i<n;i++)
            for(int j = 1;j<n;j++)
                m[i][j] = max(m[i][j], min(m[i][k], m[k][j]) );
    }
    int fluxo = m[a][b];
    
    // cout << fluxo << "\n";
    
    return (peso + fluxo-2) /(fluxo-1);
}

int main(){
    int t = 1;
    while(true){
        cin >> n >> r;
        // cout << n << r << "\n";
        if(n+r == 0) break;
        int result =  solve();

        cout << "Scenario #" << t++ << "\n";
        cout << "Minimum Number of Trips = " << result <<"\n";
        cout << "\n";
    }
    return 0;
}