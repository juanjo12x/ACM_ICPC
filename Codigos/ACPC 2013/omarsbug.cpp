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

int main(){
	int T;
	cin >> T;
	while(T > 0){
		int N,X,Y;
		cin >> N >> X >> Y;
		if(Y == 1){
			int j = 1;
			for(int i = 0; i < N;i++){
				if(j==X){ j++;}
				if(i==0)cout << j;
				if(i!=0)cout << " "<< j;
				j++;
			}
		}
		else{
			int j = 1;
			bool ya = false;
			for(int i = 0; i < N;i++){
				if(j==X){ya=true;}
				if(i==N-1 && !ya){j=X ;}
				if(i==0)cout << j;
				if(i!=0)cout << " "<< j;
				
				j++;
			}
		}
		cout << endl;
		T--;
	}
	

	return 0;
}
