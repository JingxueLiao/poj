// Description

// Farmer John knows that an intellectually satisfied cow is a happy cow who will give more milk.
// He has arranged a brainy activity for cows in which they manipulate an M × N grid (1 ≤ M ≤ 15; 1 ≤ N ≤ 15) of square tiles, each of which is colored black on one side and white on the other side.

// As one would guess, when a single white tile is flipped, it changes to black; when a single black tile is flipped, it changes to white.
// The cows are rewarded when they flip the tiles so that each tile has the white side face up.
// However, the cows have rather large hooves and when they try to flip a certain tile, they also flip all the adjacent tiles (tiles that share a full edge with the flipped tile).
// Since the flips are tiring, the cows want to minimize the number of flips they have to make.

// Help the cows determine the minimum number of flips required, and the locations to flip to achieve that minimum.
// If there are multiple ways to achieve the task with the minimum amount of flips, return the one with the least lexicographical ordering in the output when considered as a string.
// If the task is impossible, print one line with the word "IMPOSSIBLE".

// Input

// Line 1: Two space-separated integers: M and N 
// Lines 2..M+1: Line i+1 describes the colors (left to right) of row i of the grid with N space-separated integers which are 1 for black and 0 for white

// Output

// Lines 1..M: Each line contains N space-separated integers, each specifying how many times to flip that particular location.

// Sample Input

// 4 4
// 1 0 0 1
// 0 1 1 0
// 0 1 1 0
// 1 0 0 1

// Sample Output

// 0 0 0 0
// 1 0 0 1
// 1 0 0 1
// 0 0 0 0

#include <iostream>
#include <vector>

using namespace std;

int get_color(const vector<vector<int> > &tiles, const vector<vector<int> > &flip, int x, int y) {
    static const int dx[5] = {0, -1, 0, 1, 0};
    static const int dy[5] = {0, 0, 1, 0, -1};
    int c = tiles[x][y];
    for (int d = 0; d < 5; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < tiles.size() && ny >= 0 && ny < tiles[0].size() && flip[nx][ny])
            ++c;
    }
    return c % 2;
}

int process(vector<vector<int> > &tiles, vector<vector<int> > &flip) {
    if (tiles.empty() || tiles[0].empty())
        return 0;
    int flip_times = 0;
    int m = tiles.size(), n = tiles[0].size();
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            flip[i][j] = 0;
            if (get_color(tiles, flip, i - 1, j)) {
                flip[i][j] = 1;
                ++flip_times;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (get_color(tiles, flip, m - 1, i)) {
            flip_times = -1;
            break;
        }
    }
    return flip_times;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > tiles(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> tiles[i][j];
    int minimum_flip_times = -1;
    vector<vector<int> > minimum_flip;
    vector<vector<int> > flip(m, vector<int>(n));
    for (int s = 0; s < 1 << n; ++s) {
        int first_line_flip_times = 0;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) {
                flip[0][i] = 1;
                ++first_line_flip_times;
            } else {
                flip[0][i] = 0;
            }
        }
        int remain_flip_times = process(tiles, flip);
        if (remain_flip_times != -1 && (minimum_flip_times == -1 || first_line_flip_times + remain_flip_times < minimum_flip_times)) {
            minimum_flip_times = first_line_flip_times + remain_flip_times;
            minimum_flip = flip;
        }
    }
    if (minimum_flip_times == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << minimum_flip[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
