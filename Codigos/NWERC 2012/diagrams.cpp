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
#include <time.h>
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

using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,ii> pii ;
typedef vector <ii> vii;
typedef vector<int> vi;

map<int , ll> memo[10][10];
int n, rows;
int filas[10];

inline int obtenerValor(int mask, int pos){
    if(pos > 7 || pos < 1){
        return 0;
    }
    mask = mask >> (3*(pos-1));
    int res = 0;
    f(i,0,3){
        res = res | (mask & (1<<i));
    }
    return res;
}

inline int obtenerMascara(int mask, int num, int pos){
    int j = 0;
    // si no fijaba el "r" me daba TLE
    //el "inline" fue sugerencia de jesus pero creo que no afectó
    //porque igual dio tle
    int r = 3*(pos-1);
    f(i,r,r+3){
        if(num & (1<<j)){
            mask = mask | (1 << i);
        }else{
            mask = mask & ~(1<<i);
        }

        j++;
    }
    return mask;

}

ll solve(int x, int y , int mask){

    if(x >= rows){/*cout<<"H "<<x<<"-"<<rows<<endl;*/return 1LL;}
    if(memo[x][y].count(mask)){
           // cout<<"dp"<<endl;
        return memo[x][y][mask];
    }
    ll res = 0;
    if(y == filas[x]){
        res = solve(x+1,0,mask);
    }else{
        int valEncima = obtenerValor(mask,7-y);
        int valIzq = obtenerValor(mask,7-y+1);
        //cout << valEncima<<"-"<<valIzq<<endl;
        int nuevaMask;
        f(i,max(valEncima+1,valIzq),n+1){
            /*int falta = rows -x;
            if(falta + i - 1 > 7){break;}*/
            nuevaMask = obtenerMascara(mask,i,7-y);
            //cout<<nuevaMask<<endl;
            res += solve(x,y+1,nuevaMask);
        }
    }
    return memo[x][y][mask] = res;


}


int main(){

    while(scanf("%d",&rows)==1){
            //cout<<"ROW"<<rows<<endl;
        for(int i = 0; i < rows;i++){
            int e;
            scanf("%d",&e);
            filas[i]=e;
        }
        f(i,0,10){
            f(j,0,10){
                memo[i][j].clear();
            }
        }
        scanf("%d",&n);
        ll res = solve(0,0,0);

        printf("%d\n",res);


    }


    return 0;
}
