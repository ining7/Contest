#### [2002-2003 Winter Petrozavodsk Camp, Andrew Stankevich Contest 1 (ASC 1)](https://codeforces.com/gym/100199)

## A.  Chinese Girls’ Amusement

​	数论；打表

```c++
bool isEven(string s) {
    return (s.back() - '0') % 2 == 0;
}

string sub(string s, int x) {
    string res = s;
    int idx = s.length() - 1;
    if (res[idx] - '0' >= x) res[idx] -= x;
    else {
        res[idx] += 10 - x;
        --idx;
        while (idx >= 0 && res[idx] == '0') {
            res[idx--] = '9';
        }
        --res[idx];
    }
    return res;
}

string divideByTwo(string s) {
    string res;
    int ls = 0;
    for (int i = 0, l = s.length(); i < l; ++i) {
        int nw = (ls * 10 + (s[i] - '0')) / 2;
        ls = (s[i] - '0') % 2;
        res += (char)(nw + '0');
    }
    while (res.length() > 1 && res[0] == '0') res.erase(res.begin());
    return res;
}

int modFour(string s) {
    if (s.length() == 1) return (s[0] - '0') % 4;
    return ((s[s.length() - 2] - '0') * 10 + (s[s.length() - 1] - '0')) % 4;
}

void solve(string n) {
    string tmp = divideByTwo(n);
    if ((n.length() > 1 || (n[0] > '2' && n.length() == 1)) && modFour(sub(n, 2)) == 0) tmp = sub(tmp, 2);
    if (modFour(n) == 0) tmp = sub(tmp, 1);
    cout << tmp << '\n';
}
```



## D. Matrix Multiplication

```C++
void solve() {
    int n, m; cin >> n >> m;
    set<int> mp[n + 1];
    while (m--) {
        int u, d; cin >> u >> d;
        mp[u].insert(d);
        mp[d].insert(u);
    } 
    int res = 0;
    for (int i = 1; i <= n; ++i) res += mp[i].size() * mp[i].size();
    cout << res << '\n';
}
```



## E. Nice Patterns Strike Back

​	对于2*2的条件，上一行的状态会影响到下一行的方案，容易想到是动态规划；观察到M很小而N很大，按行递推可以使用矩阵快速幂加速。(N很大懒得处理了用python了)

```python
M = 5
SZ = 1 << M

def check(x, y, m):
    for i in range(m - 1):
        if ((x >> i) & 3 == 3) and ((y >> i) & 3) == 3:
            return False
        if ((x >> i) & 3 == 0) and ((y >> i) & 3) == 0:
            return False
    return True

def matmul(a, b, sz, p):
    tmp = [[0 for _ in range(sz)] for _ in range(sz)]
    for i in range(sz):
        for j in range(sz):
            for k in range(sz):
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % p
    return tmp

def solve(fin, fout):
    n, m, p = map(int, fin.readline().split())
    sz = 1 << m
    f = [1 for _ in range(sz)]
    mat = [[0 for _ in range(sz)] for _ in range(sz)]
    res = [[0 if i != j else 1 for j in range(sz)] for i in range(sz)]
    for i in range(sz):
        for j in range(sz):
            if check(i, j, m):
                mat[i][j] = 1
    n -= 1
    while n:
        if n & 1:
            res = matmul(res, mat, sz, p)
        mat = matmul(mat, mat, sz, p)
        n >>= 1
    ans = 0
    for i in range(sz):
        for j in range(sz):
            ans = (ans + res[i][j] * f[j]) % p
    fout.write(str(ans) + '\n')

if __name__ == "__main__":
    with open("nice.in", "r") as fin, open("nice.out", "w") as fout:
        solve(fin, fout)
```



## C. New Year Bonus Grant

