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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(m); for (int i = 0; i < m; i++) cin >> b[i];

        // bea always goes first (a)

        // difference array to see how long they can last
        vector<int> diffOne(n + 1), diffTwo(m + 1);

        bool canContinue = true;
        for (int i = 1; i <= n; i++) {
            diffOne[i] = diffOne[i - 1];

            if (i < n) {
                int time = a[i - 1] - a[i] + 1;

                if (time > 0 && canContinue) {
                    diffOne[i] += time;
                } else {
                    canContinue = false;
                }
            } else if (i == n && canContinue) {
                // case where we reached the end
                diffOne[i] += a[i - 1];
            }
        }

        bool secondContinue = true;

        for (int i = 1; i <= m; i++) {
            diffTwo[i] = diffTwo[i - 1];

            if (i < m) {
                int time = b[i - 1] - b[i] + 1;

                if (time > 0 && secondContinue) {
                    diffTwo[i] += time;
                } else {
                    secondContinue = false;
                }
            } else if (i == m && secondContinue) {
                diffTwo[i] += b[i - 1];
            }
        }

        if (diffOne[n] >= diffTwo[m]) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
