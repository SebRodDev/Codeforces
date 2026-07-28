#include <iostream>
#include <vector>
#include <cmath>
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

bool can(int position, int difference, set<int>& spikes) {
    if (spikes.count(position + difference)) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<int> robots(n);
        set<int> spikes;

        cout << "\n";
        for (int i = 0; i < n; i++) cin >> robots[i];
        for (int i = 0; i < m; i++) {
            int location; cin >> location;
            spikes.insert(location);
        } 

        vector<int> difference(k);
        // want to sort because if it doesnt die at this point then we can just keep going
        sort(robots.begin(), robots.end());
        char first; cin >> first;

        if (first == 'R') difference[0] = 1;
        if (first == 'L') difference[0] = -1;

        for (int i = 1; i < k; i++) {
            char instruction; cin >> instruction;

            if (instruction == 'R') {
                difference[i] = difference[i - 1] + 1;
            } else {
                difference[i] = difference[i - 1] - 1;
            }
        }

        int alive = robots.size();
        vector<int> dead(k);

        for (int i = 0; i < k; i++) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int mid = (left + (right - left)) / 2;
                if (can(robots[mid], difference[i], spikes)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            if (left == 0 && can(left, difference[i], spikes)) {
                cout << "making 0\n";
                dead[k] = 0;
            } else {
                cout << "changing0\n";
                dead[k] = alive - (left + 1); 
            }
        }

        // printing
        for (int i = 0; i < k; i++) {
            cout << robots.size() - dead[k] << " ";
        }
        cout << "\n";
        
    }
}
