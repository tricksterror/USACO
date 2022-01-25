//Milk Factory http://www.usaco.org/index.php?page=viewproblem2&cpid=940

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[110];
vector<bool> vis(110, false);

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);
        #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        #endif
        freopen("factory.in", "r", stdin);
        freopen("factory.out", "w", stdout);

        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
                int a, b;
                cin >> a >> b;
                adj[a].emplace_back(b);
        }
        int cnt = 0, root;
        for (int i = 1; i <= n; i++) {
                if (adj[i].size() == 0) {
                        cnt++;
                        root = i;
                }
        }
        if (cnt == 0 || cnt > 1) {
                cout << -1 << "\n";
                return 0;
        }
        for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;
                int flg = i;
                while (adj[flg].size() != 0) {
                        if (vis[flg]) {
                                flg = root;
                                break;
                        }
                        vis[flg] = true;
                        flg = adj[i][0];
                }
                if (flg != root) {
                        cout << -1 << "\n";
                        return 0;
                }
        }
        cout << root << "\n";
        return 0;
}

//Building Roads  https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N, false);

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex) {
        vis[vertex] = true;
        current_cc.push_back(vertex);
        for (int child : g[vertex]) {
                if (vis[child]) continue;
                dfs(child);
       }
}

signed main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        #endif
        
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
                int v1, v2; 
                cin >> v1 >> v2;
                g[v1].push_back(v2); 
                g[v2].push_back(v1);
        }
        for (int i = 1; i <= n; i++) {
                if(vis[i]) continue;
                current_cc.clear();
                dfs(i); 
                cc.push_back(current_cc);
        }
        cout << cc.size() - 1 << "\n";
        for (int i = 1; i < cc.size(); i++) {
                cout << cc[i-1][0] << " " << cc[i][0] << "\n";
        } 
        return 0;
}
