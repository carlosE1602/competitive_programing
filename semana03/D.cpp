#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


void solve(){
    int n;
    cin >> n;

    int digitos[10] = {0};
    stringstream ss;
    string s = "";

    for(int i =1;i<=n;i++){
        s+=to_string(i);
    }


    for(int i = 0;i<s.size();i++){
        int pos = int(s[i])-'0';
        digitos[pos]++;
    }

    for(int i = 0;i<10;i++){
        cout << digitos[int(i)]; 
        if(i != 9) cout << " ";
    }

    cout << "\n";
}

int main(){
    int n;
    cin >> n;

    while(n--){
        solve();
    }
}