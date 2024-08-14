#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int sum = 0;
    cin >> n;
    int num;
    priority_queue<int> pq;
    while (n--) {
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
        

    }

   
    


}