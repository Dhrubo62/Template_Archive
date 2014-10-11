/*
Name: GCD & LCM
Purpose: Mathematical functions
*/

int gcd( int divisor, int dividend ) {
    while( divisor ) {
        int remainder  = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    } return dividend;
}

int lcm( int a, int b ) {
    return ( a / gcd(a,b) ) * b; // division is done first to avoid overflow
}
