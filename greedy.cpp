//Mad Scientist http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

#include <bits/stdc++.h>
using namespace std;

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("breedflip.in", "r", stdin);
        freopen("breedflip.out", "w", stdout);

        int n;
        string a, b;
        cin >> n >> a >> b;
        int ans = 0;
        bool ok = false;
        for (int i = 0; i < n; i++) {
                if (b[i] != a[i]) ok = true;
                else {
                        if (ok) {
                                ans++;
                                ok = false;
                        }
                }
        }
        cout << ans << "\n";
        return 0;
}
