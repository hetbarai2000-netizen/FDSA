#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;

    cout << "Enter number of buildings (vertices): ";
    cin >> n;

    int graph[20][20];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting building (0 to " << n - 1 << "): ";
    cin >> start;

    
    bool visited[20] = {false};
    stack<int> s;

    cout << "\nDFS Order: ";

    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

           
            for (int i = n - 1; i >= 0; i--) {
                if (graph[v][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> q;

    cout << "\nBFS Order: ";

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}