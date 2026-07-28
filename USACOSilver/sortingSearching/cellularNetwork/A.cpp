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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    // a values are sorted
    vector<int> a(n);
    vector<int> b(m);

    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    // finding the smallest r such that given all cell stations they can cover all 

    // bin search from every city to find closest cell station and just continously take min?
    int r = 0;
    for (int i = 0; i < n; i++) {
        auto closestCell = lower_bound(b.begin(), b.end(), a[i]);


        if (closestCell != b.begin() && closestCell != b.end()) {
            auto checkSmaller = closestCell - 1;

            if (checkSmaller != b.end() && abs(*checkSmaller - a[i]) < abs(*closestCell - a[i])) {
                closestCell = checkSmaller;
            }
        } else if (closestCell == b.end()) {
            closestCell--;
        }

        r = max(r, abs(*closestCell - a[i]));

    }

    cout << r << "\n";

}
