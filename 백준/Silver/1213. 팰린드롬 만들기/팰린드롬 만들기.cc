#include <bits/stdc++.h>
using namespace std;


string s;
int arr[26];
char res[51];
int centerNum;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	for(int i=0 ; i<s.length() ; i++){
		arr[ s[i]-'A']++;
	}
	int cnt =0;
	char center;
	for(int i=0 ; i<26 ;i++){
		if(arr[i] %2 ==1){
			cnt++;
		  	center = i + 65;
		  
		}
	}
	if(cnt >=2){
		cout<< "I'm Sorry Hansoo";
		return 0;
	}
	
	sort(s.begin(), s.end());
	
	if(cnt ==0){
		for(int i=0 ; i<s.size()/2; i++){
			res[i] = s[i*2];
		}
		for(int i=s.size()/2 ; i<s.size() ;i++){
			res[i] = res[s.size()-1 -i];
		}	
	}else{
		
		for(int i=0 ; i<s.size(); i++){
			if(s[i] == center){
				centerNum = i;
				break;
			}
		}
		
		string newS = "";
		for(int i=0 ; i<s.size(); i++){
			if(i == centerNum){
				continue;
			}
			newS += s[i];
		}
		
		for(int i=0 ; i<newS.size()/2; i++){
			res[i] = newS[i*2];
		}
		for(int i=s.size()/2 ; i<newS.size() ;i++){
			res[i] = res[newS.size()-1 -i];
		}
		
		for(int i=0 ; i<s.size() ;i++){
		//	cout << res[i];
		}
		//cout << "\n";
	
		
		for(int i=newS.size() ; i>newS.size()/2; --i){
			res[i] = res[i-1];
		}
		
			for(int i=0 ; i<s.size() ;i++){
		//	cout << res[i];
		}
		
		res[s.size() / 2] = center;
		
		
	}
	for(int i=0 ; i<s.size() ;i++){
			cout << res[i];
		}

	
	
}