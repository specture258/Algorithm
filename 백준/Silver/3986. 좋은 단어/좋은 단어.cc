#include <bits/stdc++.h>
using namespace std;

int n;
int res =0;
string word;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--){
		cin >> word;
		stack<char> st;
		for(int i=0 ; i<word.length(); i++){
			if(st.empty()){
				st.push(word[i]);
			}
			else{
				char candi = word[i];
				if(candi == st.top()){
					st.pop();
				}else{
					st.push(word[i]);
				}
			}
		}
		if(st.empty()){
			res++;
		}
	}
	cout << res;
	
}