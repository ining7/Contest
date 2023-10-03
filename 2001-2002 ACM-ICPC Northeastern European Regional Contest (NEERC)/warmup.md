[Samara Interacademic Programming Contest Russia, Samara, March 18, 2012](https://codeforces.com/gym/100030) 

## B. Epic Battle

​	`x-1`表示当前堆能进行拆分的操作次数，操作次数为odd时先手赢，反之反手赢。

```c++
void solve() {
    int n; cin >> n;
    int sum = 0;
    while (n--) {
        int x; cin >> x;
        sum += --x;
    }
    cout << (sum % 2 ? "Constantine" : "Mike") << '\n';
}
```
