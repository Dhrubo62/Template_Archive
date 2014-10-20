/*
Name: Longest Increasing Subsequence
Division: Dynamic Programming
Purpose: From a given sequence, finding the largest sequence that is increasing
         by values of members but contains the original order between the members
*/

int n; // number of object in the main sequence
int dp[MAX]; bool visit[MAX];
int dir[MAX]; // here the path of the longest subsequence from different objects are
              // stored
              // if the next object to go from u to get the longest subsequence from u
              // is v then dir[u]=v
int longest( int u ) {
    if( visit[u] ) return dp[u];
    int maxi=0; // for storing the largest subesuence size 'after' u
    /* from u we want to go to v which is accessoible from u and holds
    the largest subsequence */
    for( int v=u+1; v<n; v++ ) {
        if( arr[v]>arr[u] ) { // checking increasing value
            if( longest(v)>maxi ) { // better than the existing size
                maxi = longest(v);
                dir[u]=v;
            }
        }
    }

    visit[u]=true;
    return dp[u] = maxi+1; // the length 'after' u, plus, u
}

void path( int u ) { // path printing
    cout << arr[u] << " ";
    while( dir[u]!=-1 ) {
        u = dir[u];
        cout << arr[u] << " ";
    }
}
