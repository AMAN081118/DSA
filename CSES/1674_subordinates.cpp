#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ans;

int dfs(int node) {

  if (adj[node].size() == 0) {
    return 0;
  }
  for (auto ch : adj[node]) {
    ans[node] += 1 + dfs(ch);
  }
  return ans[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  adj.resize(n + 1);
  ans.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    int v;
    cin >> v;
    adj[v].push_back(i);
  }
  ans[1] = dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}