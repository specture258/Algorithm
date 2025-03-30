#include <bits/stdc++.h>
using namespace std; 


int x;
vector <int> v;
int a,b;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x;
    int stick = 64;
    
    if(x == 64){
    	cout << 1;
    	return 0;
	}
	v.push_back(64);
	while(1){
		
		if(v[0] == 64){
			v.erase(v.begin());
			v.push_back(stick/2);
			v.push_back(stick/2);
		}
		
		int res=0;
		for(int i=0 ; i<v.size()-1 ;i++){
			res += v[i];
		}
		if(res == x){
			break;
		}
		
		
		int sum =0;
		
		
		for(int i=0 ; i<=v.size()-2 ;i++){
			sum += v[i];
		}
		
		int tmp = v[v.size()-1];
		v.erase(v.begin()+v.size()-1 );
		v.push_back(tmp/2);
		v.push_back(tmp/2);
		if(sum >= x){
			
			for(int i=0 ; i<v.size() ;i++){
				if(v[i] == tmp){
					v.erase(v.begin()+i);
					break;
				}
			}
		}
		
	}
	
	cout << v.size()-1;
	

  	
  	
} 