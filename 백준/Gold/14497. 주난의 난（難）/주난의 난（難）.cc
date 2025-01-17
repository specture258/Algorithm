#include <bits/stdc++.h>
using namespace std; 

int n, m;
int xj, yj, xb,yb;

char board[301][301];
int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};
pair<int, int> ju;
int visited[301][301];
int cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n>> m;
	
	cin >> xj >> yj >> xb >> yb;
	
	for(int i=0 ; i<n; i++){
		for(int j=0 ; j<m; j++){
			cin >> board[i][j];
		}
	}
	
	queue<pair<int , int> > q;
	
	for(int i=0 ; i<n; i++){
		for(int j=0 ; j<m; j++){
			if(board[i][j] =='*'){
				ju.first = i;
				ju.second = j;
			}
		}
	}
	
	while(true){
		fill(&visited[0][0] ,&visited[0][0]+301*301 , 0);
		q.push({ju.first,ju.second});
		visited[ju.first][ju.second] =1;
		cnt++;
		
		while(!q.empty()){
		pair<int ,int> cur = q.front();
		q.pop();
		
		for(int dir =0 ; dir<4 ;dir++){
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			
			if(nx <0 || nx >=n || ny <0 || ny>=m || visited[nx][ny]) continue;
			if(board[nx][ny] == '1'){
				board[nx][ny] = '0';
				visited[nx][ny] =1;
				continue;
			}
			
			if(board[nx][ny] == '#'){

				cout << cnt;
				return 0;
			}
			
			q.push({nx,ny});
			visited[nx][ny] =1;
			
			
		}
	  }
	  

		
	}
	
	
	
	


    
   
   
} 