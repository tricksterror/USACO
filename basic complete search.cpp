// Cow Gymnastics  http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n, k;
        cin >> k >> n;
        vector<vector<int>> a(k, vector<int>(n));
        for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }
        set<pair<int,int>> s;
        for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                        for (int l = j+1; l < n; l++) {
                                s.insert({a[i][j], a[i][l]});
                        }
                }
        }
        int ans = 0;
        for (auto x : s) {
                if (s.find({x.second, x.first}) == s.end()) ans++;
        }
        cout << ans << "\n";
}

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("gymnastics.in", "r", stdin);
        freopen("gymnastics.out", "w", stdout);

        solve();
        return 0;
}














#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n, m;
        cin >> n >> m;
        vector<string> a(2*n);
        for (int i = 0; i < (2*n); i++) {
                cin >> a[i];
        }
        int ans;
        for (int i = 0; i < m; i++) {
                set<char> s, ns;
                for (int j = 0; j < (2*n); j++) {
                        if (j < n) s.insert(a[j][i]);
                        else ns.insert(a[j][i]);
                }
                bool ok = false;
                for (char x : s) {
                        if (ns.count(x) != 0) {
                                ok = true;
                                break;
                        }
                }
                if (!ok) {
                        ans = i;
                        break;
                }
        }
        cout << ans << "\n";
}

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("cownomics.in", "r", stdin);
        freopen("cownomics.out", "w", stdout);

        solve();
        return 0;
}
