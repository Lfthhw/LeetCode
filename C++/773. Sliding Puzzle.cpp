#include<bits/stdc++.h>
using namespace std;
/**
 * Description
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
 * A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 *
 * The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 * Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
 */
/*
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
*/

class Solution {
public:
    /**
     * Solution
     * define the direction array {-1, 1, -3, 3}
     * use queue to record the state (BFS)
     * use map to record swap times of the state
     */
    int slidingPuzzle(vector<vector<int> >& board) {
        queue<string> q;
        map<string, int>mp;
        // direction
        int d[7] = {-1, 1, -3, 3};
        int i, j, x;
        string now, last, ed = "123450";
        // vector turn to string
        for (i = 0; i < 2; i ++)
            for (j = 0; j < 3; j ++) {
                now +=  board[i][j] + 48;
            }
        q.push(now);
        mp[now] = 1;
        if (mp[ed]) return mp[ed] - 1;
        while (!q.empty()) {
            last = q.front();  q.pop();
            cout << last << endl;
            for (i = 0; i < 6; i ++) {
                if (last[i] == '0') j = i;
            }
            // left, right, up, down
            for (i = 0; i < 4; i ++) {
                x = j + d[i];
                if (x >= 0 && x < 6 && !((x == 3 && j == 2) || (x == 2 && j == 3))) {
                    now = last;
                    swap(now[x], now[j]);
                    if (mp[now]) continue;
                    q.push(now);
                    mp[now] = mp[last] + 1;
                    if (mp[ed]) return mp[ed] - 1;

                }
            }
        }
        return -1;
    }
};

int main () {
    int a[3] = {4,1,2};
    int b[3] = {5,0,3};
    vector<int> v1(a, a + 3);
    vector<int> v2(b, b + 3);
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    Solution S;
    printf("%d\n", S.slidingPuzzle(v));
    return 0;
}
