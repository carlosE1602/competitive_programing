#include <bits/stdc++.h>

using namespace std;

void solve(string& s){

    stack<char> st;

    for(auto &c:s){
        if(c == '(' || c == '['){ st.push(c); continue;}
        if(!st.empty()){
            if( c == ']' and st.top() == '[') st.pop();
            else if( c == ')' and st.top() == '(') st.pop();
            
        }else if (c == ']' or c == ')'){cout << "No\n"; return;}
        
    }

    if(st.empty()) cout << "Yes\n";
    else cout << "No\n";


}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    for(int i = 0;i<n;i++){
        getline(cin,s);
        solve(s);
    }
}