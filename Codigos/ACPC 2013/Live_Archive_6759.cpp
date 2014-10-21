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
	int T;
	cin >> T;
	while(T > 0){
		vector<vi > grid;
		int N , M;
		cin >> N >> M;
		int maximo = -2000000000;
		f(i,0,N){
			vi fila;
			f(j,0,M){
				int a;
				cin >> a;
				fila.push_back(a);
			}
			grid.push_back(fila);
		}
		vector<vi> A(N,vi (M));
		A[0][0] = grid[0][0];
		f(i,0, N){
			f(j,0,M){
				if(j == 0 & i == 0){continue;}
				if(i > 0 && j > 0){
					A[i][j] = A[i][j-1] + A[i-1][j] - A[i-1][j-1] + grid[i][j];
				}else
				if(i >0){
					A[i][j] =   A[i-1][j]  + grid[i][j];
				}else
				if( j > 0){
					A[i][j] = A[i][j-1]  + grid[i][j];
				}
			}
		}
		
		f(i,0,N){
			f(j,0,M){
				
				
				f(k,i,N){
					f(m, j, M){
						int subRect = A[k][m];
						if(i > 0) subRect -= A[i-1][m];
						if(j > 0) subRect -= A[k][j-1];
						if(i >0 && j > 0) subRect += A[i-1][j-1];
						maximo = max(maximo,subRect);
					}
				}	
				
			}
		}		
		
		cout << maximo << endl;
		
		 
		T--;
	}
	return 0;
}
