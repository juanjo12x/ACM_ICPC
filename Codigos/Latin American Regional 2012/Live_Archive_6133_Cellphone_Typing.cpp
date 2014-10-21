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
const int MAXIMO=26;//tamaño del abecedario
//implementacion del trie
struct trie{
  trie*hijo[MAXIMO];
  int prefijos;
  int palabras;
  //constructores
  trie(){
  	prefijos=0;
  	palabras=0;
  	f(i,0,MAXIMO){
  		hijo[i]=NULL;
  	}
  }
  ~trie(){
  	f(i,0,MAXIMO){
  		delete(hijo[i]);
  	}
  }
  //funciones asociadas
  void agregar(const char*cadena){
  	if(*cadena=='\0'){
  		palabras++;//llego al final de la palabra
  		return;
  	}
  	trie *t = hijo[*cadena-'a'];
    if(hijo[*cadena-'a']==NULL) {
      //nueva raiz
      t = hijo[*cadena-'a'] = new trie();  
      t->prefijos = 1;//solo un prefijo
    } else {
      t->prefijos = t->prefijos + 1;//incrementa prefijo
    }
    t->agregar(cadena+1);//continuo recocriendo la cadena
  }
  //se necesita para este problema
  //la idea es ver es contar todos los que tengan contador de prefijos distintos
  //si 2 nodos adyacentes tienen igual contador, no se cuenta
  int obtener_keys(const char *cadena, int k = 0) {
      if(*cadena=='\0') return k;//la obtuve
      trie *t = hijo[*cadena - 'a'];
      if(t == NULL) return 0;
      return (t->obtener_keys(cadena+1, 
         (prefijos == t->prefijos) ? k: k + 1));
   }
};
int main() {
	int n,keys;
	char buff[1000050];
	while(scanf("%d",&n)!=EOF){
		trie*t=new trie();
         vector<string>dicc;
		f(i,0,n){
			scanf("%s",&buff);
			dicc.push_back(buff);
            t->agregar(buff);
		}
		keys=0;
		f(i,0,n){
			keys+=t->obtener_keys(dicc[i].c_str());
		}
		printf("%.2lf\n",double(keys)/n);
	}
	return 0;
}