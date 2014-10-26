/*
Name: Minimum Vertex Cover
Division: Graph Theory + Dynamic Programming
Purpose: Minimizing the size of the set of vertices such that each edge of the graph has at least
         one of it's endpoints in that set.
*/

int n,m;
vector <int> g[100];
int dp[100][2], visit[100][2], par[100]; // par is for keeping track from which vertex we have
                                         // come to the present one

int call( int u, int i ) {
    if( visit[u][i] ) return dp[u][i];

    int ttl=0; /* we want to calculate the number of selected vertices after u to the end of
               the graph depending on the selection state of the current vertex u */
    for( int j=0; j<g[u].size(); j++ ) {
        int v = g[u][j];
        if( par[u]!=v ) { // we dont want to go the vertice from where we have come to this one
            par[v] = u; // storing that we are going to v from u

            ttl += i? min( call(v,1), call(v,0) ) : call(v,1); /* if this vertex is not selected
            at this moment, then we must select all the vertices connected to this one.
            But if this vertex is selected then for the vertices connected to this one we will see
            which one of selecting or not selecting them is more benifitial */
        }
    }

    visit[u][i]=true;
    return dp[u][i]=ttl+i; // number of selected after u plus the selection state of u
}

int main() {

    // for a tree, the root is to be called once with selected state
    // and once with non selected state. the minimum of these two is the result
    int ans = min( call(1,0), call(1,1) );
}
