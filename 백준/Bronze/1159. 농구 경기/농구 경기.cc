#include <bits/stdc++.h>
using namespace std;

string names[151];
int cnt[26];
int num;
string res = "";


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> num;
	for(int i=0 ; i<num ;i++){
		cin >> names[i];
	}
	
	for(int i=0 ; i<num ; i++ ){
		char firstName = names[i][0];
		cnt[ firstName-'a']++;
	}
	
	for(int i=0 ; i<26 ;i++){
		if(cnt[i]>= 5){
			res += char(i+97);
		}
	}
	
	if(res != ""){
		cout << res;
	}else{
		cout << "PREDAJA";
	}
	
}