
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n);

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int u) {
            if (u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        void merge(int u, int v) {
            u = find(u);
            v = find(v);
            if (u != v) {
                if (rank[u] > rank[v]) {
                    parent[v] = u;
                } else {
                    parent[u] = v;
                    if (rank[u] == rank[v]) {
                        rank[v]++;
                    }
                }
            }
        }
};

bool comp(Edge& e1, Edge& e2) {
    return e1.weight < e2.weight;
}

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), comp);

    DSU ds(n);
    vector<Edge> mst;
    int totalWeight = 0;

    for (Edge edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            mst.push_back(edge);
            cout << edge.u + 1 << " " << edge.v + 1 << " " << edge.weight << "\n";
            ds.merge(edge.u, edge.v);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        edges[i].u = a - 1;
        edges[i].v = b - 1;
        edges[i].weight = weight;
    }
    cout << "---------------\n";

    vector<Edge> mst = kruskal(n, edges);

    return 0;
}
