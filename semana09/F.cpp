/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - prevv contains the minimum cut. If prevv[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <string.h>
#include<algorithm>

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prevv[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prevv, -1, sizeof( prevv ) );
        qf = qb = 0;
        prevv[q[qb++] = s] = -2;
        while( qb > qf && prevv[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prevv[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prevv[q[qb++] = v] = u;

        // see if we're done
        if( prevv[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prevv[v]; u >= 0; v = u, u = prevv[v] )
            bot = std::min(bot,cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for( int v = t, u = prevv[v]; u >= 0; v = u, u = prevv[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

#include<bits/stdc++.h>

using namespace std;
#define INF 9999999
int n, w; //number of machines and wires

void solve(){
    memset( cap, 0, sizeof( cap ) );
    int machine, cost;
    //modelar o grafo de forma a criar vertices auxiliares para cada maquina que pode ser destruida
    //com o custo de destruir, assim encontrar o corte minimo é encontrar o custo de desconectar a rede
    cap[0][n] = INF;
    cap[n-1][(2*n)-1] = INF;
    
    for(int i = 0;i<n-2;i++){
        cin >> machine >> cost; machine--;
        // cout << cost << "\n";
        cap[machine][n+machine] = cost;

    }

    int machine1;
    for(int i = 0;i<w;i++){
        cin >> machine >> machine1 >> cost;
        machine--; machine1--;
        cap[machine+n][machine1]  = cost;
        cap[machine1+n][machine] = cost;
       
    }
    cout << fordFulkerson(2*n, 0, (2*n)-1) << "\n";
}

int main(){
    while(cin >> n >> w){
        if(n+w == 0) break;

        solve();
    }

}