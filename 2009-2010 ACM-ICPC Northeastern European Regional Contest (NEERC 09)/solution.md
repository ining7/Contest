## B. Business Center

​	`上升a*u和下降b*d(a+b=n)`可以等效于`上升n*u后下降x*(u+d)`；

​	由于不能返回0层，所以当取模为0的时候应该取`u+d`

```C++
void solve() {
    int n, m; cin >> n >> m;
    int res = 0x7fffffff;
    while (m--) {
        int u, d; cin >> u >> d;
        int tmp = (n * u) % (u + d);
        if (!tmp) tmp = u + d;
        res = min(res, tmp);
    }
    cout << res << '\n';
}
```



## H. Headshot

​	俄罗斯轮盘赌问题

- 不rotate：由于对方先click了一次，中枪概率为`cnt_1 / sum`
- rotate：完全随机，中枪概率为`(n - sum) / n`

```C++
void solve(string s) {
    int n = s.length();
    int cnt_0 = 0, cnt_1 = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++sum;
            if (s[(i + 1) % n] == '0') ++cnt_0;
            else ++cnt_1;
        }
    }
    if (cnt_1 * n < (n - sum) * sum) cout << "SHOOT\n";
    else if (cnt_1 * n == (n - sum) * sum) cout << "EQUAL\n";
    else cout << "ROTATE\n";
}
```



## D. Database

​	求：是否存在a行和b行的c列和d列相同（重点在于如何清晰的维护和查询）

​	对于当前的字符串，对于所在的列中遍历所有行，同时对行列做键值对映射；当行对应的键值对已经存在，那么代表：对于当前行，已经存在另一行和当前行有两列的字符串相等。

```c++
void solve(int n, int m) {
    unordered_map<string, set<int>> mp[m + 1];
    string s; getline(cin, s);
    for (int i = 1; i <= n; ++i) {
        unordered_map<int, int> vis;
        getline(cin, s);
        int idx = 0; int l = s.length();
        for (int j = 1; j <= m; ++j) {
            string t = "";
            while (idx < l && s[idx] != ',') t += s[idx++];
            for (auto k : mp[j][t]) {
                if (vis[k]) {
                    cout << "NO\n";
                    cout << k << ' ' << i << '\n';
                    cout << vis[k] << ' ' << j << '\n';
                    return ;
                } 
                vis[k] = j;
            }
            mp[j][t].insert(i);
            ++idx;
        }
    }
    cout << "YES\n";
}
```



## F. Funny Language

​	优先队列

```c++
# Time limit exceeded on test 10
void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(m);
    for (int i = 0; i < m; ++i) cin >> s[i];
    sort(s.begin(), s.end());
    vector<unordered_map<int, int>> cnt(m); 
    for (int i = 0; i < m; ++i) for (int j = 0, l = s[i].length(); j < l; ++j) ++cnt[i][s[i][j] - 'A'];
    priority_queue<pair<int, string>> q;
    q.push({0, ""});
    while (n) {
        pair<int, string> nw = q.top(); q.pop();
        auto rg = equal_range(s.begin(), s.end(), nw.second);
        if (nw.second != "" && rg.first == rg.second) {
            cout << nw.second << '\n';
            --n;
        }
        unordered_map<int, int> tmp;
        for (int j = 0, l = nw.second.length(); j < l; ++j) ++tmp[nw.second[j] - 'A'];
        for (string i = nw.second + 'A', ed = nw.second + 'Z'; i <= ed; ++i.back()) {
            ++tmp[i.back() - 'A'];
            nw.first = 0;
            for (int j = 0; j < m; ++j) {
                int f = 1;
                for (int c = 0; c < 26; ++c) {
                    if (tmp[c] > cnt[j][c]) f = 0;
                }
                if (f) ++nw.first;
            }
            q.push({nw.first, i});
            --tmp[i.back() - 'A'];
        }
    }
}
```

​	对于超时问题：将`vector<unordered_map<int, int>> cnt(m); `改成全局的二维数组即可

```C++
const int M = 1010;
int cnt[M][26];
```
