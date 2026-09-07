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

    // each operation must decrement the entire array by 2 not just 1 element
    // prefix sum over something

    // at some point you can bring all even numbers to 1 and all odd to 2
    // bring all odd to 1 thats trivial but then the issue with the evens is that they alternate from 0 and 2 so MUST
    // know how they alternate

    int t; cin >> t;

    for (int k = 0; k < t; k++) {
        int n; cin >> n;

        vector<int> v;

        int res = 0;
        for (int i = 0; i < n; i++) {
            int cur; cin >> cur;

            // if odd
            if (cur & 1) {
                res++;
            } else {
                v.push_back(cur);
            }
        }


        // min answer will just be the odd numbers only or it will be the even numbers
        int oddZero = 0, evenZero = 0;

        for (int num : v) {
            if ((num / 2) % 2 == 0) {
                evenZero++;
            } else {
                oddZero++;
            }
        }

        cout << max(res, max(evenZero, oddZero)) << endl;
    }
}
