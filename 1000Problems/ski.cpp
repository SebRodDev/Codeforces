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

#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define eb emplace_back
#define f first
#define s second
#define lep(i,a,b) for (int i = (a); i < (b); i++)
#define rep(i,a,b) for (int i = (a); i > (b); i--)

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    // looks like sliding window
    while (t--) {
        int n, k, q; cin >> n >> k >> q;

        // reading in input
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];


        long long res = 0;
        long long longest = 0;

        // basically just when we have a valid longest then we have to consider all previous such that current element - minimum length of window + 1 because of inclusive range
        // by subtracting our window size and we have exceeded k then we know that subtracting the min window size will tell us how many other windows including this element we will
        // have this value and then we have to add one to consider the min window size as well
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= q) {
                longest++;

                if (longest >= k) {
                    res += (longest - k + 1);
                } 
            } else {
                longest = 0;
            }
        }


        cout << res << "\n";

    }
}
