/*
Description

A group of cows grabbed a truck and ventured on an expedition deep into the jungle.
Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank.
The truck now leaks one unit of fuel every unit of distance it travels. 

To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road.
On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop). 

The jungle is a dangerous place for humans and is especially dangerous for cows.
Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town.
Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold.
The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000). 

Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all. 

Input

* Line 1: A single integer, N 

* Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop. 

* Line N+2: Two space-separated integers, L and P

Output

* Line 1: A single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

Sample Input

4
4 4
5 2
11 5
15 10
25 10

Sample Output

2

Hint

INPUT DETAILS: 

The truck is 25 units away from the town; the truck has 10 units of fuel.
Along the road, there are 4 fuel stops at distances 4, 5, 11, and 15 from the town (so these are initially at distances 21, 20, 14, and 10 from the truck).
These fuel stops can supply up to 4, 2, 5, and 10 units of fuel, respectively. 

OUTPUT DETAILS: 

Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more units, stop to acquire 5 more units of fuel, then drive to the town.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return b.first < a.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > stops(n);
    for (int i = 0; i < n; ++i) {
        cin >> stops[i].first >> stops[i].second;
    }
    int l, p;
    cin >> l >> p;
    sort(stops.begin(), stops.end(), comp);
    stops.push_back(make_pair(0, 0));
    int times = 0;
    priority_queue<int> fuels;
    for (int i = 0; i < stops.size(); ++i) {
        p -= l - stops[i].first;
        l = stops[i].first;
        if (p < 0) {
            while (!fuels.empty() && p < 0) {
                ++times;
                p += fuels.top();
                fuels.pop();
            }
            if (p < 0) {
                times = -1;
                break;
            }
        }
        fuels.push(stops[i].second);
    }
    cout << times << endl;
    return 0;
}
