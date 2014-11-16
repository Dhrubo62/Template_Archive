/*{
    Team name: AUST_Muffin
    Author: ddhrubo
    AUST CSE 32 batch

    Problem:
    Catagory:
    Method:
    Verdict:
}*/
//{********************[Template]********************
using namespace std;
//{***************[        Templates        ]***************
using namespace std ;
//{***************[        C Headers        ]***************
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cfloat>
#include <ctime>
//}
//{***************[        C++ Headers      ]***************
#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <map>
//}
//{***************[        Loops            ]***************
#define forab(i,a,b) for( __typeof (a) i = a ; i <= b ; i++ )
#define rep(i,n) forab(i,0,n-1)
#define repn(i,n) forab(i,1,n)
#define forstl(i, s) for ( __typeof ((s).end ()) i = (s).begin (); i != (s).end (); i++ )
//}
//{***************[        Values           ]***************
#define pi              3.141592653589793
#define inf(INF,type)   type INF = ( 1 << ( 8*sizeof(type)-1 ) ) -1
//}
//{***************[        Macros           ]***************
#define memo(a,b)       memset (a,b,sizeof(a))
#define all(a)          a.begin () , a. end ()
#define ll              long long
#define int64           long long
#define ull             unsigned long long
#define ff              first
#define ss              second
template <class T, class U> inline T max (T &a, U &b) { return a > b ? a : b; }
template <class T, class U> inline T min (T &a, U &b) { return a < b ? a : b; }
template <class T, class U> inline T swap (T &a, U &b){ T tmp = a;a = b;b = tmp;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
//}
//{***************[        Directions       ]***************
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//}
//{***************[        IO               ]***************
#define sf              scanf
#define pf              printf
#define si(a)           scanf("%d",&a)
#define nl              puts("")
#define II              ({ int a; scanf("%d",&a); a;})
#define IL              ({ int64 a; scanf("%lld",&a);  a;})
#define ID              ({ db a; scanf("%lf",&a);  a;})
#define IC              ({ char a; scanf("%c",&a);  a;})
#define IS              ({ string a; cin >> a;  a;})
#define ICA(n)          ({ char a[n]; scanf("%s",&a);  a;})
#define rd              freopen ( "input.txt" , "r" , stdin )
#define wr              freopen ( "output.txt" , "w" , stdout )
//}

int main() {


    return 0;
}
