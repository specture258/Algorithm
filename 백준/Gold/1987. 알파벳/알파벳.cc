#include <bits/stdc++.h>
using namespace std; 

int visited[26];
int r,c;
char board[21][21];
int dx[4] = {1,0, -1,0};
int dy[4] = {0,1,0,-1};
int res;

void recur(int x, int y, int cnt){
		res = max(res, cnt);
	for(int i=0 ; i<4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx>=r || ny <0 || ny>=c || visited[board[nx][ny] - 65]){
			continue;
		} 
		visited[board[nx][ny] - 65] = 1;
		recur(nx, ny, cnt+1);
		visited[board[nx][ny] - 65] = 0;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> r>> c;
    for(int i=0 ; i<r ; i++){
    	for(int j=0 ; j< c; j++){
    	    cin >> board[i][j];	
		}
	}
	
	visited[ board[0][0] - 65]  = 1;
	
	recur(0,0, 1);
	
	cout << res;
	
	
	
  
	
} 