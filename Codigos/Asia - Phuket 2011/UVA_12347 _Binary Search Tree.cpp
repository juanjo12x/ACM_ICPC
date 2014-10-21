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

int arr[10010];
int padre[10010];
int hI[10010];
int hD[10010];
int arr2[10010];
//int minn[10010];
int maxx[10010];

void postOrder(int ind){
	if(hI[ind] == 0){
		if(hD[ind] != 0) postOrder(hD[ind]);
	}else if(hD[ind] == 0){
		postOrder(hI[ind]);
	}else{
		postOrder(hI[ind]);
		postOrder(hD[ind]);
	}
	cout << arr[ind] << endl;
}
int main() {
	int n;
	int cant = 0;
	cin >> n;
	//memset(maxx,1000000,sizeof(maxx));
	padre[0] = -1;
	maxx[0] = 1000000;
	maxx[1] = n-1;
	int curr = 0;
	
	arr[cant++] = n;
	while(cin>>n){
		arr[cant++] = n;
		if(n<arr[curr]){
			hI[curr] = cant-1;
			padre[cant-1] = curr;
			maxx[cant-1] = arr[curr]-1;
			//cout << arr[curr]-1 << endl;
		}
		else{
			//cout << n << " " << arr[curr] << " " << maxx[curr] << endl;
			while(n>maxx[curr]){
				curr = padre[curr];
			}
			hD[curr] = cant-1;
			padre[cant-1] = curr;
			maxx[cant-1] = maxx[curr];
		}
		curr = cant-1;
	}
	postOrder(0);
	//for(int i=0;i<cant;i++) cout << arr[i] << " " << padre[i] << " " << hI[i] << " " << hD[i] << endl;
	return 0;
}