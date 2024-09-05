#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int t;
int cnt;
string p;
string n;

string number;
int num[100001];
bool iserror;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    
    while (t--) {
        cin >> p;
        
        cin >> cnt;
        cin >> number;
       
        string newnumber = number.substr(1, number.size() - 2);
        vector<int> v;
        
        stringstream ss(newnumber);
        string token;
        while (getline(ss, token, ',')) {
            v.push_back(stoi(token));
        }
        deque <int> dq;
        bool isreversed = false;
        
        for (int num : v) {
            dq.push_back(num);
        }
     
       
        for (int i = 0; i<p.length(); i++) {
            iserror = false;
            if (p[i] == 'R') {

                if (dq.empty()) {
                    continue;
                }
               
                if (isreversed) {
                    isreversed = false;
                }
                else {
                    isreversed = true;
                }
            }
            else{
                if (dq.empty()) {
                    
                    iserror = true;
                    
                    break;
                }
                if (isreversed == false) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
                
            }

         

        }

        if (dq.empty()) {
            if (iserror) {
                cout << "error";
                cout << "\n";
                continue;
           }
        }

        cout << "[";
        if (isreversed == false) {
            for (auto iter = dq.begin(); iter != dq.end(); iter++) {
                if (iter == dq.end()-1) {
                    cout << *iter;
                    break;
                }
                cout << *iter;
                cout << ",";
            }
        }
        else {
            for (auto iter = dq.rbegin(); iter != dq.rend(); iter++) {
                if (iter == dq.rend() - 1) {
                    cout << *iter;
                    break;
                }
                cout << *iter;
                cout << ",";
            }
        }
        cout << "]";
        cout << "\n";
    }


   
   
}