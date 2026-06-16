#include <bits/stdc++.h>
#define int long long

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // can quickly query between ranges with the prefix sum

    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;

        vector<int> nums(n + 1);

        for (int i = 1; i <= n; i++) {
            nums[i] = s[i - 1] - '0';
            nums[i] += nums[i - 1];
        }

        unordered_map<int, int> dp;

        for (int i = 0; i <= n; i++) {
            dp[nums[i] - i]++;
        }

        int res = 0;
        for (auto& [key, value] : dp) {
            res += (value * (value - 1) / 2);
        }

        cout << res << "\n";
    }
}
