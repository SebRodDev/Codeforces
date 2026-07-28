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

    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<int> longestA(2 * n + 1, 0);
        vector<int> longestB(2 * n + 1, 0);

        int count = 1;
        longestA[a[0]] = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                count++;
            } else {
                count = 1;
            }

            longestA[a[i]] = max(longestA[a[i]], count);
        }

        count = 1;
        longestB[b[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (b[i] == b[i-1]) {
                count++;
            } else {
                count = 1;
            }

            longestB[b[i]] = max(longestB[b[i]], count);
        }

        // now going through both and computing result
        long long res = 0;
        for (int i = 0; i <= 2 * n; i++) {
            float cur = longestA[i] + longestB[i];
            //cout << "cur: " << cur << "\n";
            res = fmax(res, cur);
        }

        cout << res << "\n";
    }
}
