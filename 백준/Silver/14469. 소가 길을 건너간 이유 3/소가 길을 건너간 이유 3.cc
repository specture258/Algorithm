#include <bits/stdc++.h>
using namespace std; 

int n;
int a, b;
vector<pair<int ,int>> v;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0 ; i<n ; i++){
    	cin >> a >> b;
    	v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());
	
	int t =v[0].first + v[0].second;
	for(int i=1 ; i<n ; i++){
		if(t < v[i].first){
			t =v[i].first + v[i].second;
			
		}else{
			t +=  v[i].second;
		}
	}
    cout << t;
    
	
} 