#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<int> numbers(n);
    for(int i =0;i<n;i++){
        cin >> numbers[i];
    }

    int q; cin >> q; int sum;
    while(q--){
        cin >> sum;
        int aux = numbers[0] + numbers[1];
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(abs(numbers[i]+numbers[j] - sum) < fabs(aux - sum)){
                    aux = numbers[i] + numbers[j];
                }
            }
        }
        cout << "Closest sum to " << sum << " is " << aux << ".\n";
    }

}

int main(){
    int n;
    int i =1;
    while(true){
        cin >> n;
        if(!n) break;
        cout << "Case " << i++ <<":\n";
        solve(n);
        
    }

    return 0;
}
