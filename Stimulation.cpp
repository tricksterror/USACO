//Circular Barn http://www.usaco.org/index.php?page=viewproblem2&cpid=616#

#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) {
                cin >> x;
        }
        int ans = (int)1e9+7;
        for (int i = 0; i < n; i++) {
                int flg = 0;
                for (int j = i, k = 0; true; j++, k++) {
                        if (j > n-1) j = 0;
                        if (j == i && k != 0) break;
                        flg += (k*a[j]);
                }
                ans = min(ans, flg);
        }
        cout << ans << "\n";
}

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("cbarn.in", "r", stdin);
        freopen("cbarn.out", "w", stdout);

        solve();
        return 0;
}

