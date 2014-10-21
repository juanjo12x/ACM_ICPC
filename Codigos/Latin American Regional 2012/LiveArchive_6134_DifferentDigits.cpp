#include <iostream>
#include <map>
using namespace std;

int main() {
	int n,m;
	while(cin>>n>>m){
		int rpta = 0;
		for(int i=n;i<=m;i++){
			int aux = i;
			map<int,int> m;
			while(aux){
				int dig = aux%10;
				m[dig]++;
				if(m[dig]==2) break;
				aux /= 10;
			}
			if(!aux) rpta++;
		}
		cout << rpta << endl;
	}
	return 0;
}