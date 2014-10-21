#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int n,m;
vector<vector<int> > adj;
bool verif(int mascara){
	int i;
	for(i=0;i<m;i++){
		int cant1 =0,cant2=0;
		for(int j=0;j<adj[i].size();j++){
			int aux = 1<<adj[i][j];
			if(mascara&aux) cant1++;
			else cant2++;
		}
		//cout << flag1 << " " << flag2 << endl;
		if(cant1 == 0 || cant2 == 0) break;
		if(cant1 != 1 && cant2 != 1) break;
	}
	if(i == m) return true;
	else return false;
}
bool recur(int mascara,int ini){
	if(ini == n){
		if(verif(mascara)){return true;}
		else return false;
	}
	if(recur(mascara,ini+1)) return true;
	if(recur(mascara|(1<<ini),ini+1)) return true;
	return false;
}

int main() {
	
	int k;
	scanf("%d",&k);
	string rpta;
	for(int i=0;i<k;i++){
		scanf("%d %d",&n,&m);
		string str;
		getline(cin,str);
		for(int i=0;i<m;i++){
			int num;
			vector<int> aux;
			
			getline(cin,str);
			istringstream it(str);
			while(it>>num){
				num--;
				aux.push_back(num);
			}
			adj.push_back(aux);
		}
		if(recur(0,0)) rpta += 'Y';
		else rpta += 'N';
		adj.clear();
	}
	cout << rpta;
	return 0;
}