#include <bits/stdc++.h>
using namespace std; 
// 100 70 90 10
int n;
int mp, mf, ms, mv;

int arr[16][4];
int cnt[16];
int price[16];
int mn = 2147483647;
vector<int> res;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    
    for(int i=0 ; i<n; i++){
    	for(int j=0 ; j<4 ;j++){
    		cin >> arr[i][j];
		}
		cin >> price[i];
	}
	for(int i=0 ; i<n; i++){
		cnt[i] =i;
	}

	for(int i=1 ; i<(1<<n); i++){
		vector<int> v;
		
		int mpSum=0;
		int mfSum =0;
		int msSum =0;
		int mvSum =0;
		int priceSum =0;
		for(int j=0 ; j<n ;j++){
			if(i &(1<<j)){
				v.push_back(cnt[j]);
				mpSum += arr[cnt[j]][0];
				mfSum += arr[cnt[j]][1];
				msSum += arr[cnt[j]][2];
				mvSum += arr[cnt[j]][3];
				
			}
			
		
		}
		for(int i=0 ; i<v.size() ;i++){
				priceSum += price[v[i]];

			}

		if(mpSum<mp || mfSum < mf || msSum < ms || mvSum < mv ) continue;
		
		if(priceSum < mn){
			res.clear();
			mn = priceSum;
			for(int i=0 ; i<v.size(); i++){
				res.push_back(v[i]);
			}
		}
		else if(priceSum == mn){
			int p =0;
		    while(1){
		    	if(v[p] < res[p] ){
		    		res.clear();
		    		for(int i=0 ; i<v.size(); i++){
						res.push_back(v[i]);
			        }
		    		break;
				}
				else if(v[p] > res[p]){
					break;
				}
				p++;
			}	
		}

		
	}

	if(mn == 2147483647){
		cout << -1;
	}
	else{
		cout << mn << "\n";
		for(int i=0 ; i<res.size() ;i++){
			cout << res[i]+1 << " ";
		}
	}
	
	
    
  
  
  
} 