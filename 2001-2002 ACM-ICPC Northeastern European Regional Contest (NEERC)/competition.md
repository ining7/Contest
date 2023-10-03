#### [2001-2002 ACM-ICPC Northeastern European Regional Contest (NEERC)](https://codeforces.com/gym/100002)

## D. Decoding Task

```c++
#include <bits/stdc++.h>

using namespace std;

int char2int(char c) {
    if (c <= '9') return (c - '0');
    return (c - 'A' + 10);
}

char int2char(int x) {
    if (x <= 9) return ('0' + x);
    return (x - 10 + 'A');
}

void solve(string a, string b) {
    int n = a.length() / 2;
    vector<int> aa(n), bb(n + 1), cc(n + 1);
    for (int i = 0; i < n; ++i) {
        aa[i] = 16 * char2int(a[2 * i]) + char2int(a[2 * i + 1]);
        bb[i] = 16 * char2int(b[2 * i]) + char2int(b[2 * i + 1]);
    }
    bb[n] = 16 * char2int(b[2 * n]) + char2int(b[2 * n + 1]);
    cc[0] = 32 ^ bb[0];
    for (int i = 1; i <= n; ++i) {
        cc[i] = cc[i - 1] ^ aa[i - 1] ^ bb[i];
    }
    for (int i = 0; i <= n; ++i) {
        cout << int2char(cc[i] / 16) << int2char(cc[i] % 16);
    }
    cout << '\n';
}

int main() {
    freopen("decode.in", "r", stdin);
    freopen("decode.out", "w", stdout);
    string a, b;
    while (cin >> a >> b) solve(a, b);
    return 0;
}
```



## C. Cricket Field

```C++
#include <bits/stdc++.h>

using namespace std;

int n, w, h;
vector<int> px, py;
vector<pair<int, int>> ps;

bool check(int x, int y, int l) {
    for (auto i : ps) {
        if (x < i.first && x + l > i.first && y < i.second && y + l > i.second) return false;
    }
    return true;
}

void solve() {
    cin >> n >> w >> h;
    px.push_back(0);
    px.push_back(w);
    py.push_back(0);
    py.push_back(h);
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        px.push_back(x);
        py.push_back(y);
        ps.push_back({x, y});
    }
    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());
    sort(py.begin(), py.end());
    py.erase(unique(py.begin(), py.end()), py.end());
    int xx = 0, yy = 0, ll = 0;
    for (auto x : px) {
        for (auto y : py) {
            int l = 0;
            int r = min(w - x, h - y);
            int res = 0;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (check(x, y, mid)) {
                    res = mid;
                    l = mid;
                } else r = mid - 1;
            }
            if (res > ll) {
                ll = res;
                xx = x;
                yy = y;
            }
        }
    }
    cout << xx << ' ' << yy << ' ' << ll << '\n';
}

signed main() {
    freopen("cricket.in", "r", stdin);
    freopen("cricket.out", "w", stdout);
    solve();
    return 0;
}
```



## B. Bricks

```C++
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
```



## F. Folding



## A. Amusing Numbers


