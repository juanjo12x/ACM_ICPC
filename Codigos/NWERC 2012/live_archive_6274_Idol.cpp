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
#define TAM 4500
 
using namespace std;
 
typedef pair<int,int> ii ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> pii ;
typedef vector <ii> vii;
typedef vector<int> vi;

pii votos[TAM][2];
int t, n, SIZE, v[TAM], orden[TAM], SCC[TAM];
bool visitados[TAM];
vector<pii> adj[TAM][2];
vector<int> G[TAM], Ginv[TAM];

int dfs_base(int p, int x) {
	if(v[p] != -1 && v[p] != x) return 0;
	if(v[p] == x) return 1;
	v[p] = x;
	for(int i=0;i<adj[p][x].size();i++) if(!dfs_base(adj[p][x][i].first, adj[p][x][i].second)) return 0;
	return 1;
}
/*estos dfs son parte del algoritmo de kurasaju*/

void dfs(int v) {
	visitados[v]=1;
	for(int i=0;i<G[v].size();i++) {
		int u=G[v][i];
		if(!visitados[u]) dfs(u);
	}
	orden[t++] = v;//guardo el recorrido
}

void dfsinv(int v) {
	visitados[v]=1;
	SCC[v]=t;
	for(int i=0;i<Ginv[v].size();i++) {
		int u=Ginv[v][i];
		if(!visitados[u]) dfsinv(u);
	}
}

void Kurasaju() {
	t=0;
	for(int i=0;i<SIZE;i++) visitados[i]=0;
	for(int i=0;i<SIZE;i++) if(!visitados[i]) dfs(i);
	t=0;
	for(int i=0;i<SIZE;i++) visitados[i]=0;
	for(int i=SIZE-1;i>=0;i--) if(!visitados[orden[i]]) dfsinv(orden[i]), t++;
}

int main() {
	int m;
	while(scanf("%d %d", &n, &m) != EOF) {
		f(i,1,n+1) v[i] = -1;
		f(i,1,n+1) f(j,0,2) adj[i][j].clear();
		f(i,0,m) {
			int a, b;
			scanf("%d %d",&a,&b);
			int vala = a>0;
			int valb = b>0;
			if(a<0) a=-a;
			if(b<0) b=-b;
			votos[i][0] = pii(a, vala);
			votos[i][1] = pii(b, valb);
			//lo que indica el par es basicamente el valor de a y su respectivo valor
			//booleano
			//tambien se podia hacer con bits
			adj[a][1-vala].push_back(pii(b, valb));adj[b][1-valb].push_back(pii(a, vala));
		}
		memset(visitados,false,sizeof(visitados));
		if(!dfs_base(1, 1)) {
			printf("no\n");
			continue;
		}
		SIZE = 2*n+2;//se tendran en cuenta el grafo implicito, es decir 2N aristas
		f(i,0,SIZE) {
			G[i].clear();
			Ginv[i].clear();
		}
		//creacion del grafoimplicito;
		f(i,0,m) {
			int a = votos[i][0].first;int vala = votos[i][0].second;
			int b = votos[i][1].first;int valb = votos[i][1].second;
			if(v[a] == -1 && v[b] == -1) {
				int negaciona = 2*a + (1-vala);
				a = 2*a + vala;
				int negacionb = 2*b + (1-valb);
				b = 2*b + valb;
				G[negaciona].push_back(b);
				G[negacionb].push_back(a);
				Ginv[a].push_back(negacionb);
				Ginv[b].push_back(negaciona);
			}
		}
		Kurasaju();
		int i;bool salio=false;
		for(i=1;i<=n;i++) {
			if(SCC[2*i] == SCC[2*i+1]) {salio=true;break;}
		}
		if(!salio) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}