#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#define pi acos(-1.0)
#define maxn (100000 + 50)
#define Lowbit(x) (x & (-x))
using namespace std;
typedef long long int LLI;

int a[maxn];
int c[maxn];

void Update(int x,int change,int n) {
    while(x <= n) {
        cout << x << " depurando essa bosta " << Lowbit(x) << "\n";
        c[x] = c[x] + change;
        x = x + Lowbit(x);
    }
}

int Query(int l,int r) {
    int suml = 0,sumr = 0,nl = l - 1,nr = r;
    while(nr > 0) {
        sumr = sumr + c[nr];
        nr = nr - Lowbit(nr);
    }
    while(nl > 0) {
        suml = suml + c[nl];
        nl = nl - Lowbit(nl);
    }
    return sumr - suml;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int Case = 1; Case <= t; Case ++) {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        printf("Case %d:\n",Case);
        int n,q,sum = 0,temp;
        scanf("%d%d",&n,&q);
        for(int i = 1; i <= n; i ++) {
            scanf("%d",&temp);
            sum = sum + temp;
            a[i] = sum;
            c[i] = a[i] - a[i - Lowbit(i)];
        }
        for(int i = n; i >= 1; i --) {
            a[i] = a[i] - a[i - 1];
        }
        for(int i = 1; i <= q; i ++) {
            int Order,ii,jj;
            scanf("%d",&Order);
            if(Order == 1) {
                scanf("%d",&ii);
                Update(ii + 1,-a[ii + 1],n);
                printf("%d\n",a[ii + 1]);
                a[ii + 1] = 0;
            } else if(Order == 2) {
                scanf("%d%d",&ii,&jj);
                a[ii + 1] = a[ii + 1] + jj;
                Update(ii + 1,jj,n);
            } else {
                scanf("%d%d",&ii,&jj);
                printf("%d\n",Query(ii + 1,jj + 1));
            }

            for(int i = 1;i<=n;i++){
                cout << a[i] << " ";
            }
            cout << "\n";

            for(int i = 1;i<=n;i++){
                cout << c[i] << " ";
            }

            cout << "\n";
        }

    }
    return 0;
}