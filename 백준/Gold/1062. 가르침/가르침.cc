#include <bits/stdc++.h>
using namespace std; 

int n, k;
string s;
int mx =0;
int cmp[26];
vector <char> v;
char arr[5] ={'a', 'n', 't', 'i', 'c'};

vector<string> words;
void combi(int start, vector<char> &b, int h){
	
	if(b.size() == h){
		int cnt=0;
		for(int i=0 ; i<b.size(); i++){
			cmp[b[i]-97] =1;
		}
		
		for(int i=0 ; i<words.size() ;i++){
			int flag = true;
			for(int j=4 ; j<words[i].size() -4 ;j++){
				if(cmp[ words[i][j]-97 ] == 0){
					flag = false;
				}
			}
			if(flag){
				cnt+=1;
			}
		}
		
//		for(char i : b ){
//			cout << i << " ";
//		}
//		cout<< "\n";
		
		mx = max(mx, cnt);
		for(int i=0 ; i<b.size(); i++){
			cmp[b[i]-97] =0;
		}
	}
	
	for(int i= start+1 ; i<v.size() ;i++){
		b.push_back(v[i]);
		combi(i, b, h);
		b.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=0 ; i<n; i++){
    	cin >> s;
    	words.push_back(s);
    	for(int j=0 ;j<s.size() ;j++){
    		if(s[j] != 'a' && s[j] != 'n' && s[j] != 't' && s[j] != 'i' && s[j] != 'c'){
    			v.push_back(s[j]);	
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int i=0 ; i<5 ;i++){
		cmp[ arr[i]-97 ] =1;
	}
	
	if(v.size() + 5 < k ){
		cout << n;
		return 0;
	}
	
	if(v.size()==0){
		cout << 1;
		return 0;
	}

	if(k<5){
		cout << 0;
		
	}
	else{
		int h = k -5; 
		vector<char> b;
		combi(-1, b, h);
		cout<< mx;
	}

  	
  	
} 