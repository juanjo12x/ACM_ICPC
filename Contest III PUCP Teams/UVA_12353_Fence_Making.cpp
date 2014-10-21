#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <bitset>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#define FOR(i,A) for(typeof (A).begin() i = (A).begin() ; i != (A).end() ; i++)
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define fd(i,a,b) for(int i = a ; i >= b ; i--)
#define debug( x ) cout << #x << " = " << x << endl
#define clr(v,x) memset( v, x , sizeof v )
#define all(x) (x).begin() , (x).end()
#define mp make_pair
#define rall(x) (x).rbegin() , (x).rend()
#define PI acos( -1.0 )
#define EPS 1E-9
#define TAM 100010
  
using namespace std;
  
typedef pair<int,int> ii ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,ii> pii ;
typedef vector <ii> vii;
typedef vector<int> vi;
int main() {
     int dmin,dmax,rmin,rmax,S;ll ans;
     while(scanf("%d %d %d %d %d",&rmin,&rmax,&dmin,&dmax,&S)){
     	if(rmin==0 && rmax==0 && dmin==0 && dmax==0 && S==0) break;
     	ans=0;
     	f(r,rmin,rmax+1){
     		f(d,dmin,dmax+1){
     			double aux=(r+d)*4;
     			double srect = 2 * (r + d);double scirc = 2 * PI * r * r / aux;
                ans += max(0, int((S - scirc) / (srect - scirc)) * 2);
     		}
     	}
     	printf("%lld\n",ans);
     }
    return 0;
}