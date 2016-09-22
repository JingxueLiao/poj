/*
Description

动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 
有人用两种说法对这N个动物所构成的食物链关系进行描述： 
第一种说法是"1 X Y"，表示X和Y是同类。 
第二种说法是"2 X Y"，表示X吃Y。 
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。 
1）	当前的话与前面的某些真的话冲突，就是假话； 
2）	当前的话中X或Y比N大，就是假话； 
3）	当前的话表示X吃X，就是假话。 
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 

Input

第一行是两个整数N和K，以一个空格分隔。 
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。 
若D=1，则表示X和Y是同类。 
若D=2，则表示X吃Y。

Output

只有一个整数，表示假话的数目。

Sample Input

100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5

Sample Output

3
*/

#include <cstdio>
#include <vector>

using namespace std;

int find(vector<int> &parents, int x) {
    if (parents[x] != x)
        parents[x] = find(parents, parents[x]);
    return parents[x];
}

void unite(vector<int> &parents, vector<int> &ranks, int x, int y) {
    x = find(parents, x);
    y = find(parents, y);
    if (x != y) {
        if (ranks[x] < ranks[y]) {
            parents[x] = y;
        } else if (ranks[y] < ranks[x]) {
            parents[y] = x;
        } else {
            parents[y] = x;
            ++ranks[x];
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> parents(3 * n + 1), ranks(3 * n + 1);
    for (int i = 0; i <= 3 * n; ++i)
        parents[i] = i;
    int lie = 0;
    while (k--) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        if (x <= 0 || x > n || y <= 0 || y > n) {
            ++lie;
        } else {
            int xa = find(parents, x), xb = find(parents, x + n), xc = find(parents, x + 2 * n);
            int ya = find(parents, y), yb = find(parents, y + n), yc = find(parents, y + 2 * n);
            if (type == 1) {
                if (xa == yb || xa == yc) {
                    ++lie;
                } else {
                    unite(parents, ranks, xa, ya);
                    unite(parents, ranks, xb, yb);
                    unite(parents, ranks, xc, yc);
                }
            } else if (type == 2) {
                if (x == y || xa == ya || xa == yc) {
                    ++lie;
                } else {
                    unite(parents, ranks, xa, yb);
                    unite(parents, ranks, xb, yc);
                    unite(parents, ranks, xc, ya);
                }
            }
        }
    }
    printf("%d\n", lie);
    return 0;
}
