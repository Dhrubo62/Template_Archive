/*
Name: Topological sort
Description: Task Scheduling Algorithm
Division: Graph Theory
*/

int n; // number of nodes
vector <int> graph[ MAX_N ]; // graph in adjacency list
vector <int> top; // for storing the sorted order
int ind[ MAX_N ]; // for storing indegrees of nodes

void top_sort()
{
    // clearing the sorted list vector
    top.clear();

    queue <int> q;
    for( int i=0; i<n; i++ ) if(!ind[i]) q.push(i); // taking the edges of zero indegree
    while( !q.empty() )
    {
        int u=q.front(); q.pop();
        top.push_back(u);

        for( int i=0; i<graph[u].size(); i++ ) // reducing indegree of all the tasks dependent on u
        {
            int v=graph[u][i];
            ind[v]--; // reducing the indegree
            if( !ind[v] ) top.push_back( v );
        }
    }
}

int main(void)
{
    // input dependencies as edges of the graph
    int u,v; cin>>u>>v;
    // if v is dependent on u
    graph[u].push_back(v);
    ind[v]++;
}
