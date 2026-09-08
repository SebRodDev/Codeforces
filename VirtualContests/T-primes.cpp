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

const int MAX_PRIME = 1000005;
std::vector<bool> is_prime(MAX_PRIME, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_PRIME; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_PRIME; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

// 2. O(1) Check Function for random queries (X <= 1e12)
bool has_exactly_3_divisors(long long x) {
    if (x < 4) return false;

    // Find the integer square root
    long long root = std::sqrt(x);

    // Verify it is a perfect square AND the root is a prime number
    return (root * root == x) && is_prime[root];
}

void solve() {
    int n; cin >> n;
    sieve();

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        if (has_exactly_3_divisors(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;

    while (tt--) {
        solve();
    }
}
