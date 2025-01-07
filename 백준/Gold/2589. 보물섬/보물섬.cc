#include <bits/stdc++.h>
using namespace std; 


int l, w;
char board[52][52];

int dist[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int res;


void bfs(int x, int y){
   
		fill(&dist[0][0], &dist[0][0] + 52*52 , -1);
		queue<pair<int, int>> q;
	
		q.push({x,y});
		dist[x][y] = 0;
				
		while(!q.empty()){
		      pair<int, int> cur = q.front();
		      q.pop();
		      for(int dir=0 ; dir<4 ;dir++){
		      	  int nx = cur.first + dx[dir];
		      	  int ny = cur.second + dy[dir];
		      	  
		      	  if(nx<0 || nx >=l || ny < 0 || ny>=w) continue;
		      	  if(board[nx][ny] == 'W' ) continue;
		      	  if(dist[nx][ny] >=0  ) continue;
		      	  q.push({nx,ny});
		      	  dist[nx][ny] = dist[cur.first][cur.second] + 1;
		      	  res = max(dist[nx][ny], res);
			  }
		}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	

   cin >> l  >> w;
   
   for(int i=0 ; i<l; i++){
   	   for(int j=0 ; j<w; j++){
   	   	    cin >> board[i][j];
   	   	    
		}
    }
    
    for(int i=0 ; i<l; i++){
   	   for(int j=0 ; j<w; j++){
   	   	    
   	   	    if(board[i][j] == 'L'){
   	   	    	bfs(i,j);	
			}
		}
    }
    
  
    cout << res;

  
   
} 