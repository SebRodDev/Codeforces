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

int calc(vector<int>& nums) {
    int mx = 1;
    int sum = 0;
    //cout << nums << "\n";
    for (int num : nums) {
        if (num > mx) mx = num;
        //cout << "adding max: " << mx << "\n";
        sum += mx;
    }

    //cout << "returning: " << sum << "\n";
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        vector<int> numbers(num);

        // reading input
        for (int j = 0; j < num; j++) {
            cin >> numbers[j];
        }

        // actual math
        int res = calc(numbers);
        //cout << num << " ";
        //cout << arr << "\n";
        for (int h = 0; h < num; h++) {
            for (int k = h + 1; k < num; k++) {
                // performing our one swap
                swap(numbers[h], numbers[k]);
                int curSum = calc(numbers);
                if (curSum > res) res = curSum;
                
                // swapping back
                swap(numbers[h], numbers[k]);
            }
        }

        cout << res << "\n";
    }
}
