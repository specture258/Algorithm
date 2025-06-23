#include <bits/stdc++.h> 
using namespace std; 

string s;
int k;
int num, dir;
string str[5];

int visited[5];
int go[2] = { -1, 1};
int rot[5];

void bfs(int num){
	
	queue <int> q;
	q.push(num);
	visited[num] =1;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int i=0 ; i<2 ;i++){
		    int next = cur + go[i];
		    
		    if(next<1 || next > 4) continue;
		    if(visited[next]) continue;
		    
		    if(cur > next){
		    	if(str[cur][6] == str[next][2]) continue;
			}
		    if(cur < next){
		    	if(str[cur][2] == str[next][6]) continue;	
			}	
			
			if(rot[cur] == 1){
				rot[next] = -1;
			}
			else if(rot[cur] == -1){
				rot[next] = 1;
			}
			
			q.push(next);
			visited[next] =1;
 		}
	}
}

void left(string &s){
	rotate(s.begin(), s.begin()+1, s.end());
}

void right(string &s){
	rotate(s.rbegin(), s.rbegin()+1, s.rend());
}

int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=1 ; i<=4 ; i++){
    	cin >> s;
    	str[i] = s;
	}
     
    cin >> k; 
    while(k--){
    	cin >> num >> dir;
    	rot[num] = dir;
    	bfs(num);
    	
    	for(int i=1 ;  i<=4 ; i++){
    		if(rot[i] ==1){
    			right(str[i]);
			}
			else if(rot[i] == -1){
				left(str[i]);
			}
		}

    	fill(rot, rot+6, 0);
    	fill(visited, visited+6, 0);
    	
    	
	} 
	
	
	int sum =0;
	
	for(int i=1 ; i<=4 ;i++){
		if(str[i][0] == '1'){
			int val = (int)pow(2, i-1);
			sum += val;
		}
	}
	
	cout << sum;
}