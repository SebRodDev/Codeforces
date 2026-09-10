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

void solve() {
    string s1, s2; cin >> s1 >> s2;

    int match = 0;

    for (char c : s1) {
        if (c == '+') match++;
        if (c == '-') match--;
    }

    int secondMatch = 0;

    int numQuestion = 0;

    for (char c : s2) {
        if (c == '?') numQuestion++;
        if (c == '+') secondMatch++;
        if (c == '-') secondMatch--;
    }

    // basically have to do counting based cause we dont care how we choose the stuff we just care about
    // the final result

    int answerDistance = match - secondMatch;
    double res = 1;

    if ((answerDistance + numQuestion)%2 != 0 || numQuestion < abs(answerDistance)) {
        res = 0;
    } else {
        int properMoves = (numQuestion + abs(answerDistance)) / 2;

        int c = 1;

        for (int i = 0; i < properMoves; i++) {
            c *= numQuestion-i;
        }

        for (int i = 2; i <= properMoves; ++i) {
            c /= i;
        }

        res = (double)c/(1 << numQuestion);
    }

    cout << fixed << setprecision(9) << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;

    while (tt--) {
        solve();
    }
}
