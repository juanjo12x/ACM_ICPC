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
     int t,n;string pattern;
     scanf("%d",&t);
     
      f(l,1,t+1){
        if(l>1) printf("\n");
        scanf("%d",&n);getchar();
        cin>>pattern;
        printf("Test case #%d\n",l);
        int B[n+1];
        int i=0,j=-1;
        B[i]=j;
        while(i<n){
         while(j>=0 && pattern[i]!=pattern[j]) j=B[j];
         i++;j++;
         B[i]=j;
          if(j>0 && (i)%(i-j)==0)
             printf("%d %d\n",i,(i)/(i-j));
        }
       
       
    }
     
    return 0;
}