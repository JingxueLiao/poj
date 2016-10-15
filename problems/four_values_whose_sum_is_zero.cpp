// Description

// The SUM problem can be formulated as follows: given four lists A, B, C, D of integer values, compute how many quadruplet (a, b, c, d ) ∈ A x B x C x D are such that a + b + c + d = 0.
// In the following, we assume that all lists have the same size n.

// Input

// The first line of the input file contains the size of the lists n (this value can be as large as 4000).
// We then have n lines containing four integer values (with absolute value as large as 228 ) that belong respectively to A, B, C and D .

// Output

// For each input file, your program has to write the number quadruplets whose sum is zero.

// Sample Input

// 6
// -45 22 42 -16
// -41 -27 56 30
// -36 53 -37 77
// -36 30 -75 -46
// 26 -38 -10 62
// -32 -54 -6 45

// Sample Output

// 5

// Hint

// Sample Explanation: Indeed, the sum of the five following quadruplets is zero: (-45, -27, 42, 30), (26, 30, -10, -46), (-32, 22, 56, -46),(-32, 30, -75, 77), (-32, -54, 56, 30).

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    vector<int> nums1(n * n), nums2(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            nums1[i * n + j] = a[i] + b[j];
            nums2[i * n + j] = c[i] + d[j];
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    long long quadruplets = 0;
    int i = 0, j = n * n - 1;
    while (i < n * n && j >= 0) {
        int sum = nums1[i] + nums2[j];
        if (sum < 0) {
            ++i;
        } else if (sum > 0) {
            --j;
        } else {
            int k = i, l = j;
            while (k < n * n && nums1[k] == nums1[i])
                ++k;
            while (l >= 0 && nums2[l] == nums2[j])
                --l;
            quadruplets += (long long)(k - i) * (j - l);
            i = k;
            j = l;
        }
    }
    printf("%lld\n", quadruplets);
    return 0;
}
