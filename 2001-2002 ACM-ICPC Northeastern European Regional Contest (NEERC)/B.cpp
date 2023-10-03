#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

void solve() {
    vector<double> aa(3), bb(2);
    cin >> aa[0] >> aa[1] >> aa[2] >> bb[0] >> bb[1];
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    double a, b, c, d, e; 
    a = aa[0], b = aa[1];
    d = bb[0], e = bb[1];

    if (a <= d && b <= e) {
        cout << "YES\n";
        return ;
    }

    double dd = pi / 100000;
    double st = acos(d / b);
    double ed = asin(e / b);

    for (double aph = st + dd; aph < ed; aph += dd) {
        if ((d - b * cos(aph)) / sin(aph) >= a && (e - b * sin(aph)) / cos(aph) >= a) {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
}

signed main() {
    freopen("bricks.in", "r", stdin);
    freopen("bricks.out", "w", stdout);
    solve();
    return 0;
}