#include <bits/stdc++.h>
using namespace std; 

int k;
char arr[10];
int visited[10];
string mx;
string mn;
string num;

vector<string>v;

bool comp(int a, int b, char c){
	if(c == '<'){
		if(a < b){
			return true;
		}
		else{
			return false;
		}
	}
	else if(c == '>'){
		if(a < b){
			return false;
		}
		else{
			return true;
		}
	}
}


void recur(int cnt){
	if(cnt == k+1){
		
		v.push_back(num);
		
		return;
	}
		
	for(int i=0 ; i<=9 ;i++){
		if(cnt == 0){
			num += (char)(i+48);
			visited[i] =1;
		
	    }
		else{
			if(comp(num[cnt-1] -48, i, arr[cnt-1])== false || visited[i]==1){
	    		continue;
			}
			num += (char)(i+48);
			visited[i] =1;
			
		}
		
		recur(cnt+1);
	    	num.erase(num.begin()+ cnt );
		    visited[i] =0;
	    
	    
	}
	return;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  	cin >> k;
  	
  	for(int i=0 ; i<k ;i++){
  		cin >> arr[i];	
   }
   
   recur(0);
   cout << v[ v.size()-1] << "\n";
	cout << v[0];
 
	
  
	
	
} 