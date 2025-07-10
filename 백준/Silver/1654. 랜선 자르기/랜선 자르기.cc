#include<bits/stdc++.h> 
using namespace std; 

int n;
int k;
int arr[10001];

int check(int num){
	int cnt =0;
	for(int i=0 ; i<n ;i++){
		cnt += arr[i] / num;
	}
	return cnt;
}


int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> n >> k;
   
   for(int i=0 ; i<n ;i++){
   	   cin>> arr[i];
   }
   
   
   sort(arr,arr+n);
   
   long long l = 1;
   long long r = arr[n-1];
   long long mid = (l+r) / 2;
   
   while(r>=l){
   	  if(check(mid) < k){
		 r = mid-1;
	  	 mid = (l+r) /2;	   	  	
	  }
	  else{
	  	 l = mid+1;
		 mid = (l+r) /2;
	  }
   }
   cout << r;
   
}