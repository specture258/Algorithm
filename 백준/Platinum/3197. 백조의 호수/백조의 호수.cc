#include <bits/stdc++.h>
using namespace std; 


int r, c;
char board[1501][1501];
int swanX, swanY;
int swanVisit[1501][1501];
int waterVisit[1501][1501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> water, tempwater, swan, tempswan;

int day;

bool swanMeet(){
	while(!swan.empty()){
		pair<int, int> cur = swan.front();
		swan.pop();
		for(int i=0 ; i<4 ;i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if(nx < 0 || nx>= r || ny<0 || ny>=c ) continue;
			if(swanVisit[nx][ny]) continue;
			
			//swanVisit[nx][ny] =1;
			
			if(board[nx][ny] == 'L' ){
				return true;
			}
			else if(board[nx][ny] == 'X'){
				tempswan.push({nx,ny});
				swanVisit[nx][ny] =1;
				continue;
			}
			else if(board[nx][ny] == '.' ){
				swan.push({nx,ny});
				swanVisit[nx][ny] =1;
			}
			
		}
	}
	return false;
}

void waterMelt(){
	while(!water.empty()){
		pair<int, int> cur = water.front();
		water.pop();
		for(int i=0 ; i<4 ;i++){
			int nx = cur.first +dx[i];
			int ny = cur.second + dy[i];
			
			if(nx < 0 || nx>= r || ny<0 || ny>=c ) continue;
			if(waterVisit[nx][ny]) continue;
			
			if(board[nx][ny] == 'X'){
				board[nx][ny] = '.';
				tempwater.push({nx,ny});
			//	waterVisit[nx][ny] = 1;
			}
			waterVisit[nx][ny] = 1;
			
		}
	}
}

void clearQueue( queue <pair<int, int>> &q){
	queue <pair<int, int>> empty;
	swap(q, empty);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    
    for(int i=0 ; i<r; i++){
    	for(int j=0 ; j< c ;j++){
    		cin >> board[i][j];
    		if(board[i][j] == 'L' ){
    			swanX = i;
    			swanY = j;
			}
			if(board[i][j] == '.' || board[i][j] == 'L'){
				water.push({i,j});
			}
		}
	}
	
	swan.push({swanX, swanY});
	swanVisit[swanX][swanY] =1 ;
	
	while(1){
		if(swanMeet()){
			break;
		}
		
		waterMelt();
		
		water= tempwater;
		swan = tempswan;
		
		
		clearQueue(tempwater);
		clearQueue(tempswan);
		
		
		
		day++;
		
	}
	
	cout << day;
   
	
} 