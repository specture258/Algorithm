#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	string reversS = s;
	reverse(reversS.begin(), reversS.end());
	
	if(s == reversS){
		cout << 1;
	}else{
		cout << 0;
	}
}