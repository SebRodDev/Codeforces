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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> c(n); for (auto& x : c) cin >> x;

    map<int, vector<int>> colorWithElements;
    map<int, int> colorDifferenceAmt;

    for (int i = 0; i < a.size(); i++) {
        colorWithElements[c[i]].push_back(a[i]);
        colorDifferenceAmt[c[i]] = 0;
    }

    // construct prefix sum array
    for (auto& elements : colorWithElements) {
        for (int i = 1; i < elements.second.size(); i++) {
            elements.second[i] += elements.second[i - 1];
        }
    }

    int q; cin >> q;

    int globalAdd = 0;

    while (q--) {
        int instruction, color, amt; cin >> instruction >> color >> amt;

        if (instruction == 1) {
            globalAdd += amt;
            colorDifferenceAmt[color] -= amt;
        } else {
            // instruction 2 is legit just binary search for the prefix
            int l = 0, r = colorWithElements[color].size() - 1;

            int res = 0;
            while (l <= r) {
                int mid = (r + l) / 2;

                int value = colorWithElements[color][mid] + (mid + 1) * (globalAdd + colorDifferenceAmt[color]);
                if (value <= amt) {
                    res = max(res, mid + 1);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            cout << res << "\n";
        }


    }
}
