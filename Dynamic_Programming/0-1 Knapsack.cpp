/*
Name: 0-1 Knapsack
Purpose: Maximizing profit within weight limit
Division: Dynamic Programming
*/

int n, cap; // number of items and the capacity of the sack
int val[ MAX_N ]; // profit values
int wgh[ MAX_N ]; // wights
int dp[ MAX_N ][ MAX_CAP ]; // dp array

int call( int i, int w ) // reached ith item and having w weight in the sack
{
    /*
    at this stage we calculate the profit gain in this stage by taking/not taking
    ith item and the next_stage_profit as a consequence of taking/not taking the ith item
    at this stage and return this total profit to the previous stage as the previous
    stage's next_stage_profit
    */

    // base case
    if( i==n ) return 0; /* as no more item can be taken at this stage, this stage cannot
                         contribute to the previous stage's profit */

    if( dp[i][w]!=-1 ) return dp[i][w];

    int take=0, not_take=0;

    // 'trying' to take this item if it does not exceed the weight limit
    if( w + wgh[i] <= cap ) take = val[i] + call( i+1, w+wgh[i] ); // we are going to the next item because
                                                                   // each item can be taken only once
    // not taking this item, skipping it
    not_take = call( i+1, w );

    dp[i][w]=max( take, not_take ); // we want to find the better consequence between taking and not taking
    return dp[i][w];
}
