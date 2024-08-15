#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int n, m;

bool ischosen[10001];
int arr[10];
int res[10];


void recur(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = 1; i<=n ; i++) {
       // if ( k!=0 && i < arr[k-1]) {
       //     continue;
     //   }
      
        if (ischosen[arr[i]] == false ) {
            
                res[k] = arr[i];
                ischosen[arr[i]] = true;
                recur(k + 1);
                ischosen[arr[i]] = false;
            
           
        }
        
    }


}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for (int i = 1; i<=n ; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr + n+1);
    
    recur(0);
   
}