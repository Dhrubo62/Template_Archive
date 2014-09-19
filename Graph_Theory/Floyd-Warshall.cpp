/*
Name: Floyd-Warshall Algorithm
Purpose: Shortest path between all pairs of vertices in a graph
Division: Graph Theory
*/

long long INF, n; // number of vertices

/* adjacency matrix is used to store and use the graph
initially cost of any node from itself is 0, and if a node J is
not accessible from a node I then g[i][j] = INF */
long long g[ MAX_N ][ MAX_N ];

/* storing the paths
next[i][j] will hold the node that is to be visited next to I in order
to get to J */
int next[ MAX_N ][ MAX_N ];

/* we take a node K and a pair of vertices I,J to see if going from I to J through K
is cheaper than the existing cost of going from I to J */
void floyd_warshall()
{
    for( int k=0; k<n; k++ ) {
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( g[i][k]!=INF && g[k][j]!=INF && g[i][j] > g[i][k] + g[k][j] ) {

                    g[i][j] = g[i][k] + g[k][j];

                    /*
                    Caution!!!
                    INF check for g[i][k] and g[k][j] must be given. This in not a part of the
                    logic of the algorithm. if INF is set to such a big value that adding anything
                    to INF ( e.g. ....... g[i][k] + g[k][j].......) might cross the limit of the variable
                    holding it, then this check must be done cause in these cases "g[i][k] + g[k][j]" would
                    cross the limit and produce a negative value which is less than g[i][j]
                    */

                    /* as we are going from i to j through k we have to go to k at first
                    so the next node to go from i for going to j is the same as that for going
                    to k */
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void path( int u, int v ) // for printing the path from u to v
{
    cout << u << " ";
    while( u!=v ) {
        u = next[u][v];
        cout << u << " ";
    }
    cout << endl;
}
