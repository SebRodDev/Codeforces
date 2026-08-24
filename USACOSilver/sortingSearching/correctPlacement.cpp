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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<tuple<int, int, int>> nums(n); // {height, width, original_id}
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            nums[i] = {h, w, i};
        }
        sort(nums.begin(), nums.end(), greater<tuple<int, int, int>>());

        // smallestWidth[i] = {min width, original_id} over suffix [i, n)
        vector<pair<int, int>> smallestWidth(n + 1, {INT_MAX, -1});
        vector<int> res(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            smallestWidth[i] = smallestWidth[i + 1];
            if (get<1>(nums[i]) < smallestWidth[i + 1].first) {
                smallestWidth[i] = {get<1>(nums[i]), get<2>(nums[i]) + 1}; // store original id
            }
        }

        for (int i = 0; i < n; i++) {
            int myH = get<0>(nums[i]), myW = get<1>(nums[i]), myId = get<2>(nums[i]);
            int idx = upper_bound(nums.begin(), nums.end(), make_tuple(myH, INT_MIN, INT_MIN),
                       greater<tuple<int,int,int>>()) - nums.begin();
            auto [w, id] = smallestWidth[idx];
            if (id != -1 && w < myW) {
                res[myId] = id; // write into original id's slot
            }
        }

        // now handle the "lying down" case: swap height/width, id stays attached
        for (int i = 0; i < n; i++) {
            swap(get<0>(nums[i]), get<1>(nums[i]));
        }
        sort(nums.begin(), nums.end(), greater<tuple<int, int, int>>());

        vector<pair<int, int>> smallestHeight(n + 1, {INT_MAX, -1});
        for (int i = n - 1; i >= 0; i--) {
            smallestHeight[i] = smallestHeight[i + 1];
            if (get<1>(nums[i]) < smallestHeight[i + 1].first) {
                smallestHeight[i] = {get<1>(nums[i]), get<2>(nums[i]) + 1};
            }
        }

        for (int i = 0; i < n; i++) {
            int myH = get<0>(nums[i]), myW = get<1>(nums[i]), myId = get<2>(nums[i]);
            int idx = upper_bound(nums.begin(), nums.end(), make_tuple(myH, INT_MIN, INT_MIN),
                       greater<tuple<int,int,int>>()) - nums.begin();
            auto [w, id] = smallestHeight[idx];
            if (id != -1 && w < myW && res[myId] == -1) {
                res[myId] = id;
            }
        }

        for (int r : res) cout << r << " ";
        cout << "\n";
    }
}