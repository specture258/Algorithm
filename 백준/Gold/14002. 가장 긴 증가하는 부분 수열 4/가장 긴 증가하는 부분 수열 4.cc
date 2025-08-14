#include<bits/stdc++.h> 
using namespace std; 

int lis[1001];
int n;
int num;
pair<int, int> res[1001];
int len;
stack <int> s;
int main(){
   
   ios::sync_with_stdio(0);
   cin.tie(0);
   
    cin >> n;
    
    for(int i=0 ; i<n ;i++){
    	cin >> num;
    	auto lowerPos = lower_bound(lis, lis+len, num);
    	int pos = (int) ( lower_bound(lis,lis+len, num) - lis);
    	
    	if(*lowerPos == 0) len++;
    	*lowerPos = num;
    	
    	res[i].first = pos;
    	res[i].second = num;
	}
	
	cout << len << "\n";
	for(int i=n-1 ; i>=0 ;i--){
		if(res[i].first == len-1){
			s.push(res[i].second);
			len--;
		}
	}
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
    
    
    
    
  
}