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
int n1,n2,m1,m2;
int main() {
     int x,y,X,Y;
     bool entro=true;
     scanf("%d %d",&n1,&n2);
     char Gollum[n1+1][n2+1];
     f(i,0,n1){
     	scanf("%s",&Gollum[i]);
     	//debug(Gollum[i]);
     }
     scanf("%d %d",&m1,&m2);
     char Aragon[m1+1][m2+1];
     f(i,0,m1){
      scanf("%s",&Aragon[i]);
      //debug(Aragon[i]);
     }
     vii v;
     f(i,0,m1-n1+1){
     	f(j,0,m2-n2+1){
     		if(Aragon[i][j]==Gollum[0][0]){
     			entro=true;
     			for(x=0,X=i;x<n1;x++,X++){
     				for(y=0,Y=j;y<n2;y++,Y++){
     					if(Aragon[X][Y]!=Gollum[x][y]){
     						entro=false;
     						break;
     					}
     				}
     			}
     			if(entro){
     					v.push_back(mp(i+1,j+1));
     			}
     		}
     		
     	}
     }
     if(v.size()==0){
     	printf("NO MATCH FOUND...\n");
     }else{
     	sort(all(v));
     	/*set<ii> st;
     	f(i,0,v.size()){
     		st.insert(mp(v[i].first,v[i].second));
     	}
     	set<ii>::iterator it;
     	vector<ii> v1;
     	FOR(it,st){
     		v1.push_back(mp(it->first,it->second));
     	}*/
     	f(i,0,v.size()){
     		printf("(%d,%d)\n",v[i].first,v[i].second);
     	}
     }
     
    return 0;
}