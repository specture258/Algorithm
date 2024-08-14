#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;
    int num;
    priority_queue<int, vector<int> , greater<int>> pq;
   
    for (int i = 0; i < n * n; i++) {
        cin >> num;
        if ( pq.size() < n) {
            pq.push(num);
        }
        else {
            pq.push(num);
            pq.pop();
           
        }
       
    }
   
    cout << pq.top() << "\n";


}