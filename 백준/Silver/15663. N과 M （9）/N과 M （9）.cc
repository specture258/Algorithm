#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int n, m;
bool ischosen[10001];
int arr[10];
int res[10];

void recur(int k) {
    if (m == k) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (ischosen[i] == false && tmp != arr[i]) {
            ischosen[i] = true;
            res[k] = arr[i];
            tmp = res[k];
            recur(k+1);
            ischosen[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for (int i = 0; i<n ; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    recur(0);
   
}