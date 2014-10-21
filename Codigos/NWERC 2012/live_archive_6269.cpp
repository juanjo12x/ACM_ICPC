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
int n,h,m;
//representacion de 4 segmentos
typedef struct{
 int h0;
 int h1;
 int m0;
 int m1;
}TSegmento;
TSegmento arr[55];
int psegment[4][7];
bool segments[10][7]={{1,1,1,0,1,1,1},  
                      {0,0,1,0,0,1,0},  
                      {1,0,1,1,1,0,1},  
                      {1,0,1,1,0,1,1},  
                      {0,1,1,1,0,1,0},  
                      {1,1,0,1,0,1,1},  
                      {1,1,0,1,1,1,1},  
                      {1,0,1,0,0,1,0},  
                      {1,1,1,1,1,1,1},  
                      {1,1,1,1,0,1,1}};

bool revisa(int p,int x0,int x){

//reviso cada uno de los 7 segmentos, verifico que segmentos
//no prenden
          f(i,0,7){  
                 if (!segments[x0][i] && segments[x][i]) return false;  
                 if (psegment[p][i]==0 && segments[x][i]) return false;  
                 if (psegment[p][i]==1 && segments[x0][i] && !segments[x][i]) return false;  
                 if (segments[x0][i] && segments[x][i]) psegment[p][i]=1;  
                 if (segments[x0][i] && !segments[x][i]) psegment[p][i]=0;  
          }   
          return true;  
} 
bool es_valido(int haux,int maux){
   
         int h0,h1,m0,m1;    
          f(i,0,4){
           f(j,0,7){
             psegment[i][j]=-1;
           }
          }   
          int hr=haux;int mr=maux;
          for (int t=1;t<=n;t++)  
          {  
                 h0=hr/10,h1=hr%10;  
                 m0=mr/10,m1=mr%10;   
                 if (!revisa(0,h0,arr[t].h0)) return false;  
                 if (!revisa(1,h1,arr[t].h1)) return false;  
                 if (!revisa(2,m0,arr[t].m0)) return false;  
                 if (!revisa(3,m1,arr[t].m1)) return false;  
                 mr++;  
                 if (mr==60) mr=0,hr++;//llego a 60, pasa a hora
                 if (hr==24) hr=mr=0;// llego a 24 horas, reinicia  
          }  
          return true;     


}
int main() {
    //la estrategia es revisar cada uno delos minutos y revisar
    //si cumplen o no
    
    
    while(scanf("%d",&n)!=EOF){
       f(i,1,n+1){
        //TSegmento segaux;
        scanf("%d:%d",&h,&m);
        //debug(h);debug(m);
        //debug(h/10);debug(h%10);debug(m/10);debug(m%10);
        arr[i].h0=h/10;arr[i].h1=h%10;
        arr[i].m0=m/10;arr[i].m1=m%10;  
      }
      bool entro=false;
      f(i,0,24){
        f(j,0,60){
         if(es_valido(i,j)){
          if(entro) printf(" ");
          printf("%d%d:%d%d",i/10,i%10,j/10,j%10);
          entro=true;
         }
        }      
      }
      
      if(!entro) printf("none\n");
      else printf("\n");
      
    }	
	return 0;
}
