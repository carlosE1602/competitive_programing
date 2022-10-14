#include <iostream>
int cont = 0;

void algo(int n){
    if(n==1){ cont+=3; return ;}
    for(int i = 0;i<3;i++) algo(n-1);
    cont+=4;
}
using namespace std;

void hanoi(int n, const string A,const string C,const string B){
    if(n == 1){
        cout << "Mova " << A << " para " << B <<"\n";
        cout << "Mova " << B << " para " << C <<"\n";
        return;
    }
    hanoi(n-1, A,C,B);
    cout << "Mova " << A << " para " << B <<"\n";
    hanoi(n-1, C,A,B);
    cout << "Mova " << A << " para " << B <<"\n";
    hanoi(n-1,A,C,B);
}
int main(){
    int n;
    cin >> n;
    hanoi(n, "A", "C", "B");
}