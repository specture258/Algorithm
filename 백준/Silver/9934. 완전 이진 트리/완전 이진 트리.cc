#include <bits/stdc++.h>
using namespace std; 

int k;
int arr[1025];
vector<int> v[11];

void recur(int st, int ed, int cnt){
	int mid = (st+ed) /2 ;
	if(cnt == k ){
		return;
	}
	
	
	
	int leftMid = ( st+ ( mid-1) ) /2;
	int rightMid = ( ed+ ( mid+1) ) /2;
//	cout << leftMid << " " << rightMid;
//	cout << "\n";

	v[cnt].push_back( arr[leftMid]);
	v[cnt].push_back( arr[rightMid]);
	int a = mid - ( (pow)(2 ,k-cnt) -1);
	int b = mid + ( (pow)(2 ,k-cnt) -1);
	recur(a, mid-1 ,cnt+1);
	recur( mid+1 , b ,cnt+1);
	
	
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    int cnt = (pow)(2 ,k)-1;
    for(int i=0 ; i<cnt; i++){
    	cin >> arr[i];
	}
    
    int mid = cnt  /2 ;
   
    v[0].push_back(arr[mid]);
    recur(0, cnt-1, 1);

	
	for (int i = 0; i < k; i++) { 
        for (int j = 0; j < v[i].size(); j++) { 
            cout << v[i][j] << " "; 
        }
        cout << "\n"; 
    }
	
	
} 