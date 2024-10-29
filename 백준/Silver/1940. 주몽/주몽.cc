#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[15001];
int cnt =0;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> m;
	
	for(int i=0 ; i<n ;i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	int st = 0;
	int ed = n-1;
	
	while(1){
		if(arr[st] >= arr[ed]){
			break;
		}
		
		if(arr[st] + arr[ed] == m){
			cnt++;
			st+=1;
			ed-=1;
		}
		else if(arr[st] + arr[ed] < m){
			st +=1;
		}
		else if(arr[st] + arr[ed] > m){
			ed -=1;
		}
		
	}
	
	cout << cnt;
	
}