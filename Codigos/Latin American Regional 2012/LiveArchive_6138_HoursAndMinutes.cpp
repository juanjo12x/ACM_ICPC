#include <iostream>
using namespace std;

int main() {
	int a;
	while(cin>>a){
		if(a%6) cout << "N" << endl;
		else cout << "Y" << endl;
	}
	return 0;
}