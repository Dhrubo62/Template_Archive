/*
Name: Rock Climbing
Purpose: Finding maximum profit when we can go only three ways in a grid thus cancelling
         the chance of a cycle
*/

int r,c; // row and column of the grid
int dp[ MAX_R ][ MAX_C ];
int grid[ MAX_R ][ MAX_C ];

int call( int i, int j )
{
    if( i<0 || i>=r || j<0 || j>=c ) return 0; // base case, gone out of grid
    if( dp[i][j] != -1 ) return dp[i][j];

    /* we will search the maximum possible profit from goint to three directions from this
    cell. the profit at this stage will be the maximum profit from next stages plus the
    value of this cell in the grid */

    int next=0; /* the values returned from next stages will be compared to this 0
    cause if a value is greater than 0 only then going to that stage is profitable */

    next = max( next, call( i+1, j ) );
    next = max( next, call( i+1, j+1 ) );
    next = max( next, call( i+1, j-1 ) );

    return dp[i][j] = next + grid[i][j];
}
