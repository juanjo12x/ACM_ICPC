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
int v,e;
bool matriz[455][455];
int weights[455];
vector<ii> mascapo;

int main() {
   int n1,n2;
	while(scanf("%d %d",&v,&e)!=EOF){
	memset(matriz,false,sizeof(matriz));
	memset(weights,0,sizeof(weights));
	f(i,1,v+1){
	 scanf("%d",&weights[i]);
	}
	f(i,1,e+1){
	  scanf("%d %d",&n1,&n2);
	  matriz[n1][n2]=true;matriz[n2][n1]=true;
	  mascapo.push_back(mp(n1,n2));
	}
    //input
     //ver que grafos hay
     int suma=0;int sumaaux;
     f(i,0,e){
     //k2
     sumaaux=weights[mascapo[i].first] + weights[mascapo[i].second];
//      vector<int> guanira;
      suma=max(sumaaux,suma); 
       f(j,i+1,e){
        sumaaux=weights[mascapo[i].first] + weights[mascapo[i].second];
         //if(i==j) continue;
          if(mascapo[i].first==mascapo[j].first){
              //vemos si hay union de 2 y 3
              if(matriz[mascapo[i].second][mascapo[j].second]){
                //k3
                sumaaux+=weights[mascapo[j].second];suma=max(suma,sumaaux);
                //break;
              }
          }else{
            if(matriz[mascapo[i].first][mascapo[j].first] && matriz[mascapo[i].first][mascapo[j].second] && matriz[mascapo[i].second][mascapo[j].first] && matriz[mascapo[i].second][mascapo[j].second]){
             sumaaux+=weights[mascapo[j].first]+weights[mascapo[j].second];suma=max(suma,sumaaux);
            }
          }
         }           
         suma=max(suma,sumaaux);
       }
       
       printf("%d\n",suma);
       mascapo.clear();   
     }
     
    	
	return 0;
}
