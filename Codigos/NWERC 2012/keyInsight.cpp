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

using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,ii> pii ;
typedef vector <ii> vii;
typedef vector<int> vi;


unsigned long long factorial(int n){
    if(n == 0 || n==1){
        return 1LL;
    }else{
        unsigned long long res = 1LL;
        for(int i = 1; i <= n;i++){
            res *= i;
        }
        return res;
    }
}
bool verif2(string s, string r){
    vector<int> frecs(26,0);
    vector<int> frecr(26,0);
    for(int i = 0; i < s.size();i++){
        int e1 = int(s[i]-'a');
        int e2 = int(r[i]-'a');
        frecs[e1]++;
        frecr[e2]++;

    }
    for(int i = 0; i < 26;i++){
        if(frecr[i]!=frecs[i]){
            return false;
        }
    }
    return true;
}

bool verif(vector<string>plaintext,vector<string> ciphertext){

    bool pasa = true;
    for(int i = 0; i < plaintext.size();i++){
        string p = plaintext[i];
        string c = ciphertext[i];
        bool a =verif2(p,c);
        pasa = pasa and a;
        if(!pasa){
            return false;
        }
    }
    return true;

}
unsigned long long solve(vector<string> plaintext, vector<string> ciphertext){
    unsigned long long res = 1LL;
    string plano = plaintext[0];
    string cifrado = ciphertext[0];

    vector<vi> ida(plano.size());
    vector<vi> vuelta(plano.size());

    for(int i = 0; i < plano.size();i++){
        char e1 = plano[i];

        for(int j = 0; j < cifrado.size();j++){
            bool pasa = true;
            char e2 = cifrado[j];
            if(e1 == e2){
            //verificamos que cumpla para todos los trozos
                for(int h = 0; h < plaintext.size();h++){
                    string p = plaintext[h];
                    string c = ciphertext[h];
                    if(p[i]!= c[j]){
                        pasa = false;
                        break;
                    }
                }
                if(!pasa){
                    continue;
                }
                ida[i].push_back(j);
                vuelta[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < plano.size();i++){
        vi llaves = ida[i];
        if(llaves.size()==0){

            return 0LL;
        }
        vi comparar;
        for(int h = 0; h < llaves.size();h++){
            vi retorno = vuelta[llaves[h]];
            if(retorno.size()!= llaves.size()){

                return 0LL;
            }
            if(h==0){
                comparar = retorno;
            }else{
                for(int j = 0; j < comparar.size();j++){
                    if(comparar[j]!= retorno[j]){

                        return 0LL;
                    }
                }
            }
        }

    }
    //lo mismo de arriba solo que al reves
    //ya que se debe cumplir el cifrado por ambos lados
    set<vi> posibles;
    for(int i = 0; i < plano.size();i++){
        vi llaves = vuelta[i];
        if(llaves.size()==0){
            return 0LL;
        }
        vi comparar;
        for(int h = 0; h < llaves.size();h++){
            vi retorno = ida[llaves[h]];
            if(retorno.size()!= llaves.size()){
                return 0LL;
            }
            if(h==0){
                comparar = retorno;
                posibles.insert(comparar);
            }else{
                for(int j = 0; j < comparar.size();j++){
                    if(comparar[j]!= retorno[j]){
                    //cout << "hh"<<endl;
                        return 0LL;
                    }
                }
            }
        }

    }
    /*FOR(i,posibles){
        int tam = i->size();
        res *= factorial(tam);
    }
    la macro me dio compilation error en el juez gg
    */
    for(set<vi>::iterator it = posibles.begin(); it != posibles.end();it++){
        int tam = it -> size();
        //factorial para las permutaciones
        res *= factorial(tam);
    }
    return res;
}

int main(){
    int k;


    while(cin >> k){
        string s,t;
        cin >> s >> t;

        int trozos = s.size()/k;
        vector<string> plaintext;
        vector<string> ciphertext;
        int ini = 0;
        for(int i = 0; i < trozos;i++){
            string a = s.substr(ini,k);
            string b = t.substr(ini,k);
            plaintext.push_back(a);
            ciphertext.push_back(b);
            ini += k;
        }

        //verificamos que cada trozo tenga las mismas letras en el cifrado y en el normal
        bool posible = verif(plaintext,ciphertext);

        if(!posible){

            cout <<0<<endl;
        }else{
            unsigned long long res = solve(plaintext,ciphertext);
            cout << res << endl;

        }

    }

    return 0;
}
