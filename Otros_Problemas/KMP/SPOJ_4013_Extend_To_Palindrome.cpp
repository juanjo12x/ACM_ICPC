#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <bitset>
#include <queue>
#include <fstream>
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
int B[100010];
void kmp_in(string P) {
    B[0] = 0;  B[1] = 0;  
    int i = 1, j = 0;
    while(i<P.size()) {
        if (P[i] == P[j])
            B[++i] = ++j;
        else if (j == 0)
            B[++i] = 0;
        else
            j = B[j];
    }
}
int kmp(string P, string T) {
    kmp_in(P);
    int i = 0, j = 0;
    int n = T.size(), m = P.size();
   
    while(i < n) {
        while(j < m) {
            if (P[j] == T[i]) {
                i++; j++;
            } else break;
        }
        if (j == 0) i++;
        if (i==n) return j;
        j = B[j];
    }
    return 0;
}
int main() {
     string cad;
     while(cin>>cad){
        int m=cad.size();
        int i=0,j=-1;
       
        string npal=cad;
        npal=string(cad.rbegin(),cad.rend());
        //debug(cad);
        //debug(npal);
        if(cad==npal){cout<<cad<<endl;continue;}
        string K = cad.substr(0, cad.size()-kmp(npal, cad));
        //debug(K);
        cout << cad+string(K.rbegin(), K.rend()) << endl;
    }
    return 0;
}