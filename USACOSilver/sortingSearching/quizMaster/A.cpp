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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    const int M = 1e5;
    vector<int> factors[M + 1];

    // precompute factors
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i; j <= 1e5; j += i) {
            factors[j].push_back(i);
        }
    }

    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> a(n);

        for (auto& x : a) cin >> x;

        // think have to custom sort the data by some comparison 
        vector<int> freq(m + 1);

        sort(a.begin(), a.end());

        int amtCovered = 0;
        int res = 1e9;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && amtCovered < m) {

                // go through all broken down factors of this number
                for (int x : factors[a[j]]) {
                    if (x <= m) {
                        freq[x]++;

                        // mark this topic as covered
                        if (freq[x] == 1) amtCovered++;
                    }
                }

                j++;
            }

            if (amtCovered == m) res = min(res, a[j - 1] - a[i]);

            // now trying to shrink given we have found a valid window
            for (int x : factors[a[i]]) {
                if (x <= m) {
                    freq[x]--;

                    if (freq[x] == 0) amtCovered--;
                }
            }

        }
        if (res == 1e9) {
            cout << -1 << "\n";
        } else {
            cout << res << "\n";
        }
    }
}
