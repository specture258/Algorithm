#include <bits/stdc++.h>
using namespace std; 

int n,k;
int dist[200004];
int par[200004];
vector<int> v;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    fill(dist, dist+200004, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while(k != q.front()){
    	int cur = q.front();
    	q.pop();
    	
    	for(int here : {cur+1, cur-1, cur*2}){
    		    		
    		if(here < 0 || here >100000) continue;
    		if(dist[here] >=0 ) continue;
    		dist[here] = dist[cur] +1;
    		q.push(here);
			par[here] = cur;
		}
	
    	
	}
    

	cout << dist[k] << "\n";
	v.push_back(k);
	
	while(dist[k]--){
		
		v.push_back(par[v.back()]);
	}
	reverse(v.begin(), v.end());
	for(int i=0 ; i<v.size() ;i++){
		cout << v[i] << " ";
	}
} 