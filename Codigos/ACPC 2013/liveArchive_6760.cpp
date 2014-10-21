#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr( a , v ) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int i = s ; i < (int)(n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT(i,x) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define read ios::sync_with_stdio(false)

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;


int main() {
	int T; 
	cin>>T;
	while(T--){
		int N,M,X;
		cin>>N>>M>>X;
		int comp;
		if(N<M)	comp=N;
		else comp=N%M;
		if(comp==0)	comp=M;
		if(X==comp)	cout <<"YES"<<endl;
		else		cout <<"NO"<<endl;	
	}
	return 0;
}