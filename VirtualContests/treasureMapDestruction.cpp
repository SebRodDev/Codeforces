#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

using namespace std;
#define int long long

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

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> diff(n + 1);

        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                diff[max(0LL, i-v[i] + 1)]++;
                diff[min(n, i + v[i])]--;
            }
        }

        vector<bool> forced(n);
        int curAmount = 0;

        for (int i = 0; i < n; i++) {
            curAmount += diff[i];
            forced[i] = curAmount > 0;
        }

        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            if (v[i] >= 0) {
                if (i - v[i] >= 0 && !forced[i - v[i]]) continue;
                if (i + v[i] < n && !forced[i + v[i]]) continue;
                possible = false;
            }
        }

        if (!possible) {
            cout << -1 << "\n";
        } else {
            for (auto x : forced) {
                cout << !x;;
            }
            cout << "\n";
        }
    }
}
