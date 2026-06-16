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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // choose 1 integer to replace with integer of choice to get greatest gcd of all the numbers
    int n; cin >> n;

    vector<int> nums(n + 2);

    for (int i = 1; i <= n; i++) cin >> nums[i];

    vector<int> prefix(n + 2);
    vector<int> suffix(n + 2);

    // basically can change one number which means the otehr n - 1 can be whatever value possible and that is the gcd we have to use
    for (int i = 1; i <= n; i++) {
        prefix[i] = gcd(prefix[i - 1], nums[i]);
    }

    for (int i = n; i >= 1; i--) {
        suffix[i] = gcd(suffix[i + 1], nums[i]);
    }

    int res = 0;
    // computing the max gcd of all elements if we were to not consider the current element cause we know for remaining elements it has to hold so doing this
    // ensures that we can basically just convert the max index i to whatever to make sure it meets the maximized gcd of everything to left and to right
    for (int i = 1; i <= n; i++) {
        res = max(res, gcd(prefix[i - 1], suffix[i + 1]));
    } 

    cout << res << "\n";
}
