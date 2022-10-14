#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, inversao = -1;
    cin >> n;
    vector<int> v;
    bool digits[10] = {0};
    bool flag = false;

    for(int i =0;i<n;i++){ cin>>x; v.push_back(x);}


    for(int i = n-2;i>=0;i--){
        if(v[i] < v[i+1]){inversao = i; break;}
    }

    if(inversao == -1){
        cout <<"-1"<<"\n";
        return;
    }

    int j;

    for(j=n-1;j>=0;j--){
        if(v[j] > v[inversao]) break;
    }


    swap(v[inversao],v[j]);
    sort(v.begin()+inversao+1,v.end());

    for(auto &i:v) cout << i;
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}