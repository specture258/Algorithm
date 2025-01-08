#include <bits/stdc++.h>
using namespace std; 

int n;
int arr[1000001];
int res[1000001];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> n;
	stack<int> s;
	fill(res, res+1000001, -1);
	for(int i=0 ; i<n ;i++){
		cin >> arr[i];
		
		while(s.size() && arr[s.top()] < arr[i]  ){
			res[s.top()] = arr[i];
			s.pop();
		}
		
		s.push(i);
		
	}
	
	for(int i=0 ; i<n; i++){
		cout << res[i] << " ";
	}
   
   
   
} 