#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int k;
int arr[15];
int res[7];
bool isused[50];

void recur(int cur) {
   
    if (cur == 6) {
        for (int i = 0; i < 6; i++) {
            
                cout << res[i] << " ";
            
        }
        cout << "\n";
        
        return;
    }
   

    for (int i = 0;  i< k ; i++) {

        if (cur != 0 && res[cur-1] > arr[i]) {
            continue;
        }


        if (isused[arr[i]] == false) {
            res[cur] = arr[i];
            isused[arr[i]] = true;
            
            recur(cur + 1);
                isused[arr[i]] = false;
        }
    }

}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> k;
        if (k == 0) {
            break;
        }
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        recur(0);
        cout << "\n";
        for (int i = 0; i < 15; i++) {
            arr[i] = 0;
        }
    }
}