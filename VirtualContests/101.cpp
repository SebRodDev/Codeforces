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

        vector<int> v(n); for (auto& x : v) cin >> x;

        int left = 0;

        int furthestLeftIndex = -1;

        while (left < n) {
            if (v[left] == -1 || v[left] == 1) {
                furthestLeftIndex = left;
                break;
            }

            left++;
        }

        int right = n - 1;

        int furthestRightIndex = -1;

        while (right > left) {
            if (v[right] == -1 || v[right] == 1) {
                furthestRightIndex = right;
                break;
            }

            right--;
        }

        if (furthestLeftIndex != -1) {
            v[furthestLeftIndex] = 1;
        }

        if (furthestRightIndex != -1) {
            v[furthestRightIndex] = 1;
        }

        for (int i = furthestLeftIndex + 1; i < furthestRightIndex; i++) if (v[i] == -1) v[i] = 0;

        for (int num : v) {
            cout << num << ' ';
        }

        cout << "\n";
    }
}
