#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10010;

struct Node
{
    int id, degin, degout;
    bool operator < (const Node &other) const
    {
        if (degin != other.degin) return degin < other.degin;

        return degout > other.degout;
    }
};

vector<int> g[N];
//int g[N][N];
int n, m;
Node node[N];
bool vis[N];

void input();
int solve();
void dfs(int u);

int main()
{

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        input();
        printf("Case %d: %d\n", i, solve());
    }
    return 0;
}

void input()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) g[i].clear();
    //memset(g, 0x00, sizeof(g));

    for (int i = 1; i <= n; i++) {
        node[i].degin = node[i].degout = 0;
        node[i].id = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);;
        //g[b].push_back(a);
        //g[a][b] = 1;
        node[b].degin++;
        node[a].degout++;
        node[b].id = b;
    }
}


void dfs(int u)
{
    vis[u] = true;

    /*
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && g[u][v]) {
            dfs(v);
        }
    }
    */


    for (size_t i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }

}

int solve()
{
    int ans = 0;

    memset(vis, false, sizeof(vis));

    sort(&node[1], &node[n + 1]);

    /*
    for (int i = 1; i <= n; i++) {
        printf("%d:%d %d\n", node[i].id, node[i].degin, node[i].degout);
    }
    */


    for (int i = 1; i <= n; i++) {
        if (!vis[node[i].id]) {
            ans++;
            dfs(node[i].id);
        }
    }
    return ans;

}