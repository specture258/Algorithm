#include <bits/stdc++.h>
using namespace std; 

int r,c,t;
int board[1002][1002];
int tmp[1002][1002];
int tmp2[1002][1002];
pair<int, int> g1;
pair<int, int> g2;
int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};
int res;
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c >> t;
    
    for(int i=0 ; i<r ;i++){
    	for(int j=0 ; j<c; j++){
    		cin >> board[i][j];	
		}
	}
	bool f = false;
	for(int i=0 ; i<r ;i++){
    	for(int j=0 ; j<c; j++){
    		if(board[i][j] == -1){
    			g1.first = i;
    			g1.second = j;
    			f = true;
    			break;
			}
		}
		if(f) break;
	}
	g2.first = g1.first+1;
	g2.second = g1.second;
	
	while(t--){
		for(int i=0 ; i<r ;i++){
    		for(int j=0 ; j<c; j++){
    			tmp[i][j] = board[i][j];	
			}
		}
		
		for(int i=0 ; i<r ;i++){
    		for(int j=0 ; j<c; j++){
    			if(tmp[i][j] != 0 && tmp[i][j] != -1){
    				 for(int k=0 ; k<4 ;k++){
    				 	int nx = i + dx[k];
    				 	int ny = j+ dy[k];
    				 	  if(tmp[nx][ny] == -1 ) continue;
						  if(nx == r || ny == c ||  nx <0   || ny < 0 ) continue;  
						  
						  
						  	board[nx][ny] += tmp[i][j] / 5;
						  	board[i][j] -= tmp[i][j] / 5;
						    
					 }
				}	
			}
		}
		
		for(int i=0 ; i<r ;i++){
    		for(int j=0 ; j<c; j++){
    			tmp2[i][j] = board[i][j];	
			}
		}
		
		board[g1.first][1] = 0;
		for(int i = 2 ; i<c ; i++ ){
			board[g1.first][i] = tmp2[g1.first][i-1];
		}                      
		for(int i = g1.first-1 ; i >= 0 ;i-- ){
			board[i][c-1] = tmp2[i+1][c-1];
		}
		
		for(int i = c-2 ; i >= 0 ;i-- ){
			board[0][i] = tmp2[0][i+1];
		}
		
		for(int i = 1 ; i <= g1.first-1 ;i++ ){
			board[i][0] = tmp2[i-1][0];
		}
		
		
		
		board[g2.first][1] =0;
		for(int i = 2 ; i<c ; i++ ){
			board[g2.first][i] = tmp2[g2.first][i-1];
		} 
		for(int i = g2.first+1 ; i <= r ;i++ ){
			board[i][c-1] = tmp2[i-1][c-1];
		}
		for(int i = c-2 ; i >= 0 ;i-- ){
			board[r-1][i] = tmp2[r-1][i+1];
		}
		for(int i = r-2 ; i >=g2.first+1 ;i-- ){
			board[i][0] = tmp2[i+1][0];
		}
		
		
	}
	
	for(int i=0 ; i<r; i++){
		for(int j=0 ; j<c ;j++){
			res+=board[i][j];
		}
	}
    cout << res +2; 	
  
	
} 