#include<bits/stdc++.h> 
using namespace std; 

int a,b;
int arrA[200001];
int arrB[200001];
map<int,int> mp;
int cnt;
int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> a >> b;
   
   
   for(int i=0 ; i<a; i++){
   	   cin >> arrA[i];
   	   mp[arrA[i]]++;
   }
   
   for(int i=0 ; i<b; i++){
   	   cin >> arrB[i];
   	   mp[arrB[i]]++;
   }
   
   
   for(auto i : mp){
   	   if(i.second == 1){
   	   	cnt++;
		  }
   }
   cout << cnt;
   
   
   
   
   
    
   
   
   
}