/*
Name: Helpful little functions.
Purpose: Mathematical functions
*/

int gcd( int divisor, int dividend ) {
    while( divisor ) {
        int remainder  = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    } return dividend;
}
