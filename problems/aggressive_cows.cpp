// Description

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
// The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000). 

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
// To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
// What is the largest minimum distance?

// Input

// * Line 1: Two space-separated integers: N and C 

// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output

// * Line 1: One integer: the largest minimum distance

// Sample Input

// 5 3
// 1
// 2
// 8
// 4
// 9

// Sample Output

// 3

// Hint

// OUTPUT DETAILS: 

// FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3. 

// Huge input data,scanf is recommended.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool satisfy(const vector<int> &positions, int cows, int distance) {
    int pre = 0;
    --cows;
    for (int i = 1; i < positions.size(); ++i) {
        if (distance <= positions[i] - positions[pre]) {
            pre = i;
            if (--cows == 0)
                break;
        }
    }
    return cows == 0;
}

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    vector<int> positions(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &positions[i]);
    sort(positions.begin(), positions.end());
    int low = 0, high = positions.back() - positions.front();
    while (low < high) {
        int mid = low + ((high - low + 1) >> 1);
        if (satisfy(positions, c, mid))
            low = mid;
        else
            high = mid - 1;
    }
    printf("%d\n", low);
    return 0;
}
