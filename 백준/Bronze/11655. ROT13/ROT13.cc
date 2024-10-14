#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);


	getline(cin, s);
	
	for(int i=0 ; i< s.size(); i++){
		if(s[i] - 'a' >= 0){        //소문자 
		 	char rot =  (s[i] - 97 + 13) % 26 + 97 ;
			cout << rot;
			
		}else if(s[i] - 'A' >= 0){	//대문자 
			char rot =  (s[i] - 65 + 13) % 26 + 65 ;
			cout << rot;
		}else{
			cout << s[i];
		}
	}
}