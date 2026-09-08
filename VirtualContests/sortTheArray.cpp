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

    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    // count all of the start and end positions that arent in increasing
    int l = -1;
    int r = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            if (l == -1) {
                l = i - 1;
            }

            r = i;
        }
    }

    // already sorted case
    if (l == -1 && r == -1) {
        cout << "yes\n" << "1 1\n";
        return;
    }

    reverse(a.begin() + l, a.begin() + r + 1);

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "no\n"; return;
        }
    }

    cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;

    while (tt--) {
        solve();
    }
}
