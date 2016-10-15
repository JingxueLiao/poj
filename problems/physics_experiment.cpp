// Description

// Simon is doing a physics experiment with N identical balls with the same radius of R centimeters.
// Before the experiment, all N balls are fastened within a vertical tube one by one and the lowest point of the lowest ball is H meters above the ground.
// At beginning of the experiment, (at second 0), the first ball is released and falls down due to the gravity.
// After that, the balls are released one by one in every second until all balls have been released.
// When a ball hits the ground, it will bounce back with the same speed as it hits the ground.
// When two balls hit each other, they with exchange their velocities (both speed and direction).

// Simon wants to know where are the N balls after T seconds. Can you help him?

// In this problem, you can assume that the gravity is constant: g = 10 m/s2.

// Input

// The first line of the input contains one integer C (C ≤ 20) indicating the number of test cases.
// Each of the following lines contains four integers N, H, R, T.
// 1≤ N ≤ 100.
// 1≤ H ≤ 10000
// 1≤ R ≤ 100
// 1≤ T ≤ 10000

// Output

// For each test case, your program should output N real numbers indicating the height in meters of the lowest point of each ball separated by a single space in a single line.
// Each number should be rounded to 2 digit after the decimal point.

// Sample Input

// 2
// 1 10 10 100
// 2 10 10 100

// Sample Output

// 4.95
// 4.95 10.20

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const double g = 10.0;
    int c;
    scanf("%d", &c);
    while (c--) {
        int n, h, r, t;
        scanf("%d%d%d%d", &n, &h, &r, &t);
        double trip = sqrt(2 * h / g);
        vector<double> heights(n);
        for (int i = 0; i < n; ++i) {
            if (t <= i) {
                heights[i] = h;
            } else {
                int run_time = t - i;
                int k = run_time / trip;
                double remain_time;
                if (k % 2 == 0) {
                    remain_time = run_time - k * trip;
                } else {
                    remain_time = (k + 1) * trip - run_time;
                }
                heights[i] = h - g * remain_time * remain_time / 2;
            }
        }
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); ++i)
            printf("%.2f ", heights[i] + 2 * r * i / 100.0);
        printf("\n");
    }
    return 0;
}
