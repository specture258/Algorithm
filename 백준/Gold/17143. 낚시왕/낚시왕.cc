#include <bits/stdc++.h> 
using namespace std; 

int n, m, sh;
int arr[101][101];
int r,c, s,d,z;
vector<int> v[10001];
int tmp[101][101];
int visited[101][101];
pair<pair<int, int> , int> move(int x, int y, int s, int d){
	
	
	int speed = s; 
	int dir  = d;
	 int r; 
	 if(d == 1 || d == 2){
	 
	  r = (n-1) *2; 
	  } 
	 else{ 
	    r = (m-1) *2; 
	 } 
	 speed = speed % r;
	
	queue<pair<int, int>> q;
	q.push({x,y});
	
	while(speed--){
		pair<int, int> cur = q.front();
		q.pop();
		
		int nx, ny;
		
		if(dir == 1 ){
			if(cur.first == 1){
				dir =2;
				nx = cur.first+1;
				q.push({nx, cur.second});
				continue;
			}
			nx = cur.first-1;
			q.push({nx, cur.second});
		}
		else if(dir == 2){
			if(cur.first == n ){
				dir =1;
				nx = cur.first-1;
				q.push({nx, cur.second});
				continue;
			}
			nx = cur.first+1;
			q.push({nx, cur.second});
		}
		else if(dir == 4){
			if(cur.second == 1 ){
				dir =3;
				ny = cur.second+1;
				q.push({cur.first, ny});
				continue;
			}
			ny = cur.second-1;
			q.push({cur.first, ny});
		}
		else if(dir == 3){
			if(cur.second == m ){
				dir =4;
				ny = cur.second-1;
				q.push({cur.first, ny});
				continue;
			}
			ny = cur.second+1;
			q.push({cur.first, ny});
		}
		
	}
	int h = q.front().first;
	int w = q.front().second;
	return {{h, w}, dir};
	
	
}



int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    cin >> n >> m >> sh;    
     
	fill(&arr[0][0], &arr[0][0]+ 101*101, 0);
	
	for(int i=1 ; i<=sh ;i++){
		cin >> r >> c >> s >> d>> z;
		arr[r][c] = i;
		
		v[i].push_back(s);
		v[i].push_back(d);
		v[i].push_back(z);
	}
	
	int sum =0;
	int cnt =1;
	
	

	while(true){
		if(cnt>m){
			break;
		}
		
		for(int i=1 ; i<=n ;i++){
			if(arr[i][cnt] !=0){
				sum += v[arr[i][cnt]][2];
				arr[i][cnt] =0;
				break;
			}
		}
		
		
		
		for(int i=1 ; i<=n; i++){
		for(int j=1 ; j<=m; j++){
			if(arr[i][j] != 0){
				
			
				pair<pair<int, int>, int> val = move( i, j,  v[arr[i][j]][0], v[arr[i][j]][1] );

				int a = val.first.first;
				int b = val.first.second;
				v[arr[i][j]][1] = val.second;

				
				if(tmp[a][b] ==0){
					tmp[a][b] = arr[i][j];
				}
				else{
					if(v[tmp[a][b]][2] > v[arr[i][j]][2]  ){
						continue;
					}
					else{
						tmp[a][b] = arr[i][j];
					}
				}
				

			}
		}
	}

	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ;j++){
			arr[i][j] = tmp[i][j];
		}
	}
		fill(&tmp[0][0], &tmp[0][0]+ 101*101, 0);
		cnt++;
	
	}

	cout << sum;
	
	
}