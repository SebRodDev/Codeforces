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
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> suffixCheck(n);
        suffixCheck[n - 1] = v[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixCheck[i] = min(suffixCheck[i + 1], v[i]);
        }

        bool found = false;
        int first, second, third;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (v[i] < v[j] && v[j] > suffixCheck[j + 1]) {
                    found = true;
                    first = i;
                    second = j;
                    third = j + 1;
                }
            }

            if (found) break;
        }

        if (found) {
            cout << "YES\n" << first + 1 << " " << second + 1 << " " << third + 1 << endl;
        } else {
            cout << "NO\n";
        }
    }
}
