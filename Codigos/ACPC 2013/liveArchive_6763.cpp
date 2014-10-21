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




void MCD (int64 a , int64 b , int64& G, int64& x, int64& y){ // G=MCD(a,b)= ax + by
	if(b==0)	{G=a; x=1;y=0;	}
	else{
		MCD(b,a%b,G,y,x);	y-=floor(a/b)*x;
	}
}
 


int main() {
	int casos;
	cin>>casos;
	while(casos--){
	int64 N1,F1,D1,N2,F2,D2,G , x, y;
	
	cin>> N1>>F1>>D1>>N2>>F2>>D2;
	
	//F1+D1x=F2+D2y 
	// 0<=X<=N1-1 	0<=Y<=N2-1 
	
	MCD(D1,-D2,G,x,y); //Algoritmo de Euclides
	
	//(D1x-D2y = F ) /G
	
	int64 F=F2-F1;
	
	x=x*F/G;
	y=y*F/G;	
	
	G=abs(G);
	
	int64 a=D1/G;	//	los incrementos de la ecuacion
	int64 b=D2/G; 	//	deben ser PESI para tomar todos
	

	while(x<0 || y<0){ // si son negativos se agradan hasta el mayor valor posible
		x+=b;
		y+=a;
	}
	
	
	while(x>=0 && y>=0){ // si son positivos se reducen al menor posible
		x-=b;
		y-=a;
	}
	


	int64 posi1=(N1-1-x)/b;	//posibles iguales  
	int64 posi2=(N2-1-y)/a; // posibles iguales
	
	cout<<min(posi1,posi2)<<endl;
	
	}
	
	return 0;
}