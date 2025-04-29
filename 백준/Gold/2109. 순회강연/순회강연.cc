#include <bits/stdc++.h>
using namespace std; 

int n, p,d;
vector<pair <int, int>>  v;

bool cmp(pair<int, int> &a, pair<int, int> &b){
	
	if(a.first != b.first){
		return a.first > b.first;
	}
	
	return a.second > b.second;
} 
int ret[10001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    for(int i=0 ; i<n ;i++){
    	cin >> p >> d;
		v.push_back({p, d}); 
	}
	
	sort(v.begin(), v.end(), cmp);
    
    for(int i=0 ; i<n; i++){
    	int day = v[i].second;
    	for(int j=day ; j>=1 ;j--){
    		if(ret[j] ==0) {
    		ret[j] = v[i].first;
			break;	
			}
		}
    	
	}
   int sum =0;
     for(int i=0 ; i<10001; i++){
     	sum += ret[i];
	 }
   cout << sum;
    
} 