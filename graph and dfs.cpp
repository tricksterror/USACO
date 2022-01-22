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
