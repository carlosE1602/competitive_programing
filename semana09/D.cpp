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
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
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
int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            bot = std::min(bot,cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for( int v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}
#include <iostream>
#include <vector>

void solve(){
    memset( cap, 0, sizeof( cap ) );
    int nPessoas;
    int totalAdesivos;
    std::cin >> nPessoas >> totalAdesivos;
    int last = nPessoas + totalAdesivos;
    int nAdesivos;
    // le os dados de BOB
    std:: cin >> nAdesivos;
    for(int i = 0;i<nAdesivos;i++){
        int aux;
        std::cin >> aux;
        cap[0][aux]++;
        cap[aux][last] = 1;
    }
    for(int i = 0;i<nPessoas-1;i++){
        // std:: cout << nAdesivos << "\n";
        std::cin >> nAdesivos;
        bool repetidos[totalAdesivos] ={false};
        for(int j = 0;j<nAdesivos;j++){
            int aux;
            std::cin >> aux;
            // std::cout << aux << " ";
            if(repetidos[aux-1]){ //pessoa i+1 tem o adesivo aux repetido, i.e pode troca-lo com alguem
                cap[totalAdesivos + i+1][aux]++;
            }else repetidos[aux-1] = true;
            // std::cout << aux << " " << last << "\n";
            cap[aux][last] = 1; //obriga que somente uma figurinha seja contada como diferente 
        }
        for(int j = 0;j<totalAdesivos;j++){
            // std::cout << repetidos[j] << " ";
            if(!repetidos[j]){  //se a pessoa i+1 nao tem a figurinha j+1, ela pode receber de alguem
                cap[j+1][totalAdesivos + i + 1] = 1;
            }
        }
        // std::cout << "\n";

    }
        
    // }




    int flow = fordFulkerson(last+1,0,last);

    std::cout << flow << "\n";
}

int main(){
    int nt;
    std::cin >> nt;
    for(int i = 0;i<nt;i++){
        std::cout << "Case #" << i+1 <<": ";
        solve();
    }
    return 0;
}