#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int n, s;
int arr[21];
int cnt;
void recur(int k, int sum) {
   
    if (k == n) {
        if (sum == s) {
            cnt++;
            
        }
        return;
       
    }

    recur(k + 1, sum +arr[k]);
    recur(k + 1, sum );
   

}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    cin >> n >> s;

    for (int i = 0; i< n ; i++) {
        cin >> arr[i];
     }
    recur(0 ,0);
    if (s == 0) cnt--;
    cout << cnt;
}