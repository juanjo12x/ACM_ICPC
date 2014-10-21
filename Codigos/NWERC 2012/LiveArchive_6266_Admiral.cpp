#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define INF 9999999
typedef pair<int,int> pii;
typedef pair<int,pii > ppii;
typedef long long ll;
typedef long double ld;

int n,m;
int mat[1010][1010];
vector<ppii> edges;
vector<pii> camino;
int *pesos,*pred;
void bellmanFord(int ini){
	pesos = new int[n+1];
	pred = new int[n+1];
	for(int i=1;i<=n;i++){
		if(i==ini) pesos[i] = 0;
		else pesos[i] = INF;
		pred[i] = INF;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<edges.size();j++){
			int u = edges[j].second.first;
			int v = edges[j].second.second;
			int w = edges[j].first;
			if(pesos[u]+w < pesos[v]){
				pesos[v] = pesos[u] + w;
				pred[v] = u;
			}
		}
	}
	int sum = 0;
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int a,b,w;
			cin>>a>>b>>w;
			edges.push_back(mp(w,mp(a,b)));
		}
		bellmanFord(1);
		int aux=n;
		int rpta=pesos[n];
		while(pred[aux] != INF){
			camino.push_back(mp(pred[aux],aux));
			aux = pred[aux];
		}
		int n2 = n;
		for(int j=0;j<edges.size();j++){
			if(edges[j].second == camino[camino.size()-1]){
				edges[j].first = 0 - edges[j].first;
				int aux = edges[j].second.first;
				edges[j].second.first = edges[j].second.second;
				edges[j].second.second = aux;
				break;
			}
		}
		for(int i=camino.size()-2;i>=0;i--){
			for(int j=0;j<edges.size();j++){
				if(edges[j].second == camino[i]){
					
					n++;
					
					for(int k=0;k<edges.size();k++){
						if(j == k || edges[k].first < 0) continue;
						if(edges[k].second.first == edges[j].second.first){
							
							edges.push_back(mp(edges[k].first,mp(n,edges[k].second.second)));
							edges.erase(edges.begin()+k);
							if(k<j)j--;
							k--;
						}
					}
					edges.push_back(mp(0,mp(n,edges[j].second.first)));
					edges.push_back(mp(0-edges[j].first,mp(edges[j].second.second,n)));
					edges.erase(edges.begin()+j);
					break;
				}
			}
		}
		delete[] pesos;
		delete[] pred;
		bellmanFord(1);
		rpta +=  pesos[n2];
		delete[] pesos;
		delete[] pred;
		cout << rpta << endl;
		edges.clear();
		camino.clear();
	}
	return 0;
}