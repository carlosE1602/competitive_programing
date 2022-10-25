#include<iostream>
#include<set>
#include<vector>

using namespace std;
#define lli long long int
int aux;
lli a,b,c,d;
lli cont = 0;

void solve(int n){
	set<lli> s;
	for(int i = 0;i<n;i++){
		cin >> aux;
		
		s.insert(aux);
	}
	vector<lli> v(s.rbegin(),s.rend());

	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i==j) continue;
			for(int k = j+1;k<n;k++){
				cont++;
				if(i==k or k == j) continue;

				d = v[i]; a=v[j]; b=v[k];
				// cout << 
				c = d-(a+b);
				if(a == c or b == c or d==c) continue;
				if(s.count(c)){
					cout << d << "\n";
					return;
				}
			}
		}
	}
	// cout << cont <<"\n";
	cout << "no solution\n";
}

int main(){
	int n;
	while(true){
		cin >> n;
		if(n == 0) break;
		solve(n);
	}	
	return 0;
}
