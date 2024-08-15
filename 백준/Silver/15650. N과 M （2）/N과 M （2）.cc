#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int n, m;

bool ischosen[10];
int arr[10];



void recur(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = 1; i<=n ; i++) {
        if ( k!=0 && i < arr[k-1]) {
            continue;
        }
      
        if (ischosen[i] == false ) {
            
                arr[k] = i;
                ischosen[i] = true;
                recur(k + 1);
                ischosen[i] = false;
            
           
        }
        
    }


}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
   
    recur(0);
   
}