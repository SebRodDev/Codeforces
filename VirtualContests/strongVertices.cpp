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
    vector<int> b(n); for (auto& i : b) cin >> i;

    vector<pair<int, int>> differences;

    for (int i = 0; i < n; i++) {
        differences.push_back({a[i] - b[i], i + 1});
    }

    sort(differences.begin(), differences.end(), [](const auto& x, const auto& y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    vector<int> res;
    res.push_back(differences[0].second);
    int largest = differences[0].first;
    for (int i = 1; i < n; i++) {
        if (differences[i].first == largest) {
            res.push_back(differences[i].second);
        }
    }

    cout << res.size() << "\n";
    for (auto& x : res) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
