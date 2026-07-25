    #include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>
    using namespace std;

    const int INF = 1000000000;

    int main() {
        int n = 6;
        vector<pair<int,int>> graph[6];

        graph[1].push_back({2, 3});
        graph[2].push_back({3, 4});
        graph[3].push_back({4, 5});
        graph[4].push_back({5, 3});

        graph[1].push_back({3, 10});
        graph[2].push_back({5, 20});

        int start = 1;
        int finish = 5;

        vector<int> dist(n, INF);
        vector<int> parent(n, -1);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distance from node "
             << start << " to node "
             << finish << " = "
             << dist[finish] << endl;

        vector<int> path;
        for (int v = finish; v != -1; v = parent[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << endl;

        return 0;
    }
