#include <bits/stdc++.h>
using namespace std; 

int r,c;

char board[1002][1002];
int jVisited[1002][1002];
int fVisited[1002][1002];
vector< pair<int , int >>v;
queue< pair<int, int>> fq;
queue <pair <int , int>> jq;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void jBfs(int x ,int y){
	jq.push({x,y});
	jVisited[x][y] = 0;
	
	while(!jq.empty()){
		pair<int, int> cur = jq.front();
		jq.pop();
		
		for(int i=0 ; i<4; i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if(nx<0 || nx >=r || ny < 0 || ny >= c) {
				cout << jVisited[cur.first][cur.second]+1;
				return;
			}
		
			if(jVisited[nx][ny] >=0 || board[nx][ny] == '#') continue;
			if(fVisited[nx][ny] <= jVisited[cur.first][cur.second] +1 && fVisited[nx][ny] >=0  ) continue;
			
			
		
			
			jVisited[nx][ny] = jVisited[cur.first][cur.second] +1;
			jq.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    
    for(int i=0 ; i<r; i++){
    	for(int j=0 ; j<c; j++){
    		cin >> board[i][j];
		}
	}
	
	fill(&fVisited[0][0] , &fVisited[0][0] + 1002 * 1002 ,-1);
	fill(&jVisited[0][0] , &jVisited[0][0] + 1002 * 1002 ,-1);
	 
	for(int i=0 ; i<r; i++){
    	for(int j=0 ; j<c; j++){
    		if(board[i][j] == 'F'){
    			v.push_back({i,j});
    			fq.push({i,j});
				fVisited[i][j] = 0;
			}
		}
	}
	
	while(!fq.empty()){
		pair<int, int> cur = fq.front();
		fq.pop();
		
		for(int i=0 ; i<4;i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if(nx<0 || nx >=r || ny < 0 || ny >= c) continue;
			if(fVisited[nx][ny] >=0 || board[nx][ny] == '#') continue;
			
			fq.push({nx,ny});
			fVisited[nx][ny] = fVisited[cur.first][cur.second] +1;
			
		}
	}

	
		
	for(int i=0 ; i<r; i++){
    	for(int j=0 ; j<c; j++){
    		if(board[i][j] == 'J'){
    			jBfs(i,j);
			}
		}
	}
	

	
   

  
} 