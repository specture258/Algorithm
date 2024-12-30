#include<bits/stdc++.h> 
using namespace std;

int n;
string word, ret;
vector <string> v;

void go(){
	while(ret.size() && ret.front() == '0'){
		ret.erase(ret.begin());
	}
	if(ret.size()==0){
		ret += "0";
	}
	v.push_back(ret);
	
	ret = "";
}

bool cmp(string a, string b){
	if(a.size()== b.size()){
		return a < b;
	}
	return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
  cin >> n;
  
  for(int i=0 ; i<n; i++){
  	 cin >> word;
  	 ret = "";
  		for(int j=0 ; j<word.size(); j++){
		    if(word[j] < 65) ret += word[j];
			else if(ret.size()) go(); 
		  	
		}
  		
  	 	if(ret.size()) go();
  }
  
  sort(v.begin(), v.end(), cmp);
   
     
     for(int i=0 ; i<v.size() ;i++){
     	cout << v[i];
     	cout << "\n";
	 }
  
}