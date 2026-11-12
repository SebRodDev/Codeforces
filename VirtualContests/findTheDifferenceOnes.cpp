#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

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

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& i : a) cin >> i;

    // have to precompute the answer for every index and then just query that based on the range
    vector<int> prevDifference(n, -1);
    int diffPrev = -1;

    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            diffPrev = i - 1;
        }

        prevDifference[i] = diffPrev;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l ,r; cin >> l >> r; l--; r--;

        if (prevDifference[r] >= l) {
            cout << r + 1 << " " << prevDifference[r] + 1 << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
        cout << "\n";
    }
}
