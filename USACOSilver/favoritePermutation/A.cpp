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

    // can only swap backwards L and R forward
    // first character = R, last = L guaranteed
    // unique permutation
    //
    // can it be sorted in non-decreasing order
    
    int t; cin >> t;

    while (t--) {
        int n, q; cin >> n >> q;

        vector<int> a(n + 1);
        vector<int> runMax(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            runMax[i] = max(runMax[i - 1], a[i]);
        }

        vector<char> s(n + 1);
        for (int i = 1; i <= n; i++) cin >> s[i];
        vector<bool> good(n + 1);

        int bad = 0;
        for (int i = 1; i <= n; i++) {

            if (runMax[i] == i) {
                good[i] = true;
            } else {
                good[i] = false;
            }

            if (s[i - 1] == 'L' && s[i] == 'R' && !good[i - 1]) {
                bad++;
            }
        }

        while (q--) {
            int index; cin >> index;

            // basically a bunch of case work i didnt see right away
            if (s[index - 1] == 'L' && s[index] == 'R' && !good[index - 1]) bad--;
            if (s[index] == 'L' && s[index + 1] == 'R' && !good[index]) bad--;

            s[index] = (s[index] == 'R') ? 'L' : 'R';

            // update the prev and next
            if (s[index - 1] == 'L' && s[index] == 'R' && !good[index - 1]) {
                bad++;
            }

            if (s[index] == 'L' && s[index + 1] == 'R' && !good[index]) {
                bad++;
            }

            if (bad > 0) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
        }
    }
}
