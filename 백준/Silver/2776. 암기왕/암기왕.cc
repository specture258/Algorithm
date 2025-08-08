#include<bits/stdc++.h> 
using namespace std; 

int t;

int n,m;
vector<int> va;
vector<int> vb;
int num;

int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   
   cin >> t;
   
   while(t--){
   	
   	  cin >> n;
   	  
   	  for(int i=0 ; i<n; i++){
   	  	  cin >> num;
   	  	  va.push_back(num);
	  }
   	  cin >> m;
   	   
   	   for(int j=0 ; j<m ;j++){
   	   	   cin >> num;
   	   	   vb.push_back(num);
		}
   	
   	   sort(va.begin(), va.end());
   	  
   	   
   	   for(auto i : vb){
   	   	    int up = upper_bound(va.begin(), va.end(), i) - va.begin();
   	   	    int down = lower_bound(va.begin(), va.end(), i) - va.begin();
   	   	   if(up -down >=1){
   	   	   	   cout << 1 << "\n";
		   }else{
		   	   cout << 0 << "\n";
		   }
   	   	
		}
		
		va.clear();
		vb.clear();
   	
   	
   }
   
   
}