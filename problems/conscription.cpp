// Description

// Windy has a country, and he wants to build an army to protect his country.
// He has picked up N girls and M boys and wants to collect them to be his soldiers.
// To collect a soldier without any privilege, he must pay 10000 RMB.
// There are some relationships between girls and boys and Windy can use these relationships to reduce his cost.
// If girl x and boy y have a relationship d and one of them has been collected, Windy can collect the other one with 10000-d RMB.
// Now given all the relationships between girls and boys, your assignment is to find the least amount of money Windy has to pay.
// Notice that only one relationship can be used when collecting one soldier.

// Input

// The first line of input is the number of test case.
// The first line of each test case contains three integers, N, M and R.
// Then R lines followed, each contains three integers xi, yi and di.
// There is a blank line before each test case.

// 1 ≤ N, M ≤ 10000
// 0 ≤ R ≤ 50,000
// 0 ≤ xi < N
// 0 ≤ yi < M
// 0 < di < 10000

// Output

// For each test case output the answer in a single line.
// Sample Input

// 2

// 5 5 8
// 4 3 6831
// 1 3 4583
// 0 0 6592
// 0 1 3063
// 3 3 4975
// 1 3 2049
// 4 2 2104
// 2 2 781

// 5 5 10
// 2 4 9820
// 3 2 6236
// 3 1 8864
// 2 4 8326
// 2 0 5156
// 2 0 1463
// 4 1 2439
// 0 4 4373
// 3 4 8889
// 2 4 3133

// Sample Output

// 71071
// 54223

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u;
    int v;
    int cost;

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

int find(int x, vector<int> &parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, vector<int> &parent, vector<int> &rank) {
    x = find(x, parent);
    y = find(y, parent);
    if (x == y)
        return;
    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
    }
}

int minimum_tree(vector<edge> &edges, int n) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n);
    for (int i = 0; i < parent.size(); ++i)
        parent[i] = i;
    int cost = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u, parent) != find(v, parent)) {
            cost += edges[i].cost;
            unite(u, v, parent, rank);
        }
    }
    return cost;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, r;
        scanf("%d%d%d", &n, &m, &r);
        vector<edge> edges(r);
        for (int i = 0; i < r; ++i) {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            edges[i].u = u;
            edges[i].v = v + n;
            edges[i].cost = -cost;
        }
        printf("%d\n", (n + m) * 10000 + minimum_tree(edges, n + m));
    }
    return 0;
}
