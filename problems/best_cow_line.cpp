/*
Description

FJ is about to take his N (1 ≤ N ≤ 2,000) cows to the annual"Farmer of the Year" competition.
In this contest every farmer arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that order he just registers BSD).
After the registration phase ends, every group is judged in increasing lexicographic order according to the string of the initials of the cows' names.

FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible.
He decides to rearrange his cows, who have already lined up, before registering them.

FJ marks a location for a new line of the competing cows.
He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line.
When he's finished, FJ takes his cows for registration in this new order.

Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in the ith position in the original line

Output

The least lexicographic string he can make.
Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.

Sample Input

6
A
C
D
B
C
B

Sample Output

ABCBCD
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> line[i];
    string newline(n, 0);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) {
        if (line[left] < line[right]) {
            newline[i] = line[left++];
        } else if (line[right] < line[left]) {
            newline[i] = line[right--];
        } else {
            bool l = true;
            for (int j = 1; j <= right - left; ++j) {
                if (line[left + j] < line[right - j]) {
                    break;
                } else if (line[right - j] < line[left + j]) {
                    l = false;
                    break;
                }
            }
            if (l)
                newline[i] = line[left++];
            else
                newline[i] = line[right--];
        }
    }
    int i = 0;
    while (i < n) {
        for (int j = 0; j < 80 && i + j < n; ++j)
            cout << newline[i + j];
        cout << endl;
        i += 80;
    }
    return 0;
}
