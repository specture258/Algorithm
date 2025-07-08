#include<bits/stdc++.h> 
using namespace std; 


int n;
int x,y;
vector<pair<int, int>> v;

int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   
   cin >> n;
   
   while(n--){
   	   cin >> x >> y;
   	   v.push_back({x,y});
   }
   
   sort(v.begin(), v.end());
   
   
   int st = v[0].first;
   int ed = v[0].second;
   int res =0;
   for(int i=1 ; i<v.size(); i++){
   	    if(v[i].first <= ed){
   	    	if(v[i].second > ed){
   	    		ed = v[i].second;
			}
		}
		else{
			res += (ed-st);
			
			st = v[i].first;
			ed = v[i].second;
		}
   }
   
   res += ed-st;
   cout << res;
   
  
	
}