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