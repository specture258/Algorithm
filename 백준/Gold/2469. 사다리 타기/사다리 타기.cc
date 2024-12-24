#include<bits/stdc++.h> 
using namespace std;

int k, n;

string arr[1002][662];
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string res;
string ladder[1001];

string st[27];
string ed[27];
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  

    cin >> k >> n;
    cin >> res;
   	
   	for(int i=0 ; i<k ;i++){
   		st[i] = alpha[i];
	}
	
	for(int i=0 ; i<k ;i++){
   		ed[i] = res[i];
	}
	int index = -1;
	for(int i=0 ; i<n; i++){
		cin >> ladder[i];
		if(ladder[i][0] == '?'){
			index = i;
		}
	}
	
	for(int i=0 ; i<index ;i++){
		for(int j=0 ; j<k-1; j++){
			if(ladder[i][j] == '-'){
				swap(st[j], st[j+1]);
			}
	
		}
	}
	
	for(int i=n-1 ; i>index ;i--){
		for(int j=0 ; j<k-1; j++){
			if(ladder[i][j] == '-'){
				swap(ed[j], ed[j+1]);
			}
	
		}
	}


	bool flag = true;
	for(int i=0 ; i<k-1 ;i++){
		if(st[i] == ed[i]){
			v.push_back("*");
		}else if(st[i] == ed[i+1] && st[i+1] == ed[i]){
			v.push_back("-");
			swap(st[i], st[i+1]);
		}else{
			flag = false;
			break;
		}
	}
	
	if(flag == false){
		for(int i=0 ; i<k-1; i++){
			cout << "x";
		}
	}else{
		for(int i=0 ; i<k-1; i++){
			cout << v[i];
		}
	}
	

	
}