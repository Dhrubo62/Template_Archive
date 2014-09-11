/*
Name: Sieve
Task: Finding prime numbers in a range
Division: Number Theory
*/

// Global variables
bool prime[ MAX_N ];
int prime_list[ SOME_N ], ind;

void sieve()
{
    prime_list[ ind++ ] = 2;
    for( long long i=3; i<MAX_N; i+=2 )
    {
        if( !prime[i] ) // then i has not been canceled out yet. that makes i a prime number
        {
            prime_list[ ind++ ] = i; // adding i to prime list
            for( long long j = i*i; j<MAX_N; j += 2*i ) prime[j]=true; // cancelling everything divisable by i
        }
    }
}

// checking if a number is prime
if( num==2 || ( num%2 && !prime[num] ) ) num_is_prime=true;
