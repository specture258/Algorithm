#include<bits/stdc++.h> 
using namespace std; 

long long n;
long long d[1000001];

int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
    
    cin >> n;
    
    
    d[1] = 1;
    d[2] =2;
    
    for(int i=3 ; i<=n ; i++){
    	d[i] = ( d[i-1] ) + ( d[i-2] );
    	d[i] = d[i] % 15746;
	}
    
    cout << d[n];
  
}