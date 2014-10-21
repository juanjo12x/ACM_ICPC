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
     string source;//int cont=0;
     while(getline(cin,source)){
     	//cont=1;
     	//kmp preprocesamiento
     	if(source=="*") break;
     	//if(source == " ") {printf("0\n");continue;}
     	int i=0,j=-1;int m=source.size();
     	int B[m+1];int k=1;
     	B[i]=j;int st=1;
     	while(i<m){
     	 while(j>=0 && source[i]!=source[j]) j=B[j];	
     	 i++;j++;
     	 B[i]=j;
     	  //if(j>0 && (i)%(i-j)==0){ k=max(i/(i-j),k);cont++;}
          
     	}
     	int L=m-B[m];
     	if(L<m && m%L==0) st=(m/L);
     	printf("%d\n",st);
     }
    return 0;
}