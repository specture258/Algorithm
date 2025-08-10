#include<bits/stdc++.h> 
using namespace std; 

int s,c;
long long arr[1000001];

long long check(long long mid){
	long long res =0;
	
	for(int i=0 ; i<s ;i++){
		long long cnt = arr[i]/mid;
		res += cnt;
	}
	
	return res;
}

long long sum;
long long res;
long long lf;
int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> s >> c;
   
   long long st = 1;
   long long ed = 0;
   
   for(int i=0 ; i<s ; i++){
   	   cin >> arr[i];
   	   ed = max(arr[i], ed);
   	   sum += arr[i];
   		
   }
   
   long long mid = (st+ed)/2;
   
   while(st<= ed){
   	   
   	   if(check(mid) >= c){
   	   		res = mid;
   	   		st = mid+1;
   	   		mid = (st+ed)/2;
   	   		
	   }
	   else{
	   		ed = mid-1;
   	   		mid = (st+ed)/2;
	   	
	   }
   	
   }
   
   
   
   cout << sum -res*c ;
   
  
}