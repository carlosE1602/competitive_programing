#include <bits/stdc++.h>
using namespace std;

void solve(){
    int M;
    cin >> M;
    int p1,p2;
    set<pair<int,int>> coords;
    while(true){
        cin >> p1 >> p2;
        if(p1== 0 and p2 == 0) break;
        coords.insert({p1,p2});
    }
    int L = 0;
    vector<pair<int,int>> result;
    bool nCobre = false;
    auto it = coords.begin();
    
    while(it != coords.end()){
        if(it->first > L){
            nCobre = true;
            break;
        }
        auto aux = it; 
        while(it->first <= L and it != coords.end()){
            if(it->second > aux->second){
                aux = it;
            }
            it++;
        }

        L = aux->second;
        result.push_back({aux->first,aux->second});

        if(L>=M){
            break;
        }

    }


    auto t = result.end();
    if(result.size() >= 1){
        t--;
        if(t->second < M){
            nCobre = true;
        }
    }



    if(nCobre){cout << "0\n"; return;}

    cout << result.size() << "\n";
    for(auto &i:result) cout << i.first  << " " << i.second << "\n";
}

int main(){

    int n; string s;
    cin >> n;
    while(n--){
        getline(cin,s);
        solve();
        if(n > 0)
            cout << "\n";

    }
}