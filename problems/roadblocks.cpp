// Description

// Bessie has moved to a small farm and sometimes enjoys returning to visit one of her best friends.
// She does not want to get to her old home too quickly, because she likes the scenery along the way.
// She has decided to take the second-shortest rather than the shortest path.
// She knows there must be some second-shortest path.

// The countryside consists of R (1 ≤ R ≤ 100,000) bidirectional roads, each linking two of the N (1 ≤ N ≤ 5000) intersections, conveniently numbered 1..N.
// Bessie starts at intersection 1, and her friend (the destination) is at intersection N.

// The second-shortest path may share roads with any of the shortest paths, and it may backtrack i.e., use the same road or intersection more than once.
// The second-shortest path is the shortest path whose length is longer than the shortest path(s) (i.e., if two or more shortest paths exist, the second-shortest path is the one whose length is longer than those but no longer than any other path).

// Input

// Line 1: Two space-separated integers: N and R 
// Lines 2..R+1: Each line contains three space-separated integers: A, B, and D that describe a road that connects intersections A and B and has length D (1 ≤ D ≤ 5000)

// Output

// Line 1: The length of the second shortest path between node 1 and node N

// Sample Input

// 4 4
// 1 2 100
// 2 4 200
// 2 3 250
// 3 4 100

// Sample Output

// 450

// Hint

// Two routes: 1 -> 2 -> 4 (length 100+200=300) and 1 -> 2 -> 3 -> 4 (length 100+250+100=450)

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Comp {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return b.second < a.second;
    }
};

int second_shortest_path(const vector<vector<pair<int, int> > > &graph, int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, Comp> candidates;
    vector<int> shortest(graph.size(), INT_MAX), second_shortest(graph.size(), INT_MAX);
    shortest[s] = 0;
    candidates.push(make_pair(s, 0));
    while (!candidates.empty()) {
        int cur = candidates.top().first, length = candidates.top().second;
        candidates.pop();
        if (second_shortest[cur] < length)
            continue;
        for (int i = 0; i < graph[cur].size(); ++i) {
            int next = graph[cur][i].first, next_length = length + graph[cur][i].second;
            if (next_length < shortest[next]) {
                second_shortest[next] = shortest[next];
                candidates.push(make_pair(next, second_shortest[next]));
                shortest[next] = next_length;
                candidates.push(make_pair(next, next_length));
            } else if (shortest[next] < next_length && next_length < second_shortest[next]) {
                second_shortest[next] = next_length;
                candidates.push(make_pair(next,  next_length));
            }
        }
    }
    return second_shortest[t];
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<vector<pair<int, int> > > graph(n + 1);
    while (r--) {
        int u, v, length;
        cin >> u >> v >> length;
        graph[u].push_back(make_pair(v, length));
        graph[v].push_back(make_pair(u, length));
    }
    cout << second_shortest_path(graph, 1, n) << endl;
    return 0;
}
