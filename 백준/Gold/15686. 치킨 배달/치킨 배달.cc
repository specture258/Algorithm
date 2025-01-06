#include <bits/stdc++.h>
using namespace std; 

int n, m;
int board[52][52];


int res = 1000000;
vector<pair<int, int>> chi;
vector<pair<int,int>> tmp;
vector<pair<int, int>> h;



void go(int start, vector<pair<int,int>> &chi){
	
	if(chi.size() == m){

		int d1 =0;
	    for(int i=0 ; i<h.size(); i++){
			int s = 10000000;
			for(int j=0 ;j<chi.size(); j++){
				s = min(s, abs(h[i].first-chi[j].first) + abs(h[i].second-chi[j].second));
		    }
	
				d1 += s;
	    }   
	    
	    res = min(res ,d1 );
		
		

	}
	
	for(int i=start+1 ; i<tmp.size(); i++ ){
		chi.push_back({tmp[i].first,tmp[i].second});
				   
		go(i, chi);
		chi.pop_back();
	}
		
}


int main(){
	
	cin >> n >> m;
	
	for(int i=1 ; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> board[i][j];
			if(board[i][j] ==2){
				tmp.push_back({i,j});
			}
			if(board[i][j] ==1){
				h.push_back({i,j});
			}
		}
	}


		go(-1, chi);

	

	cout << res;

  
   
} 



