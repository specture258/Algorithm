#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int l, c;
char arr[20];
int tmp[20];
int res[20];
char ans[20];
bool isvisit[20];



void recur(int k) {
    if (k == l) {
        int vow =0;
        int con = 0;
        for (int i = 0; i < l; i++) {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'o' || ans[i] == 'i' || ans[i] == 'u') {
                vow++;
            }
            else {
                con++;
            }
        }
      

        if (vow>=1 && con >=2) {
            for (int i = 0; i < l; i++) {
                cout << ans[i];
            }
            cout <<  "\n";
            return;
        }
        else {
            return;
        }
       
    }

    for (int i = 0; i< c; i++) {
        if (k !=0 && ans[k-1] > arr[i]) continue;

        if (isvisit[i] == false) {
            ans[k] = arr[i];
            isvisit[i] = true;
            recur(k+1);
            isvisit[i] = false;
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for (int i = 0; i< c ; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + c);
  
    recur(0);

   
    
   
}