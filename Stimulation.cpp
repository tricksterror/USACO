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

// Censoring  http://www.usaco.org/index.php?page=viewproblem2&cpid=526

//tle soluition

#include <bits/stdc++.h>
using namespace std;

string s, t;
int b = 0;

void dope() {
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
                if (s[i] == t[0]) {
                        v.push_back(i);
                        b++;
                }
        }
        for (int i = 0; i < v.size(); i++)  {
                string st = s.substr(v[i], t.size());
                if (t == st) {
                        s.erase(s.begin() + v[i], s.begin() + v[i] + t.size());
                        break;
                }
        }
        b--;
}

void solve() {
        cin >> s >> t;
        dope();
        while (b != 0) dope();
        cout << s << "\n";
}

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("censor.in", "r", stdin);
        freopen("censor.out", "w", stdout);

        solve();
        return 0;
}

//correct soln

#include <bits/stdc++.h>
using namespace std;

void solve() {
        string s, t;
        cin >> s >> t;
        string r;
        for (int i = 0; i < s.size(); i++) {
                r += s[i];
                if (r.size() >= t.size() && r.substr(r.size() - t.size()) == t) {
                        r.resize(r.size() - t.size());
                }
        }
        cout << r << "\n";
}

signed main()
{
        std::ios_base::sync_with_stdio(NULL);
        cin.tie(nullptr); cout.tie(nullptr);

        freopen("censor.in", "r", stdin);
        freopen("censor.out", "w", stdout);
        
        solve();
        return 0;
}
