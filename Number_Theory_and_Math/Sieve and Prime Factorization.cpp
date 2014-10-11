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

// prime factorization WITH Sieve
void factor( int num )
{
    int i=0;
    while( prime_list[i] <= sqrt(num) )
    {
        if( num%prime_list[i]==0 ) {
            /*
            if the number is divisible by a prime then we add it to the list
            and keep dividing the number with the prime as long as it is divisible
            */

            cout << prime_list[i] << " ";
            while( num%prime_list[i]==0 ) num/=prime_list[i];
        }
        i++;
    }
    if( num>1 ) cout << num; // if the reamining number is greater than 1 then it is also
                             // a prime and a divisor of the original number
    cout << endl;
}


// prime factorization WITHOUT Sieve
void factor( int num ) {
    for( int i=2; i*i<=num; i++ ) {
        if( num%i==0 ) cout << i << " ";
        while( num%i==0 ) num/=i;
    } if( num>1 ) cout << num << " ";
    cout << endl;
}
