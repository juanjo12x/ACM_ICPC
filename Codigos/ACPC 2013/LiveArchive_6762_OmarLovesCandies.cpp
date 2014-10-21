#include <iostream>
using namespace std;

long long int arr[1010][1010],arr2[1010][1010];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cin>>arr[i][j];
		}
		for(int i=0;i<=n;i++){
			arr2[i][m] = 0;
		}
		for(int i=0;i<=m;i++){
			arr2[n][i] = 0;
		}
		long long int rpta = -2010;
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				arr2[i][j] = arr[i][j] + arr2[i+1][j] + arr2[i][j+1] - arr2[i+1][j+1];
				rpta = max(rpta,arr2[i][j]);
			}
		}
		cout << rpta << endl;
	}
	return 0;
}