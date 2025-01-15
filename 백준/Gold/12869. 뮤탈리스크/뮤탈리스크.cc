#include <bits/stdc++.h>
using namespace std; 


int n;
tuple<int, int, int> t;
int visited[64][64][64];
int d[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
int board[3];
int a,b,c;
int cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   
    cin >> n;
    for(int i=0  ;  i <n ;i++){
    	cin >> board[i];
	}
	
	
	t = make_tuple(board[0], board[1], board[2]);
	a = get<0>(t);
	b = get<1>(t);
	c = get<2>(t);
	
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(a,b,c));
	visited[a][b][c] =1;

	while(!q.empty()){
		tuple<int,int,int> cur = q.front();
		q.pop();
		
		for(int i=0 ; i<6; i++){
			
			tuple<int,int,int> tmp;
			tmp =  make_tuple(d[i][0], d[i][1], d[i][2]);
			
				int nx = max(0,get<0>(cur) -  get<0>(tmp) ); 
			    int ny = max(0, get<1>(cur) -  get<1>(tmp) );
			    int nz = max(0, get<2>(cur) -  get<2>(tmp));

			    
			  
				if(visited[nx][ny][nz]) continue;
				
			    q.push(make_tuple(nx,ny,nz));
			    visited[nx][ny][nz] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			
		}
	}
	
	
	cout << visited[0][0][0]-1;
	

	
	
} 