#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <tuple>

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

    // whole idea is that we basically want to remove the minimum from every array and add them to one array which is the one
    // that contributes the least amount to the sum which is the one whose second smallest is the smallest among all of the arrays and then
    // we simply greedily take the second smallest element adding it to our res until we get to a point where we know have a smallest element
    // as well as the smallest element that contributes to our result and thus we subtract and then add the smallest which means we have transferred
    // all of the smallest elements to one

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<vector<long long>> numbers(n, vector<long long>(2, 1e9));
        long long overallSmallest = 1e9;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;

            while (m--) {
                int current; cin >> current;

                if (current < numbers[i][0]) {
                    numbers[i][1] = min(numbers[i][1], numbers[i][0]);
                    numbers[i][0] = current;
                } else if (current < numbers[i][1]) {
                    numbers[i][1] = current;
                }
            }
        }

        long long res = 0;
        long long smallest = 1e9;
        long long smallestSecond = 1e9;
        // now finding the result
        for (int i = 0; i < n; i++) {
            res += numbers[i][1];

            if (numbers[i][0] < smallest) {
                smallest = numbers[i][0];
            }

            if (numbers[i][1] <  smallestSecond) {
                smallestSecond = numbers[i][1];
            }
        }

        res -= smallestSecond;
        res += smallest;
        
        cout << res << "\n";
    }
}
