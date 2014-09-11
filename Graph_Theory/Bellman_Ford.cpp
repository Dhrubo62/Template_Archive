/*
Name: Bellman-Ford
Description: Single source to all destination shortest path
             for a graph with negative weighted edges
Division: Graph Theory
*/

struct edge
{
    int u,v,c;
};
vector <edge> e;
int INF; // a very big number
int n; // number of nodes
int m; // number of edges
int d[ MAX_N ]; // cost of nodes from Start

void bellman_ford( int Start )
{
    // initialization
    for( int i=0; i<n; i++ ) d[i]=INF;
    d[Start] = 0;

    for( int i=0; i<n-1; i++ )
    {
        /*
        n-1 iterations have to be done because after each iteration the
        shortest path for at least one node is found and n-1 nodes are
        to be calculated for shortest path from Start
        */
        for( int j=0; j<m; j++ )
        {
            int u=e[j].u, v=e[j].v, c=e[j].c;
            if( d[u]!=INF && d[v]>d[u]+c ) // relax
            {
                d[v] = d[u] + c;
                /*
                d[u]!=INF check is compulsary to see if u has yet been visited
                from Start. cause there can be cases where u cant be visited
                from Start bt will relax the node v with a very low cost thus
                stopping the relaxation of v from any node reachabe from u
                that means causing bypass of original relaxation needed.
                */
            }
        }
    }

    // checking cycle
    /*
    after n-1 iterations all the nodes will have lowest cost from Start and thus
    it wont be possible to relax any of them anymore.
    This situation will not remain if there is a NEGATIVE WEIGHT CYCLE. so iterating
    one more time will detect the negative cycles in the graph
    */
    for( int i=0; i<m; i++ )
    {
        int u=e[i].u, v=e[i].v, c=e[i].c;
        if( d[u]!=INF && d[v]>d[u]+c ) // chance of relaxation
        {
            /*
            then u is a member of a negative cycle in the graph.
            it is u, not v cause the relaxation happens depending on u and in this
            case the d[u] had changed creating a chance of relaxation of all the nodes reachable
            from u. but the d[u] is not supposed to change at the first place.
            this proves that u is a member of a negative cycle in the graph

            so the cost for all the edges reachable from u can never be calculated
            optimally. in that case we have to mark these nodes by running a Flood-Fill DFS
            from u
            */
            if( !visit[u] ) dfs(u);
        }
    }
}
