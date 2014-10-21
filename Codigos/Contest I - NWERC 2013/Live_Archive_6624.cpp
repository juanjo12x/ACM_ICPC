#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstring>
#include <map>

using namespace std;

map<char,int> m;
long double DP[1300];
int arr[1300];
int fin;

long double recur(int pos){
    if(DP[pos] > -1.0) return DP[pos];
    if(pos > fin){ DP[pos] = 0.0; return 0.0;}
    else if(pos == fin){ DP[pos] = 1.0; return 1.0;}
    else if(arr[pos] != -1){ DP[pos] = 1.0; return 1.0;}

    long double prob = 0.0;
    
    for(int i=2;i<=11;i++){
        long double factor = 1.0/13.0;
        if(i==10) factor*=4;

        prob += factor*recur(pos+i);
    }
    DP[pos] = prob;
    return prob;
}
int main(){
    char buffer[5];
    int n,m;
    while(cin>>n>>m){
        int pos = m;
        memset(arr,-1 ,sizeof(arr));
        for(int i=0;i<1300;i++) DP[i] = -1.0;
        
        for(int i=0;i<n;i++){
            scanf("%s",buffer);
            int num;
            if(isdigit(buffer[0])) arr[pos] = atoi(buffer);
            else{
                if(buffer[0] == 'J' || buffer[0] == 'Q' || buffer[0] == 'K') arr[pos] = 10;
                else arr[pos] = 11;
            }
            
            if(i!=n-1) pos += arr[pos];
        }
        long double rpta=0.0;
        fin = pos;
        for(int i=1;i<=10;i++){
            rpta += recur(i)/10.0;
        }

        printf("%.10llf\n",rpta);
    }

}
