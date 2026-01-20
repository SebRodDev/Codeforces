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

int main() {
    // basically the whole goal of this problem is that we are trying to find the minimum amount that is needed in order to get the number to be divisible 
    // by k for case where k=2,3,5, but when we have a case of k=4 we could either make two factors of 2 because 4 = 2^2 or we could simply just have to increment one number
    // by a smaller amount to get it to get a factor of 4 that is why we have it as such and why only for k=4 there are 2 cases
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> numbers(n);

        int evenCount = 0;
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        if (k==2 || k==3 || k==5) {
            int minAmount = 1e9;
            for (auto el : numbers) {
                minAmount = min(minAmount, (int) ((k - el % k) % k));
            }

            cout << minAmount << "\n";
        } else {
            int minAmount = 1e9;
            for (auto el: numbers) {
                minAmount = min(minAmount, (int) ((k - el % k) % k));
            }

            // second case that its better to get 2
            int evenAmount = 0;
            for (int i = 0; i < n; i++) {
                if (numbers[i] % 2 == 0) evenAmount++;
            }


            if (evenAmount >= 2) {
                cout << 0 << "\n";
            } else if (evenAmount == 1) {
                cout << min(minAmount, 1) << "\n";
            } else {
                cout << min(minAmount, 2) << "\n";
            }
        }
    }
}
