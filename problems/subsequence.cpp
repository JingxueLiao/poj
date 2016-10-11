// Description

// A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given.
// Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.

// Input

// The first line is the number of test cases.
// For each test case the program has to read the numbers N and S, separated by an interval, from the first line.
// The numbers of the sequence are given in the second line of the test case, separated by intervals.
// The input will finish with the end of file.

// Output

// For each the case the program has to print the result on separate line of the output file.
// if no answer, print 0.

// Sample Input

// 2
// 10 15
// 5 1 3 5 10 7 4 9 2 8
// 5 11
// 1 2 3 4 5

// Sample Output

// 2
// 3

#include <cstdio>
#include <vector>

using namespace std;

int minimal_length(const vector<int> &nums, int s) {
    int length = 0;
    int i = 0, j = 0;
    int sum = 0;
    while (j < nums.size()) {
        while (j < nums.size() && sum < s)
            sum += nums[j++];
        while (i < j && sum - nums[i] >= s)
            sum -= nums[i++];
        if (sum >= s && (length == 0 || length > j - i))
            length = j - i;
        sum -= nums[i++];
    }
    return length;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, s;
        scanf("%d%d", &n, &s);
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        printf("%d\n", minimal_length(nums, s));
    }
    return 0;
}
