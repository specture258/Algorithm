#include<bits/stdc++.h> 
using namespace std;


int n,m,j;
int mn;
int lf, rg;
int temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    cin >> j;
    lf = 1;
    for(int i=0 ; i<j ; i++){
    	rg = lf + m -1;
    	cin >> temp;
    	
    	if(temp >= lf && temp <= rg) continue;
    	if(lf < temp){
    		lf += temp -rg; 
    		mn+= temp- rg;
		}else if(temp < lf){
			mn += lf-temp;
			lf = temp;
		}
	}
  
    
    cout << mn;
   
   
   
}