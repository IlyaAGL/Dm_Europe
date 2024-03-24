#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;

void dfs(int v) {
    for (int u : adj[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> prufer() {
    int n = adj.size();
    parent.resize(n);
    vector<int> deg(n);
    parent[n-1] = -1;
    dfs(n-1);

    int pos = -1;

    for (int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1 && pos == -1) {
            pos = i;
        }
    }

    vector<int> res(n - 2);
    int one = pos;

    for (int i = 0; i < n - 2; ++i) {
        int next = parent[one];
        res[i] = next;
        if (--deg[next] == 1 && next < pos) {
            one = next;
        } else {
            ++pos;
            while (deg[pos] != 1){
                ++pos;
            }
            one = pos;
        }
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    adj.resize(n);

    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> res = prufer();

    for(int c : res) {
        cout << c << " ";
    }
}

/*

13 14
16 25
18 19
21 22
24 25
27 28
11 12
6 7  
32 33
6 8  
22 33
20 21
36 37
20 23
4 6  
16 17
27 39
14 15
39 40
9 17
16 18
23 24
31 32
9 10
30 31
26 27
29 30
42 43
4 11
43 44
28 29
36 38
1 2
2 3
12 16
33 34
14 18
28 41
3 4
4 5
34 35
41 42
35 36

*/
