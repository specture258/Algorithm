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
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        cin >> num;
        pq.push(num);
    }

    while (pq.size() !=1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a + b;

        pq.push(a + b);
        
    }
    cout << sum;
    


}