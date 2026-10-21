#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int cost[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 6, 5},
        {0, 10, 0, 0, 15},
        {0, 6, 0, 0, 4},
        {0, 5, 15, 4, 0}
    };

    int visited[5] = {0};
    int edges = 0, minCost = 0;
    visited[1] = 1;

    cout << "Selected roads:\n";

    while (edges < n - 1) {
        int min = 9999;
        int a = -1, b = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] > 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << a << " - " << b
             << " : " << min << endl;

        visited[b] = 1;
        minCost += min;
        edges++;
    }

    cout << "Minimum construction cost = "
         << minCost << endl;

    return 0;
}
