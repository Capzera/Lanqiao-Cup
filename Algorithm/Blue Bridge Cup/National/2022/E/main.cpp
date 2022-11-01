#include <QCoreApplication>
#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
#define pii pair<int, int>

using namespace std;

struct Node {int v, w;};
vector<int> dis, cost;
int n, m;

void Dijskra(vector<vector<Node> >& edge) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    dis = vector<int> (n + 1, INF);
    dis[1] = 0;
    vector<bool> vis(n + 1);
    while (pq.size()) {
        int t = pq.top().second;
        pq.pop();
        if (vis[t]) continue;
        vis[t] = 1;
        for (auto& e : edge[t]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[t] + w + cost[t]) {
                dis[v] = dis[t] + w + cost[t];
                pq.push({dis[v], v});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    cost = vector<int> (n + 1);
    vector<vector<Node> > edge(n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];
    cost[1] = cost[n] = 0;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u,w});
    }
    Dijskra(edge);
    cout << dis[n] << endl;
    return 0;
}
/*
4 4
5 7 3 4
1 2 4
1 3 5
2 4 3
3 4 5
*/
