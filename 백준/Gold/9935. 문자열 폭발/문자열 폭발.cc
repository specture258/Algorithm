#include <bits/stdc++.h>
using namespace std; 

string s;
string bomb;
stack<char> st;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   cin >> s >> bomb;
   
   
   
   for(char c : s){
   	    	   
	    st.push(c);
	    if(st.size() >= bomb.size() && st.top() == bomb[bomb.size() -1] ){
	   	    string tmp;
	   	    int a = bomb.size();
	   	    while(a--){
	   	      tmp += st.top();
				 st.pop();   	
			}
			
			reverse(tmp.begin(), tmp.end());
			
			if(bomb != tmp){
				for(char c : tmp){
					st.push(c);
				}
			}
			
	   }
    }
    
    if(st.empty()){
    	cout << "FRULA";
    	return 0;
	}
    
    
    string res;
    while(st.size()){
    	res += st.top();
    	st.pop();
	}
    reverse(res.begin(), res.end());
    cout << res;

} 