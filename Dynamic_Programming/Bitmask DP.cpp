/*
Name: Bitmask DP
Division: Dynamic Programming
Purpose: Bitmask is needed where information about the last state is needed in the
         present state. Specially when a state is actually a boolean array that describes
         the active or inactive states of a set of objects which is being considered
         in the problem.
         As a boolean state array with 1's and 0's in different positions can be compared
         to a Binary Number, a number is passed as a state in a call.
*/

// functions used for bitmasking
int on( int num, int pos ) { return n | (1<<pos); } // for setting a bit to 1
int off( int num, int pos ) { return n & ~(1<<pos); } // for setting a bit to 0
bool see( int num, int pos ) { return (bool)( num & (1<<pos) ); } // for checking a bit

int n; // number of objects
int dp[ 1<<n ];
bool visit[ 1<<n ];

int call( int state ) {
    if( state==base ) return 0; /* this is an example of a basecase. cases may b different
    like if the starting case of dp is 1 in all bits "1111...." ( (1<<n)-1 ) then the base case may b
    0 in all bits "000...." ( 0 ) and vise varsa*/

    if( visit[state] ) return dp[state];

    // let's consider that something is to be minimized in the dp
    /* we will check in the state which objects have not been worked with yet. then we will
    work with each of them at this state and check the consequences of them and find where the
    thing we want to minimize is lowest for this present state.
    Suppose here a 0 in a position represents that object is still unused. */
    inf( low, int );
    for( int i=0; i<n; i++ ) {
        if( !see( state, i ) ) {
            int now; // let's do something with i and store the result of that work in 'now'
            low = min( low, now + call( on( state, i ) ) ); /* we are setting the bit i to 1
            so it means that i has been worked with and this information is passed as state
            in the next call; */
        }
    }

    visit[state]=true;
    return dp[state]=low;
}
