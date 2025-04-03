#include <bits/stdc++.h>
using namespace std; 



string s;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    
    while(1){
    	auto it = s.find("pi");
    	if(it == string::npos){
    		break;
		}
		
		s.replace(it, 2, "**");
	}
	
	while(1){
    	auto it = s.find("ka");
    	if(it == string::npos){
    		break;
		}
		
		s.replace(it, 2, "**");
	}
	
	while(1){
    	auto it = s.find("chu");
    	if(it == string::npos){
    		break;
		}
		
		s.replace(it, 3, "***");
	}
	
	for(int i=0 ; i<s.size() ;i++){
		if(s[i] != '*'){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

} 