#include<bits/stdc++.h> 
using namespace std; 


int n,m;
int arr[100001];
int st, ed, mid;
int res;

bool check(int mid){
	int cnt =1;
	
	int tmp = mid;
	
	for(int i=0 ; i<n; i++){
		
		if(mid < arr[i] ){
			cnt++;
			mid = tmp;
		}
		mid = mid - arr[i];
	}
	
	
	
	return cnt <= m;
}



int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   st = 0;
   int sum=0;
   cin >> n >> m;
   
   for(int i=0 ; i<n ;i++){
   	  cin >> arr[i];
   	  st = max(st, arr[i]);
   	  sum += arr[i];
   }
   ed = sum;
   mid = (st+ed) /2;
   while(st <= ed){
   	
   	 if(check(mid)){
   	 	ed =mid-1;
   	 	res = mid;
	  }
	  else{
	  	st = mid +1;
	  }
   		mid = (st+ed) /2;
   }
   
   
   cout << res;
   
   
   
   
}