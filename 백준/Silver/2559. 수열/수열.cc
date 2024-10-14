#include <bits/stdc++.h>
using namespace std;

int n, k;
int sum[100001];
int arr[100001];
vector<int> v;
int num;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	for(int i=1 ; i<=n ; i++){
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}


	
	for(int i=k ; i<=n ; i++){
		int term = sum[i] - sum[i-k];
		v.push_back(term);
	}
	
	int res = *max_element(v.begin(), v.end() );
	cout << res;

}