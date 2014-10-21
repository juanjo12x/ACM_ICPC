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
#define TAM 10000005
 
using namespace std;
 
typedef pair<int,int> ii ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,ii> pii ;
typedef vector <ii> vii;
typedef vector<int> vi;
bool verif[TAM];
ll primos[664580];//http://es.numberempire.com/664580
void init(){
 ll i,j,k=0;
    for(i=0;i<10000005;i++)
        verif[i]=true;
    for(i=2;i<10000005;i++)
        if(verif[i]){
            for(j=i*i;j<10000005;j+=i)
                verif[j]=false;
            primos[k++]=i;
        }
}
int main() {
	ll q,i,j,n,ans,margen,cont;
    init();
    while(scanf(" %lld",&q)){
    	if(q==0) break;
        ans = 2;
        margen = (sqrt(q)+0.000001);
        while(q%2==0)
            q/=2;
        for(i=1;primos[i]<=margen && i<664579;i++){
            if(primos[i]>q)
                break;
            cont=0;
            while(q%primos[i]==0){
                q/=primos[i];
                cont++;
            }
            ans*=(cont*2+1);
        }
        if(q!=1)
            ans*=3;
        printf("%lld\n",ans);
    }
	return 0;
}
