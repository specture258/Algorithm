#include <bits/stdc++.h>
using namespace std; 

int asum, bsum;
int score, n;
int A, B;
string prv;
string t;


string pr(int k){
	int m = k /60;
	string res1 = "00"+to_string(m);
	int s = k%60;
	string res2 = "00"+to_string(s);
	
	return res1.substr(res1.size()-2,2)   + ":" +res2.substr(res2.size()-2,2);
}

int cg(string k){
	int m = atoi(k.substr(0,2).c_str()) * 60;
	int s = atoi(k.substr(3,2).c_str());
	return m+s;
}

int go(string a, string b){
	
	int t = cg(a);
	int prv = cg(b);
	return t-prv;
}


int main(){
 
	cin >> n;
	
	while(n--){
		cin >> score >> t;
		
		if(A > B){
			asum += go(t ,prv);
		}
		else if(B > A){
			bsum += go(t ,prv);
		}
		
		if(score == 1){
			A++;
		}else{
			B++;
		}
		
		prv = t;
	}
	
	
	if(A > B){
		asum += go("48:00" ,prv);
	}
	else if(B > A){
		bsum += go( "48:00" ,prv);
	}
	
//	cout << asum << "\n" << bsum;
	cout << pr(asum);
	cout << "\n";
	cout << pr(bsum);
	
	
   
   
} 