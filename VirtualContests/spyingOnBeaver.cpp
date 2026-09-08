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
    int n, m; cin >> n;

    vector<int> depth(n, 0);
    vector<int> p(n, -1);
    for (int v = 1; v < n; ++v) {
        cin >> p[v];
        --p[v];
        depth[v] = depth[p[v]] + 1;
    }

    cin >> m;
    if (m == 0) {
        cout << "0";
        return;
    }

    // finding which ones actually have the camera
    vector<int> pt(m);

    bool root = false;
    for (int i = 0; i < m; ++i) {
        cin >> pt[i];
        --pt[i];
        if (pt[i] == 0) {
            root = true;
        }
    }

    cout << m - 1 << ' ';

    int toSkip;
    if (root == true) {
        toSkip = 0;
    } else {
        int minDepth = 1e9;
        int closest = -1;
        for (int v : pt) {
            if (minDepth > depth[v]) {
                minDepth = depth[v];
                closest = v;
            }
        }

        toSkip = closest;

    }

    for (int v : pt) {
        if (v != toSkip) {
            cout << v + 1 << " ";
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
    }
}
