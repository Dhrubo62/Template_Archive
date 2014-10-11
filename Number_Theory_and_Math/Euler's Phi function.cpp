/*
Name : Euler's Phi function
Purpose: Finding the number of relative primes of a given nuber equal or less than it.
Divison: Number Theory.
*/

/*
Tutorial written by me:http://austacmprogramming.blogspot.com/2014/10/eulers-totient-or-phi-function-n-phi_11.html
Mathematical proof is needed to understand the algorithm following.
*/

int phi( int num ) {
    int res = num;
    // prime factorization is the base of the algorithm.
    for( int i=2; i*i<num; i++ ) {
        if( num%i==0 ) {
            while( num%i==0 ) num /= i;
            res -= res/i;
        }
    } if( num>1 ) res -= res/num;
    return res;
}
