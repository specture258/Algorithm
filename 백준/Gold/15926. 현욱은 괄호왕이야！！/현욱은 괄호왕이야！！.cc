#include <bits/stdc++.h>
using namespace std; 

int n;
string s;

int arr[200001];
stack <int> st;
int res =0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    cin >> s;
	
	for(int i=0 ; i< n ;i++){
		
		if(s[i] == '('){
			st.push(i);
		}
		else if(st.size() && s[i] == ')'){
			arr[i] = 1;
			arr[st.top()] =1;
			st.pop();
		}
	}
	
	int tmp =0;
	for(int i=0 ; i<n; i++){
		if(arr[i] ==1){
			tmp++;
			res = max(res, tmp);
		}else{
			
			tmp =0;
		}
	}
	cout << res;
   

} 