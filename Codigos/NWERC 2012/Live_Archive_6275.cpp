#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int val = 10000000;


int main(){
    int x;
    while(cin >> x){
        //cout <<"f"<< x <<endl;
        x *= val;

        vector<int> a;
        int n; cin >> n;
        for(int i = 0; i < n;i++){
            int e; cin >> e;
            a.push_back(e);
        }
        if(n==0 || n == 1){
            cout << "danger"<<endl;
            continue;
        }
        bool paso = false;
        sort(a.begin(),a.end());
        int i = 0;
        int j = n-1;
        while(i < j){
            if(a[i]+a[j]==x){
                cout<<"yes"<<" "<<a[i]<<" "<<a[j]<<endl;
                paso = true;
                break;
            }else if(a[i]+a[j]<x){
                i++;
            }else if(a[i]+a[j]>x){
                j--;
            }
            //cout<<i<<" "<<j<<endl;

        }
        if(!paso){
            cout << "danger"<<endl;
        }

    }


    return 0;
}
