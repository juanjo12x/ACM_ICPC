
#include <iostream>
#include <climits>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <numeric>
#define FOR(i,A) for(typeof (A).begin() i = (A).begin() ; i != (A).end() ; i++)
#define mp make_pair
#define clr(v,x) memset( v, x , sizeof v )
#define all(x) (x).begin() , (x).end()
#define TAM 2010
#define INF 1000005
using namespace std;

typedef pair<int,int> ii ;
typedef pair<int,ii> pii ;
typedef long long LL ;

vector<pii> edg ;

int n ;
int u,vd,val;
int dis[2005][2005];
int nodo[2005];
int findroot(int x)  
{  
    if(nodo[x]!=x) return nodo[x]=findroot(nodo[x]);  
  
    return nodo[x];  
} 
int main(){
 int roota,rootb;
    bool flag=false;
	while(cin >> n){
        if(!flag) flag = true;
        else cout << endl;
        
       
        for(int i=1;i<=n;i++){
           
            for(int j=1;j<=n;j++){
                int c;
                cin>>c;
                if(j<=i) continue;
                if(c>0) edg.push_back(mp(c,mp(i,j)));
            }
        }
        sort(all(edg));
        for(int i=1;i<=n;i++) nodo[i]=i;  
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=INF;
         
        int t=0;  
  
        for (int i=0;i<edg.size();i++){
        	pii v = edg[ i ] ;
	    	int p = v.first ;
		    int a = v.second.first ;
		    int b = v.second.second ;
            roota=findroot(a);  
            rootb=findroot(b);  
  
            if(roota!=rootb)  
            {  
                nodo[roota]=rootb;  
  
                dis[a][b]=dis[b][a]=p;  
  
                u=a,vd=b,val=p;  
  
                printf("%d %d %d\n",a,b,p);  
  
                t++;  
  
                if(t>=n-1) break;  
            }  
        }  
        
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dis[i][k]==INF) break;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        bool salio=false;
        for(int i=0;i<edg.size();i++)
        {
        	pii v = edg[ i ] ;
		int p = v.first ;
		int a = v.second.first ;
		int b = v.second.second ;
            if(p!=dis[a][b])
            {
                printf("%d %d %d\n",a,b,p);
                salio=true;
                break;
            }
        }
        if(!salio) printf("%d %d %d\n",u,vd,val);
       
        edg.clear();
        
	}


	return 0 ;

}
