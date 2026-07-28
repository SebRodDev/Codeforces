#include <bits/stdc++.h>

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

bool can(int mid, vector<int>& a, int t) {
    int made = 0;

    // just assign as many as you can for each index
    for (int i = 0; i < a.size(); i++) {
        made += (mid / a[i]);

        if (made >= t) return true;
    }

    return made >= t;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, t; cin >> n >> t;

    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    int l = 0, r = 1e18;

    int res = 1e18;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid, a, t)) {
            res = min(res, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << '\n';
    
}
