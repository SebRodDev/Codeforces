#include <bits/stdc++.h>

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

    int n, m, q; cin >> n >> m >> q;

    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m); for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> odd_b(m), even_b(m);

    for (int i = 0; i < m; i++) {
        if (i & 1) {
            odd_b[i] = b[i];
        } else {
            even_b[i] = b[i];
        }

        if (i > 0) {
            odd_b[i] += odd_b[i - 1];
            even_b[i] += even_b[i - 1];
        }
    }

    vector<int> b_segment(m - n + 1);

    // computing b values for entire array in a prefix sum format where we consider
    // the polarity of the + and - and account for those appropriately based on what index we 
    // started at
    for (int i = 0; i <= (m - n); i++) {
        int sum_even = even_b[i + n - 1] - (i ? even_b[i - 1] : 0);
        int sum_odd = odd_b[i + n - 1] - (i ? odd_b[i - 1] : 0);

        if (i & 1) {
            b_segment[i] = sum_odd - sum_even;
        } else {
            b_segment[i] = sum_even - sum_odd;
        }
    }

    sort(b_segment.begin(), b_segment.end());

    int sum_a = 0;

    for (int i = 0; i < n; i++) {
        sum_a += (i & 1 ? -a[i] : a[i]);
    }

    auto query = [&](auto it) {
        auto loc = it;

        if (loc == b_segment.end()) {
            cout << llabs(*(prev(loc)) - sum_a) << "\n";
        } else {
            int ans = *loc - sum_a;

            if (loc != prev(b_segment.end())) {
                ans = min(ans, llabs(*(next(loc)) - sum_a));
            }

            if (loc != b_segment.begin()) {
                ans = min(ans, llabs(*(prev(loc)) - sum_a));
            }
            cout << ans << "\n";
        }
    };

    // binary searching on j? -> unsure
    // when making a change all you care about to the total sum for that number is whether
    // it is even or odd if its even they cancel each other out if odd then depends on whether
    // the first operation at index l was + or - and that appropriately changes the sum to entire range
    // updates are applied to every possible a value thus this updates every f value the same way
    // this efficiently computes the updated values of our f array 
    query(lower_bound(b_segment.begin(), b_segment.end(), sum_a));
    while (q--) {
        int l, r, x; cin >> l >> r >> x;

        // if odd
        if ((r - l + 1) & 1) {
            if (l & 1) {
                sum_a += x;
            } else {
                sum_a -= x;
            }
        }

        // want to minimize abs(sum_a - seg_b[j]) as this will get us as min as possible
        query(lower_bound(b_segment.begin(), b_segment.end(), sum_a));
    }
}
