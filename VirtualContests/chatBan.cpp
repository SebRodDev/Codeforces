#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

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

void solve() {
    int k, x; cin >> k >> x;

    // factorials do not work they are not the clue

    // have to binary search

    // binary searching based on the number of messages -> number of elements at a layer = k(k + 1)/2
    int left = 0, right = 2LL * k - 1;

    int res = 1;

    if (x > k * k) {
        cout << right << "\n";
        return;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int amt = 0;
        if (mid <= k) {
            amt = (mid * (mid + 1)) / 2;
        } else {
            int remainingLayers = 2LL * k - mid;
            int totalSumElements = k * k;
            int unwrittenElements = (remainingLayers * (remainingLayers - 1)) / 2;
            amt = totalSumElements - unwrittenElements;
        }

        if (amt >= x) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
