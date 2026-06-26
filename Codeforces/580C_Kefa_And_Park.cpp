#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> cats;
int ans = 0;

void dfs(int node, int cat, int parent) {
  if (cats[node] == 1) {
    cat++;
  } else {
    cat = 0;
  }
  if (cat > m) {
    return;
  }
  bool isLeaf = true;
  for (int ch : adj[node]) {
    if (ch == parent) {
      continue;
    }
    isLeaf = false;
    dfs(ch, cat, node);
  }
  if (isLeaf)
    ans++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  adj.resize(n + 1);
  cats.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> cats[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 0);

  cout << ans << endl;
}