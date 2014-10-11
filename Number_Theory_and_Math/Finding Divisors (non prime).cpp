/*
Name: Divisor Finding - Brute Force - ( both prime and non prime )
Division: Number Theory
*/

void div( int num ) {
    int cnt=0; // total number of divisors other than 1 and the number itself
    for( int i=2; i*i<=num; i++ ) {
        if( num%i==0 ) {
            if( i*i==num ) { cout << i << " "; cnt++; }
            else { cout<<i<<" "<<num/i<<" "; cnt+=2; }
        }
    }
}
