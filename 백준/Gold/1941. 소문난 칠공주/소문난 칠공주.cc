#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string board[5];
bool isbool[25];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans;
bool isp7[5][5];
bool isvisited[5][5];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i<5; i++) {
        cin >> board[i];
    }
    fill(isbool + 7, isbool + 25, true);

    do {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                isp7[i][j] = false;
                isvisited[i][j] = false;
            }
        }
        queue<pair<int, int>> q;
        int dasom = 0; int people = 0;
        for (int i = 0; i < 25; i++) {
            if (isbool[i] == false) {
                int x = i / 5;
                int y = i % 5;
                isp7[x][y] = true;
                if (q.empty()) {
                    q.push({ x,y });
                    isvisited[x][y] = true;;
                }

            }
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            if (board[cur.first][cur.second] == 'S') dasom++;
            people++;
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= 5  || ny >= 5 || isp7[nx][ny] == false || isvisited[nx][ny] == true) continue;

                q.push({ nx,ny });
                isvisited[nx][ny] = true;
            }
        }

        if (dasom >= 4 && people == 7) {
            ans++;
        }


    } while (next_permutation(isbool, isbool + 25));
        cout << ans;

   

   
   
}