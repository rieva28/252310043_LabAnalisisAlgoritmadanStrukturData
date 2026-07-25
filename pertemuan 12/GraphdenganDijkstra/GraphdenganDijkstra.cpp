#include <iostream>
#include <vector>
#include <string>
#define maxn 100005
#define INT INT_MAX
using namespace std;

vector<pair<int,int>> adj[maxn];
bool vix[maxn];
int dist[maxn];

void dijkstra(int start) {
    memset(vix, false, sizeof(vix));
    for(int i = 0; i < maxn; i++) dist[i] = INT;

    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vix[u]) continue;
        vix[u] = true;

        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    adj[1].push_back({2, 4});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 6});
    adj[3].push_back({2, 2});
    adj[3].push_back({4, 7});
    adj[3].push_back({5, 5});
    adj[4].push_back({3, 4});
    adj[5].push_back({3, 5});
    
    dijkstra(1);
        
    cout<<"Jarak terpendek dari node 1 ke node 4 adalah "<<dist[4]<<endl;
        
    return 0;
}
