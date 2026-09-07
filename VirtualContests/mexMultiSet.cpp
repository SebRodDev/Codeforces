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
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int zeroCount = 0;
        vector<int> vec(n); for (auto &x: vec) {
            cin >> x;

            if (x == 0) zeroCount++;
        }
        if (zeroCount == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        bool seen_zero = false;
        for (int i = 0; i < n; i++) {
            if (vec[i] != 0) cout << 'C';
            else if (seen_zero) cout << 'B';
            else {
                seen_zero = true;
                cout << 'A';
            }
        }
        cout << "\n";
    }
}