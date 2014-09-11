/*
Name: Dijkstra
Purpose: For finding shortest path in a weighted graph
Division: Graph Theory
*/

// a structure is needed to push nodes with low cost in priority
// queue
struct pack
{
    int node, cost;
    pack(int x, int y)  { node=x; cost=y; }

    // operator overloading for sorting in accending cost order
    bool operator < (const pack& obj)
    const
    {
        return obj.cost < cost;
    }
};

vector <int> graph[100],cost[100]; // adjacency list for wighted graph
int d[ MAX_N ];   // distance from Start will be stored in this array

int n; // number of nodes
int INF=A_VERY_BIG_NUMBER; // any very big value

int dijkstra(int Start,int End)
{
    // initializing the distances from Start
    for(int i=0; i<n; i++) dis[i] = INF;
    d[ Start ] = 0;

    // algorithm
    priority_queue <pack> q; // priority queue is used for getting vertices of low cost
    q.push( pack( Start, d[ Start ] ) );
    while( !q.empty() )
    {
        int u = q.top().node; q.pop();
        if( u==End ) break; /* as we are using a priority queue then nodes with lowest
        cost will be handled at this stage. so if a node reaches this stage then this
        node has no chance of being updated in the future. so we can stop the algorithm
        here */

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            int COST = cost[u][i];  // cost of going from u to v

            if( d[v] > d[u] + COST ) // relax
            {
                d[v] = d[u] + COST;
                q.push( pack( v, d[v] ) );
            }
        }
    }

    if( d[End]==INF ) return -1; // the End could not be reached
    return d[End];
}
