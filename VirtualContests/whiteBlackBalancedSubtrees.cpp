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

// (white count, black count)
pair<int, int> dfs(int currentNode, unordered_map<int, vector<int>>& adj, string& mode, int& res) {
    int white = 0, black = 0;

    if (mode[currentNode - 1] == 'B') {
        black++;
    } else {
        white++;
    }

    for (int outgoing : adj[currentNode]) {
        pair<int, int> outCount = dfs(outgoing, adj, mode, res);
        white += outCount.first;
        black += outCount.second;
    }

    // mark that at this node the black and white counts are equal
    if (white == black) {
        res++;
    }

    return {white, black};
}

void solve() {
    int n; cin >> n;

    unordered_map<int, vector<int>> parents;

    for (int i = 2; i <= n; i++) {
        int p; cin >> p;

        parents[p].push_back(i);
    }

    string s; cin >> s;
    int res = 0;
    dfs(1, parents, s, res);
    cout << res << "\n";
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
