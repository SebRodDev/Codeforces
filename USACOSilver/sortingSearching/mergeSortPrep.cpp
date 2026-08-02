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

    // basically just like can do it but have to optimize after

    int n; cin >> n;

    vector<int> a(n); for (auto &i: a) cin >> i;

    // initial implementation was TLE
    // numbers being distinct should help
    // do you just have to jump by upper_bound?

    // must use a set for sure

    vector<vector<int>> groups;
    vector<int> tails;

    for (int i =0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), a[i], greater<int>());

        if (it == tails.end()) {
            groups.push_back({a[i]});
            tails.push_back(a[i]);
        } else {
            int index = it - tails.begin();
            groups[index].push_back(a[i]);
            tails[index] = a[i];
        }
    }

    for (auto& group : groups) {
        for (int i = 0; i < group.size(); i++) {
            cout << group[i] << " ";
        }
        cout << endl;
    }
}
