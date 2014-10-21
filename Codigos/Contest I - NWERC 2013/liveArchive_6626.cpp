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


int MCD (int x,int y){
        return (y==0 ? x:MCD(y,x%y));
}
 
int MCM(int x ,int y){
        return (x*y/MCD(x,y));
}

map<int64,int64> factorizar(int64 x){
	map<int64,int64> fact;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			x=x/i;
			fact[i]++;
		}
	}	
		if(x>1)
			fact[x]=1;
	return fact;		
} 



int64 torres(int64 x){
	int64 total=0;
	if(x==1)	return 1;
	map<int64,int64>	desc=factorizar(x);
	int64 lim=desc.begin()->snd;
	FORIT(it,desc)	lim=max(lim,it->snd);
	FORN(i,1,lim+1){
		bool poder=true;
		FORIT(it,desc){
			if( ( (it->snd) %(int64) i) != 0)	poder=false;
		}
		if(poder)	total+=torres(i);
	}
	
	return total;
}




int main() {
	int64 a,b,c;
	while(scanf("%lld^%lld^%lld",&a,&b,&c)==3){
		map<int64,int64> fa=factorizar(a);
		int64 maxExp=0;
		FORIT(it,fa)	maxExp=MCD(maxExp,it->snd);
		map<int64,int64> fb=factorizar(b) , fX=factorizar(maxExp);
		
		FORIT(it,fb)	it->snd=it->snd*c;
		FORIT(it,fX)	fb[it->fst]+=it->snd;
		
		int64 resp=0;
		
		maxExp=fb.begin()->snd;
		FORIT(it,fb)	maxExp=max(maxExp,it->snd);
		
		FORN(i,2,maxExp+1){
			int64 divis=1;
			FORIT(it,fb){
				if(((it->snd)/i) > 0 )	divis=divis*(1+((it->snd)/i));
			}
			
			if(divis>1)	resp+= (divis-1) * torres(i);
		}
		
		printf("%lld\n",resp);
	}
	
	return 0;
}