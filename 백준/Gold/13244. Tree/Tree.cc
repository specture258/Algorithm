#include <bits/stdc++.h>
using namespace std; 

int t;
int n;
int num;
vector<int> v[1001];
int visited[1001];
int cnt;
void dfs(int n){
	visited[n] =1;
	
	for(int i : v[n]){
		if(visited[i]) continue;
		dfs(i);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
    	cin >> n;
    	cin >> num;
    	int a, b;
    	cnt =0;
    	fill(visited, visited+1001, 0);
    	for(int i=0 ; i<num ;i++){
    		cin >> a >> b;
    		v[a].push_back(b);
    		v[b].push_back(a);
		}
		
		for(int i=1 ; i<=n ;i++){
			if(visited[i]) continue;
			dfs(i);
			cnt++;
		}
		
		if(n == num +1 && cnt ==1){
			cout << "tree" << "\n";
		}else{
			cout << "graph" << "\n";
		}
		
		
	}
   
    
}