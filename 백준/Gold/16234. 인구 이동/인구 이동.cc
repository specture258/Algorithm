#include <bits/stdc++.h>
using namespace std; 

int n,l,r;

int board[52][52]; 

int visited[52][52];
int tmp[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt;

void bfs(int x, int y){
	queue<pair<int, int>> q;
	vector < pair<int, int>> v;
	visited[x][y] = 1;
	q.push({x,y});
	v.push_back({x,y});
	
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		
		for(int dir=0 ; dir<4; dir++){
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(nx <0 || nx >=n || ny <0 || ny >=n) continue;
			if(visited[nx][ny] ==1 ) continue;
			if( abs(board[cur.first][cur.second] - board[nx][ny]) >=l &&   abs(board[cur.first][cur.second] - board[nx][ny])  <=r   ) {
				v.push_back({nx, ny});
			visited[nx][ny] = 1;
			q.push({nx,ny});
			}
			

		}
	}
	
	int sum =0;
	for(int i=0 ; i<v.size() ;i++){
		sum += board[v[i].first][v[i].second];   //국경이 열려있는 도시들의 인구수 합 구하기
	}

	for(pair<int, int> a : v){
		board[a.first][a.second] = sum / v.size();     // 도시의 수로 나눠서 인구 수 변경
	}
	
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
   
    cin >> n >> l >> r;
    
    for(int i=0 ; i<n; i++){
    	for(int j=0 ; j<n  ;j++){
    		cin >> board[i][j];
		}
	}

	while(true){
	   
		fill(&visited[0][0] , &visited[0][0]+52*52 ,0);  // bfs 방문 배열 초기화
		
		for(int i=0;i<n ;i++){
			for(int j=0 ; j<n ;j++){
				tmp[i][j] = board[i][j];
			}
		}
		
		
		for(int i=0;i<n ;i++){
			for(int j=0 ; j<n ;j++){
				if(visited[i][j] == 0){
					bfs(i,j);   
				}
			}
		}
		cnt++;
		
		bool flag = false;
		for(int i=0;i<n ;i++){
			for(int j=0 ; j<n ;j++){
				if(board[i][j] != tmp[i][j]){
					flag = true;
				}
			}
			
		}
		if(flag == false) break;
		
		
		
	}
	
	

  
   cout << cnt-1;
} 