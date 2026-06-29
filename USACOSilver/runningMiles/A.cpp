#include </Users/sebastianrodriguez/stdc++.h>
//#include <bits/stdc++.h>

using namespace std;
#define int long long 

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

    // have a left and right point -> sounds like a window problem since it has to be a continous piece
    // at least 3 sights you go through, sum 3 most beautiful - distance = maximized
    //
    // b_i1 + b_i2 + b_i3 - (r - l) is max
    // define p as prefix sum
    // p[r] - p[l] - (r - l)
    // (p[r] - r) - (p[l] + l)
    
    // fixing the right most point and just finding the min possible on left to subtract from window?
    
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> b(n + 1);
        vector<int> prefixBest(n + 1);
        vector<int> suffixBest(n + 1);

        for (int i = 1; i <= n; i++) cin >> b[i];

        // computing the best left
        prefixBest[2] = b[1] + 1;
        for (int i = 2; i <= n - 1; i++)
            prefixBest[i + 1] = max(b[i] + i, prefixBest[i]);

        // computing best right
        suffixBest[n - 1] = b[n] - n;
        for (int i = n - 1; i >= 2; i--)
            suffixBest[i - 1] = max(b[i] - i, suffixBest[i]);

        int res = 0;
        for (int i = 2; i <= n - 1; i++)
            res = max(res, suffixBest[i] + b[i] + prefixBest[i]);

        cout << res << "\n";
    }
}

