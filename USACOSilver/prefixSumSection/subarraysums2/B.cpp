#include <bits/stdc++.h>
#define int long long 

using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x; vector<int> a(n + 1);

    // p[j] - p[i - 1] == x
    // p[j] - x = p[i - 1] -> query
    // p[i] = p[j] - x 
    map<int, int> d;
    d[0]++;
    int r = 0;

    // basically fixing the farthest right point and seeing if something exists on the left for it
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1];
        r += d[a[i] - x];
        d[a[i]]++;
    }

    cout << r << "\n";
}
