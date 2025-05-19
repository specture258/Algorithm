#include <bits/stdc++.h> 
using namespace std; 

int n;
int board[25][25];
int sum;
int res= 987654321;
void solve(vector<int> &v , bool *check){
	
	vector<int> vv;
		
	for(int i=1 ; i<=n ;i++){
		if(!check[i]){
			vv.push_back(i);
		}
	}
	int link =0;
	int start =0;
	
	for(int i= 0 ; i<v.size(); i++){
		for(int j=i+1 ; j<v.size() ;j++){
			link +=  (board[v[i]][v[j]] + board[v[j]][v[i]]);
		}
	}
	
	for(int i= 0 ; i<v.size(); i++){
		for(int j=i+1 ; j<v.size() ;j++){
			start +=  (board[vv[i]][vv[j]] + board[vv[j]][vv[i]]);
		}
	}
	
	res = min(res , abs(link -start));
	
	
	
	
}



void combi(int start, vector<int> &b , bool *check ){
	
	if(b.size() == n/2){
		solve(b, check);
		
		return;
	}
	
	for(int i = start+1 ; i<n ;i++){
		b.push_back(i+1);
		check[i+1] = 1;
		int tmp = i+1;
		combi(i, b, check);
		b.pop_back();
		check[tmp] = 0;
		
	}
	return;
}

int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    bool check[n+1] = {false};
    
    for(int i=1 ; i<=n ;i++){
    	for(int j=1  ; j<=n;j++){
    		cin >> board[i][j];
    		
		}
	}
	
	vector<int> b;
	combi(-1, b , check);
	cout << res;
	
    
}