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


int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
//orden especial para que concuerde con dir del vector pond

int main(){
	
	int N;
	while(cin >> N){
		vector<vector<vi > > pond(2*N,vector<vi >(2*N+1,vector<int> (4,1)));//[x][y][dir];
		int ancho = 2*N+1;
		int alto = 2*N;
		int vert = 2*N-1;
		int horiz = N;
		int par = 0;
		int i = 0;
		int j = 0;
		for(int v = 0; v < vert;v++){
			j = 0;
			if(par %2!=0){
				j = 1;
			}
			for(int h = 0; h < horiz;h++){
				char e; cin >> e;
				//cout<< i <<" "<<j<<endl;
				
				//0 es entrar por arriba
				//1 es entrar por la derecha
				//2 es entrar por abajo
				//3 es entrar por izquierda
				
				if(e == 'H'){
					pond[i][j][2] = 0;
					if(i < alto-1)
						pond[i+1][j][0] = 0;
					if(j < ancho-1)
						pond[i][j+1][2] = 0;
					if(i < alto-1 && j < ancho-1)
						pond[i+1][j+1][0] = 0;
					
				}else{
					pond[i][j][1] = 0;
					if(i < alto-1)
						pond[i+1][j][1] = 0;
					if(j < ancho-1)
						pond[i][j+1][3] = 0;
					if(i < alto-1 && j < ancho-1)
						pond[i+1][j+1][3] = 0;
				}
				j+=2;	
			}
			par++;
			i++;
		}
		int componentes = 0;
		vector<vector<bool> > visitado(alto,vector<bool> (ancho,false));
		for(int i = 0; i < alto;i++){
			for(int j = 0; j < ancho; j++){
				if(!visitado[i][j]){
					//bfs
					queue<ii> cola;
					cola.push(mp(i,j));
					visitado[i][j]=true;
					while(!cola.empty()){
						ii par = cola.front();
						cola.pop();
						for(int d = 0; d < 4;d++){
							int nx = par.first + dx[d];
							int ny = par.second + dy[d];
							if(nx >= 0 && ny >= 0 && nx < alto && ny < ancho){
								if(!visitado[nx][ny] && pond[nx][ny][d]){
									visitado[nx][ny] = true;
									cola.push(mp(nx,ny));
								}
							}
						}
					}
					componentes++;
				}	
			}
		}
		
		cout << componentes -1 << endl;
	}
	
	return 0;
}
