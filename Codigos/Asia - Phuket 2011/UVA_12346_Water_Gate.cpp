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
#include<climits>
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
int t,n;
int flow[25];int cost[25];
//idea bÃ¡sica, generar todos los posibles subsets de flows-cost(2 a la n) y checar para cada flow
//si se puede llegar al minimo, si llega la minimo de horas, revisamos si es menor el costo minimo
//acumulado hasta ahora, si no entonces imprimes IMPOSIBLE
//osea un fuerza bruta, se debio notar ya que n=20 para 1 seg
int main() {
     int mincost,v,mh;
     scanf("%d",&n);
     f(i,0,n){
      scanf("%d %d",&flow[i],&cost[i]);
     }
     scanf("%d",&t);
     int totalcost=0,totalflow=0;
     f(i,0,t){
       mincost=INT_MAX; 
       scanf("%d %d",&v,&mh);
       printf("Case %d:",i+1);
       //plantilla para generar subsets con bits
       f(k,0,(1<<n)){
         totalcost=0;totalflow=0;
         f(j,0,n){
           //si estÃ¡ en el subset
           if (1 & (k >> j)) {
            totalflow += flow[j];
            totalcost += cost[j];
           }
         }
         if(totalflow*mh>v){
          if(totalcost<mincost){
         	mincost=totalcost;
          } 	
         }
       }
       
       
       if(mincost!=INT_MAX){
         printf(" %d\n",mincost);       
       }else printf(" IMPOSSIBLE\n");
     }
     
    return 0;
}
