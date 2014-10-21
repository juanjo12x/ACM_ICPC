#include <cstdio>
#include <iostream>

using namespace std;
#define MAXN 1000001

int seg_tree[MAXN*3];
int arr[MAXN];

int combine(int a, int b) {
  // const complexity function to combine two solutions(+,-,^,min,max).
  return a*b;
}

void build(int node, int left, int right) {
  if (left+1 == right) {
    // leaf case.
    seg_tree[node] = arr[left];
    return;
  }
  int mid = left+right>>1;
  build(node * 2, left, mid);
  build(node * 2 + 1, mid, right);
  // we are a non-leaf node, so we should do some processing.
  seg_tree[node] = combine(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

int query(int node, int left, int right, int a, int b) {
  // we are completely outside the range.
  if (b <= left or a >= right) return 1; // neutral of the 'operator'
  // we are completely inside the range. 
  if (left >= a and b >= right) return seg_tree[node];
  int mid = left+right>>1;
  int answ_left = query(node * 2, left, mid, a, b);
  int answ_right = query(node * 2 + 1, mid, right, a, b);
  return combine(answ_left, answ_right);
}

int update(int node, int left, int right, int idx, int val) {
	//cout << left << " " << right << endl;
  if (left+1 == right) {
    // leaf node, implies left == idx
    return seg_tree[node] = arr[left] = val;
  }
  int mid = left+right>>1;
  if (idx >= mid) update(node * 2 + 1, mid, right, idx, val);
  else           update(node * 2 , left, mid, idx, val);
  return seg_tree[node] = combine(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

int main(){
	int n,k;
	while(cin>>n>>k){
		string str;
		for(int i=0;i<n;i++){ cin >> arr[i];
			if(arr[i] > 0) arr[i] = 1;
			else if(arr[i] < 0) arr[i] = -1;
			else arr[i] = 0;
		}
		build(1,0,n);
		for(int i=0;i<k;i++){
			char c;
			int j,r;
			cin>>c>>j>>r;
			if(c== 'C'){
				//cout << j-1 << endl;
				if(r > 0) r = 1;
				else if(r < 0) r = -1;
				else r= 0;
				update(1,0,n,j-1,r);
			}
			else{
				//for(int i=1;i<n*3;i++) cout << seg_tree[i] << " ";
				//cout << endl;
				int aux = query(1,0,n,j-1,r);
				//cout << aux << endl;
				if(aux > 0) str += '+';
				else if(aux < 0) str += '-';
				else str += '0';
			}
		}
		cout << str << endl;
	}
	return 0;
}