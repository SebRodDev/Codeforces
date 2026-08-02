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

    int n, k; cin >> n >> k;

    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // goal is to calculate the min possible distance between the maximum and minimum element
    // you can binary search on this difference and see if you can make it which means that all
    // nums must be and i think you can just compute how much you would need such that the difference between
    // the largest and smallest is that

    // can either increase or decrease the number by 1 and that counts as 1 operation

    // maybe can try both decreasing then increasing numbers somehow

    int left = 0, right = n - 1;

    int amtLeft = 1, amtRight = 1;
    while (left < right && k > 0) {
        while (left + 1 < right && a[left]==a[left + 1]) {
            amtLeft++;
            left++;
        }

        while (right - 1 > left && a[right]==a[right - 1]) {
            right--;
            amtRight++;
        }

        // computing the gap to the next unique number in the array
        int minGap = a[left + 1] - a[left];
        int maxGap  = a[right] - a[right - 1];

        if (amtLeft <= amtRight) {
            // can either jump to the gap or just increase all by 1
            int possibleSteps = min(minGap, k / amtLeft);

            if (possibleSteps == 0) break;

            a[left] += possibleSteps;
            k -= possibleSteps * amtLeft;

            if (possibleSteps == minGap) {
                amtLeft++;
                left++;
            }
        } else {
            int possibleSteps = min(maxGap, k / amtRight);

            if (possibleSteps == 0) break;

            a[right] -= possibleSteps;
            k -= possibleSteps * amtRight;
            if (possibleSteps == maxGap) {
                right--;
                amtRight++;
            }
        }
    }

    cout << a[right] - a[left] << "\n";
}