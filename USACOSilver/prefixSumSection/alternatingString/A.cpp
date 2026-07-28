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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string s; cin >> s;

        // greedy -> apply one property then apply the other simple enough
        // even characters are same, odd characters are the same, length is even
        
        // dont ask
        vector<vector<int>> prefEven(n + 2, vector<int>(26));
        vector<vector<int>> prefOdd(n + 2, vector<int>(26));
        vector<vector<int>> suffixEven(n + 2, vector<int>(26));
        vector<vector<int>> suffixOdd(n + 2, vector<int>(26));

        // prefixes
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++) {
                prefEven[i][c] += prefEven[i - 1][c];
                prefOdd[i][c] += prefOdd[i - 1][c];
            }

            if (i&1) {
                prefOdd[i][s[i - 1] - 'a']++;
            } else {
                prefEven[i][s[i - 1] - 'a']++;
            }
        }

        // suffixes
        for (int i = n; i > 0; i--) {
            for (int c = 0; c < 26; c++) {
                suffixEven[i][c] += suffixEven[i + 1][c];
                suffixOdd[i][c] += suffixOdd[i + 1][c];
            }

            if (i&1) {
                suffixOdd[i][s[i - 1] - 'a']++;
            } else {
                suffixEven[i][s[i - 1] - 'a']++;
            }
        }

        // now do the checking stuff
        if (n&1) {
            // now try deleting every index
            
            int minCost = 1e9;
            for (int i = 1; i <= n; i++) {
                int maxEven = 0, maxOdd = 0, totalEven = 0, totalOdd = 0;
                for (int c = 0; c < 26; c++) {
                    maxEven = max(maxEven, prefEven[i - 1][c] + suffixOdd[i + 1][c]);
                    totalEven += prefEven[i - 1][c] + suffixOdd[i + 1][c];

                    maxOdd = max(maxOdd, prefOdd[i - 1][c] + suffixEven[i + 1][c]);
                    totalOdd += prefOdd[i - 1][c] + suffixEven[i + 1][c];
                }

                minCost = min(minCost, 1 + totalEven - maxEven + totalOdd - maxOdd);
            }

            cout << minCost << "\n";

        } else {
            int maxEven = 0, maxOdd = 0, totalEven = 0, totalOdd = 0;

            for (int c = 0; c < 26; c++) {
                maxEven = max(maxEven, prefEven[n][c]);
                totalEven += prefEven[n][c];

                maxOdd = max(maxOdd, prefOdd[n][c]);
                totalOdd += prefOdd[n][c];
            }

            cout << totalEven - maxEven + totalOdd - maxOdd << "\n";
        }
    }
}
