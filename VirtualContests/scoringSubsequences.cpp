#include <bits/stdc++.h>

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

    // so we are basically splitting up to some point and then trying to find the largest score at that ending index

    for (int i = 0; i < n; i++) {
        int l = 1;
        int r = i + 1;

        while (l <= r) {
            int mid = (r + l) / 2;

            // checking that we are getting a positive fraction
            if (a[i - mid + 1] >= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << r << " ";

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}