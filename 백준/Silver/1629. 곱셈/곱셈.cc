#include<bits/stdc++.h> 
using namespace std;

long long a,b,c;

long long recur(long long a, long long b){
	if(b==1) return a%c;
	long long ret = recur(a, b/2);
	
    ret = (ret * ret) %c;
	
	if( b % 2 ==1){
		ret = (ret * a )%c;
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b >> c;
    
    cout << recur(a, b);

   
}