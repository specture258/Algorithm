#include <bits/stdc++.h>
using namespace std; 

int n,m;
int board[51][51];

int wboard[51][51][4];

int dx[4] = {1,0,-1,0};    
int dy[4] = {0,1,0,-1};
int visited1[51][51];
int visited2[51][51];
vector<int> v;
queue <pair<int, int>> q;
int cnt =0;
int rmx =0;
int smx =0;

void bfs1(int x, int y){
	int mx =0;
	while(!q.empty()){
		pair<int ,int> cur = q.front();
		q.pop();
		mx++;
		for(int i=0 ; i<4 ; i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if(nx<0 || nx >=m || ny <0 ||ny >=n) continue;
			if(visited1[nx][ny]) continue;
			if(wboard[cur.first][cur.second][i] ==1  ) continue;
			
			visited1[nx][ny] =1;
			q.push({nx,ny});
		}
	}
	rmx = max(rmx, mx);
}

void bfs2(int x, int y){
	int mx =0;
	while(!q.empty()){
		pair<int ,int> cur = q.front();
		q.pop();
		mx++;
		for(int i=0 ; i<4 ; i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if(nx<0 || nx >=m || ny <0 ||ny >=n) continue;
			if(visited2[nx][ny]) continue;
			if(wboard[cur.first][cur.second][i] ==1  ) continue;
			
			visited2[nx][ny] =1;
			q.push({nx,ny});
		}
	}
	smx = max(smx, mx);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0 ; i<m; i++){
    	for(int j=0 ; j<n ;j++){
    		cin >> board[i][j];
    		for(int k=0 ; k<4 ;k++){
    			wboard[i][j][k] =0;
			}
		}
	}
	
	for(int i=0 ; i<m; i++){
    	for(int j=0 ; j<n ;j++){
    		int tmp = board[i][j];
    		int p=3;
    		while(tmp != 0){
    		    if(tmp % 2 == 1){
    		    	wboard[i][j][p] = 1;
				}else{
					wboard[i][j][p] = 0;
				}
				tmp /=2;
    		    p-=1;
				
			}
			
		}
	}
	
	for(int i=0 ; i<m; i++){
    	for(int j=0 ; j<n ;j++){
    		if(visited1[i][j]) continue;
    		q.push({i,j});
    		visited1[i][j] =1;
    		bfs1(i,j);
    		cnt +=1;
		}
	}
	
	for(int i=0 ; i<m; i++){
    	for(int j=0 ; j<n ;j++){
    		for(int k=0 ; k<4 ;k++){
    			if(wboard[i][j][k] ==0) continue;
    			
    			fill(&visited2[0][0], &visited2[0][0]+ 51*51, 0);
    			wboard[i][j][k] = 0;
    			
    			q.push({i,j});
    			visited2[i][j] =1;
    			bfs2(i,j);
    			
    			wboard[i][j][k] = 1;
			}
		}
	}
	cout << cnt << "\n" << rmx << "\n" << smx;
	
} 