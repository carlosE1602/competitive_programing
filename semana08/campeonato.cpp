#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        vector<int> v(a);
        for(int i = 0;i<a;i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << 2*(v[a-1] - v[0]) << "\n";
    }
}