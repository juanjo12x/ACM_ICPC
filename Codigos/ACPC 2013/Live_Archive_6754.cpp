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
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		long long int rpta = 1;
		f(i,0,str.length()){
			if(str[i] == '?'){
				if(i==0){
					while(str[i]=='?' && i<str.length()) i++;
				}else{
					int num=0,j=i-1;
					while(str[i] == '?' && i!=str.length()){
						num++;
						i++;
					}
					if(i!=str.length()){
							if(str[i] != str[j]){
								rpta *= (num+1);
								rpta %= 1000000007;
							}
						}
					}
					i--;
				}
				
			}
		
		cout << rpta << endl;
	}
	return 0;
}
