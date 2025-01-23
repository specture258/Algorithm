#include <bits/stdc++.h>
using namespace std; 

int r, c,k;
char board[6][6];
int res;
int dx[4] ={1,0 ,-1,0};
int dy[4] = {0,1,0,-1};
int visited[6][6];

void recur(int x , int y, int cnt){
	if(x == 0 && y == c-1 && k == cnt){
		res++;
		return;
	}
	
	for(int i=0 ; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(board[nx][ny] == 'T')continue;
		if(nx<0 || ny <0|| nx>=r || ny >=c || visited[nx][ny]) continue;
		visited[nx][ny] =1;
 		recur(nx, ny, cnt+1);
		visited[nx][ny] =0;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c >> k;
    
    for(int i=0 ; i<r ; i++){
    	for(int j=0 ; j<c ; j++){
    		cin >> board[i][j];
		}
	}
	
	visited[r-1][0] =1;
	recur(r-1, 0, 1);
    
    
   cout << res;
   
	
} 