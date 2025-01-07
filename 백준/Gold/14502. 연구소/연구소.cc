#include <bits/stdc++.h>
using namespace std; 

int n, m;
int board[9][9];
int tmp[9][9];
int visited[9][9];

vector<pair<int, int>> vir;
vector<pair<int, int>> w;

int res =0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void combi(int start, vector<pair<int, int>> &v){
	if(v.size() == 3){
		

		int cnt =0;
		
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m ;j++){
				tmp[i][j] = board[i][j];
			}
		}
		
		
		fill(&visited[0][0] , &visited[0][0] +9*9 ,0);
		
		for(int i=0 ; i<v.size(); i++){
			tmp[v[i].first][v[i].second] = 1;
		}

		queue<pair<int,int>> q;
		
		for(int i=0 ; i<vir.size(); i++){
			q.push({vir[i].first, vir[i].second});
			visited[vir[i].first][vir[i].second] = 1;
		}
		
		while(!q.empty()){
			pair<int, int> cur = q.front();
			q.pop();
			
			for(int dir=0 ; dir<4 ;dir++){
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				
				if(nx<0 || nx >= n || ny < 0 || ny >=m) continue;
				if(visited[nx][ny] || tmp[nx][ny] == 1) continue;
	
				if(tmp[nx][ny] == 0) tmp[nx][ny] = 2;
				q.push({nx,ny});
				visited[nx][ny]  =1;
			}
		}
		
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				if(tmp[i][j] == 0){
					cnt++;
				}
			}
		}

		
		res = max(res, cnt);
		return;
	}
	
	for(int i=start+1 ; i<w.size(); i++){
		v.push_back({w[i].first, w[i].second});
		combi(i, v);
		v.pop_back();
	}
	
}



int main(){
	
	cin >> n >> m;
	
	for(int i=0 ; i<n ;i++){
		for(int j=0; j<m ;j++){
			cin >> board[i][j];
			if(board[i][j] == 2){
				vir.push_back({i,j});
			}
			if(board[i][j] == 0){
				w.push_back({i,j});
			}
			
		}
	}

	vector<pair<int, int>> v;
	combi(-1, v);

   cout << res;


  
   
} 