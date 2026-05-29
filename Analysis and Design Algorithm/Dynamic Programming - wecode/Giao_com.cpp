#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int LOG = 18;
const int MAXN =  2e5 + 5;
int depth[MAXN];
int up[LOG][MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int root) {
    stack<pair<int,int>> st;
    st.push({root, 0});
    while (!st.empty()) {
        int v = st.top().first;
        int p = st.top().second;
        st.pop();
        if (visited[v]) continue;
        visited[v] = true;
        up[0][v] = p;
        for (int u : adj[v]) {
            if (!visited[u]) {
                depth[u] = depth[v] + 1;
                st.push({u, v});
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++)
        if ((diff >> j) & 1)
            u = up[j][u];
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--)
        if (up[j][u] != up[j][v]) {
            u = up[j][u];
            v = up[j][v];
        }
    return up[0][u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    for (int j = 1; j < LOG; j++)
        for (int v = 1; v <= n; v++)
            up[j][v] = up[j-1][up[j-1][v]];
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[l] << "\n";
    }
    
    return 0;
}