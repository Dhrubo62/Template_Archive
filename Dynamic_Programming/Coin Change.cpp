/*
Name: Coin Change
Purpose: Finding if an amount can be reached by taking from a set of values
Division: Dynamic Programming
*/



/* there can be two ways of doing this calculation
   1. starting from 0 and reaching that amount
   2. starting from that amount and reaching 0

   we should use the second one because it will be helpful if all the test cases
   have same set of coins. thus we wont need to clear the dp array at every test
   case
   */

int n; // number of different types of coins
int dp[ MAX_N ][ MAX_AMOUNT ]; // dp array
int coin[ MAX_N ]; // values of coins



/* if there is no limit on the use of the coins, each coin can be taken unlimitedly */
int call( int i, int amnt )
{
    // base case
    if( i==n ) // all coins have been used
    {
        if( amnt==0 ) return 1; // the amount can be reached
        else return 0;
    }

    if( dp[i][amnt]!=-1 ) return dp[i][amnt];

    /* we will measure the consequences of taking/not taking this coin at this stage */
    int take=0, not_take=0;

    // trying to take this coin at this stage
    if( amnt-coin[i] >= 0 ) take = call( i, amnt-coin[i] ); /* even after taking this coin
    we are going to the next stage with the same coint cause the coins can be used as many
    times as we wish
    if we want to see the case where we take this coin now but then go to the next coin, this call will
    happen at the next stage when we will skip this coin at that stage and move to the next coin */

    // skipping this coin
    not_take = call( i+1, amnt );

    dp[i][amnt] = take + not_take; // if we cant to calculate how many ways exist then this will be used
                                   // but if we want to know about the possibility only then we will use
                                   // dp[i][amnt]= max( take, not_take );
    return dp[i][amnt]; // returning the possibilities at this stage to the previous stage
}




/* if there is limit on use of coins */

int lim[ MAX_N ]; // limits of coins

int call( int i, int amnt )
{
    if( i==n ) return !amnt;
    if( dp[i][amnt]!=-1 ) return dp[i][amnt];

    /* as we definitely know how many times a coin can be used we will try to use to the limit
    as long as it does not break the capacity and the move to the next coin

    we will run a loop from 0 to the limit. the loop will start from 0, not 1. because doing so
    will include both not_taking the coin and taking the coin several times

    we will sum the possibilities for taking this coin several times */

    dp[i][amnt]=0;
    for( int times=0; times<=lim[i] && amnt-coin[i]*times>=0; times++ )
    {
        dp[i][amnt] += call( i+1, amnt-coin[i]*times );

        /* if we only want to see if possible or not then,
        1. !dp[i][amnt] should be added as a condition for the loop
        2. inside loop, dp[i][amnt] = max( dp[i][amnt], call( i+1, amnt-coin[i]*times ); */
    }
    return dp[i][amnt];
}
