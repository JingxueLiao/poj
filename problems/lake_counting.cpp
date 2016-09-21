/*
Description

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares.
Each square contains either water ('W') or dry land ('.').
Farmer John would like to figure out how many ponds have formed in his field.
A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. 

Given a diagram of Farmer John's field, determine how many ponds he has.

Input

* Line 1: Two space-separated integers: N and M 

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

Output

* Line 1: The number of ponds in Farmer John's field.

Sample Input

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

Sample Output

3

Hint

OUTPUT DETAILS: 

There are three ponds: one in the upper left, one in the lower left,and one along the right side.
*/

#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
void extends(vector<vector<char> > &field, int x, int y) {
    field[x][y] = 'w';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size() && field[nx][ny] == 'W') {
                extends(field, nx, ny);
            }
        }
    }
}
*/

void extends(vector<vector<char> > &field, int row, int column) {
    if (field[row][column] != 'W')
        return;
    field[row][column] = 'w';
    queue<pair<int, int> > candidates;
    candidates.push(make_pair(row, column));
    while (!candidates.empty()) {
        int x = candidates.front().first, y = candidates.front().second;
        candidates.pop();
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size() && field[nx][ny] == 'W') {
                    field[nx][ny] = 'w';
                    candidates.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int count_lake(vector<vector<char> > &field) {
    if (field.empty() || field[0].empty())
        return 0;
    int lake = 0;
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[0].size(); ++j) {
            if (field[i][j] == 'W') {
                ++lake;
                extends(field, i, j);
            }
        }
    }
    return lake;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<char> > field(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf(" %c", &field[i][j]);
    printf("%d\n", count_lake(field));
    return 0;
}
