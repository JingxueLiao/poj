// Description

// Jessica's a very lovely girl wooed by lots of boys.
// Recently she has a problem.
// The final exam is coming, yet she has spent little time on it.
// If she wants to pass it, she has to master all ideas included in a very thick text book.
// The author of that text book, like other authors, is extremely fussy about the ideas, thus some ideas are covered more than once.
// Jessica think if she managed to read each idea at least once, she can pass the exam.
// She decides to read only one contiguous part of the book which contains all ideas covered by the entire book.
// And of course, the sub-book should be as thin as possible.

// A very hard-working boy had manually indexed for her each page of Jessica's text-book with what idea each page is about and thus made a big progress for his courtship.
// Here you come in to save your skin: given the index, help Jessica decide which contiguous part she should read.
// For convenience, each idea has been coded with an ID, which is a non-negative integer.

// Input

// The first line of input is an integer P (1 ≤ P ≤ 1000000), which is the number of pages of Jessica's text-book.
// The second line contains P non-negative integers describing what idea each page is about.
// The first integer is what the first page is about, the second integer is what the second page is about, and so on.
// You may assume all integers that appear can fit well in the signed 32-bit integer type.

// Output

// Output one line: the number of pages of the shortest contiguous part of the book which contains all ideals covered in the book.

// Sample Input

// 5
// 1 8 8 8 1

// Sample Output

// 2

#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int shortest_part(const vector<int> &ideas) {
    set<int> all;
    for (int i = 0; i < ideas.size(); ++i)
        all.insert(ideas[i]);
    map<int, int> times;
    int num = 0;
    int i = 0, j = 0;
    int length = ideas.size();
    while (j < ideas.size()) {
        while (j < ideas.size() && num < all.size()) {
            if (times[ideas[j++]]++ == 0)
                ++num;
        }
        while (i < j && times[ideas[i]] > 1)
            --times[ideas[i++]];
        if (num == all.size())
            length = min(length, j - i);
        --times[ideas[i++]];
        --num;
    }
    return length;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> ideas(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &ideas[i]);
    printf("%d\n", shortest_part(ideas));
    return 0;
}
