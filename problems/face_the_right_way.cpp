// Description

// Farmer John has arranged his N (1 ≤ N ≤ 5,000) cows in a row and many of them are facing forward, like good cows.
// Some of them are facing backward, though, and he needs them all to face forward to make his life perfect.

// Fortunately, FJ recently bought an automatic cow turning machine.
// Since he purchased the discount model, it must be irrevocably preset to turn K (1 ≤ K ≤ N) cows at once, and it can only turn cows that are all standing next to each other in line.
// Each time the machine is used, it reverses the facing direction of a contiguous group of K cows in the line (one cannot use it on fewer than K cows, e.g., at the either end of the line of cows).
// Each cow remains in the same *location* as before, but ends up facing the *opposite direction*.
// A cow that starts out facing forward will be turned backward by the machine and vice-versa.

// Because FJ must pick a single, never-changing value of K, please help him determine the minimum value of K that minimizes the number of operations required by the machine to make all the cows face forward.
// Also determine M, the minimum number of machine operations required to get all the cows facing forward using that value of K.

// Input

// Line 1: A single integer: N 
// Lines 2..N+1: Line i+1 contains a single character, F or B, indicating whether cow i is facing forward or backward.

// Output

// Line 1: Two space-separated integers: K and M

// Sample Input

// 7
// B
// B
// F
// B
// F
// B
// B

// Sample Output

// 3 3

// Hint

// For K = 3, the machine must be operated three times: turn cows (1,2,3), (3,4,5), and finally (5,6,7)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_operations(const vector<char> &direction, int k) {
    vector<bool> manipulate(direction.size());
    int operations = 0;
    int sum = 0;
    for (int i = 0; i <= direction.size() - k; ++i) {
        if (i >= k)
            sum -= manipulate[i - k];
        if (direction[i] == 'F' && sum % 2 != 0 || direction[i] == 'B' && sum % 2 == 0) {
            manipulate[i] = true;
            ++sum;
            ++operations;
        }
    }
    for (int i = direction.size() - k + 1; i < direction.size(); ++i) {
        if (i >= k)
            sum -= manipulate[i - k];
        if (direction[i] == 'F' && sum % 2 != 0 || direction[i] == 'B' && sum % 2 == 0) {
            operations = -1;
            break;
        }
    }
    return operations;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<char> direction(n);
    for (int i = 0; i < n; ++i)
        scanf(" %c", &direction[i]);
    int min_operations = n;
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        int cur_operations = minimum_operations(direction, i);
        if (cur_operations != -1 && cur_operations < min_operations) {
            min_operations = cur_operations;
            k = i;
        }
    }
    printf("%d %d\n", k, min_operations);
    return 0;
}
