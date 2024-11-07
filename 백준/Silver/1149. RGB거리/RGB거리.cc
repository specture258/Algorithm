#include<bits/stdc++.h> 
using namespace std;

int n;
int color[1001][3];
int dp[1001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

	cin  >> n;
	for(int i=1 ; i<=n; i++){
		for(int j=0 ; j<3; j++){
			cin >> color[i][j];
		} 
	}
	
	dp[1][0] =color[1][0];
	dp[1][1] =color[1][1];
	dp[1][2] =color[1][2];

	for(int i=2 ; i<=n ;i++){
		dp[i][0] = min ( dp[i-1][1], dp[i-1][2] ) + color[i][0];
		
		dp[i][1] = min ( dp[i-1][0], dp[i-1][2] ) + color[i][1];
		
		dp[i][2] = min ( dp[i-1][0], dp[i-1][1] ) + color[i][2];
	}
	
	cout << min ( min (dp[n][0], dp[n][1]) , dp[n][2]);
    
   
}