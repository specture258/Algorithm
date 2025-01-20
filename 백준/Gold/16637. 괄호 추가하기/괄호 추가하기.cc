#include <bits/stdc++.h>
using namespace std; 

int n;
string s;
vector<char> op;
vector<int> num;
int res = -987654321;

int oper(int a, int b, char c){
	if(c == '+'){
		return a+b;
	}
	else if(c == '-'){
		return a-b;
	}
	return a*b;
}

void solve(int cnt, int sum){
	
	if(cnt == num.size()-1){
		res = max(res, sum );
		return;
	}
	
	if(cnt < num.size()-2 ){
		int tmp = oper(num[cnt+1] , num[cnt+2], op[cnt+1] );
		solve(cnt+2, oper(sum, tmp, op[cnt]));
	}
	
	solve(cnt+1, oper(sum, num[cnt+1], op[cnt]) );
	
}





int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  
	cin >> n;
	
	cin >> s;
	
	for(int i=0 ;i<n; i++){
		if(i % 2 ==0){
			num.push_back(s[i]- '0');
		}else{
			op.push_back(s[i]);
		}
	}
	
	
	solve(0 , num[0]);
    
    cout << res;
	
	
	
} 