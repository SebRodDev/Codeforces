#include </Users/sebastianrodriguez/stdc++.h>
//#include <bits/stdc++.h>

using namespace std;

#define ll long long 

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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = 1e9 + 9; 
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
    Mod() : x(1) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	} Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    vector<Mod> pw(5010);
    pw[0] = 1;
    vector<Mod> inversepw(5010);
    inversepw[0] = 1;
    ll A = 53;

    for (int i = 1; i <= 5009; i++) {
        pw[i] = pw[i - 1] * A;
        inversepw[i] = pw[i].invert(pw[i]);
    }

    vector<Mod> hashes(s.size());
    vector<Mod> hashesBackwards(s.size());

    hashes[0] = s[0] - 'a' + 1;

    for (int i = 1; i < s.size(); i++) {
        hashes[i] = hashes[i - 1] + pw[i] * (s[i] - 'a' + 1);
    }

    // can just do every single window
    hashesBackwards[s.size() - 1] = s[s.size() - 1] - 'a' + 1;
    for (int i = s.size() - 2; i >= 0; i--) {
        hashesBackwards[i] = hashesBackwards[i + 1] + pw[s.size() - i - 1] * (s[i] - 'a' + 1);
    }

    // do the n^2 precomp
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
    vector<vector<int>> palindrome(s.size(), vector<int>(s.size()));
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            Mod left = (i == 0) ? hashes[j] : hashes[j] - hashes[i - 1];
            left = left * inversepw[i];

            Mod right = (j == s.size() - 1) ? hashesBackwards[i] : hashesBackwards[i] - hashesBackwards[j + 1];
            right = right * inversepw[s.size() - 1 - j];

            if (left.x == right.x) palindrome[i][j] = 1;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + palindrome[i][j];
        }
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << dp[r][r] - dp[l - 1][r] - dp[r][l - 1] + dp[l - 1][l - 1] << "\n";
    }
}
