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