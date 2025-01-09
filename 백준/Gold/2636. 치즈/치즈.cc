#include <bits/stdc++.h>
using namespace std; 


int n,m;
int board[102][102];
int visited[102][102];
vector< pair<int, int>> v;
int cnt1, cnt2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(int x, int y){
	visited[x][y] = 1;
	if(board[x][y] ==1){
		v.push_back({x,y});
		return;
	}
	
	for(int i=0 ; i<4; i++){
		int nx= x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= n || ny <0 || ny >=m) continue;
		if(visited[nx][ny]) continue;
		dfs(nx,ny);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
	cin >> n >> m;
	
	for(int i=0 ; i<n; i++){
		for(int j=0 ; j<m; j++){
			cin >> board[i][j];
		}
	}
	
	while(true){
		
		fill(&visited[0][0], &visited[0][0] +102*102 , 0);
		v.clear();
		
		dfs(0,0);
		cnt1++;
		cnt2  = v.size();
		for(int i=0 ; i<v.size(); i++){
			board[v[i].first][v[i].second] = 0;
		}
		
		bool flag = false;
		for(int i=0 ; i<n ;i++){
			for(int j=0 ; j<m; j++){
				if(board[i][j] ==1){
					flag = true;
				}
			}
		}
		
		if(flag == false) break;
		
		
		
		
	}
	
	cout << cnt1 << "\n";
	cout << cnt2;
   
  
} 