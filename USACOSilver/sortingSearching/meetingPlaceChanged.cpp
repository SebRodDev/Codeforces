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

bool can(vector<pair<int, int>>& friends, double mid) {
    // just kinda brute force compute but how exactly
    // do you decide whether its best to go one direction vs another
    // obviously furthest left point should go right and furthest right should go left
    // basically i think monotonic property is that if a person is able to reach a point then they can
    // reach all points from where they started to that point

    // could maybe compute furthest left/right for each of the friends and then see if theres overlap?

    // sweep line like it seems cause you can either go left or right


    double goingLeft = friends[0].first - (friends[0].second * mid);
    double goingRight = friends[0].first + (friends[0].second * mid);

    for (int i = 1; i < friends.size(); i++) {
        goingLeft = max(goingLeft, friends[i].first - (friends[i].second * mid));
        goingRight = min(goingRight, friends[i].first + (friends[i].second * mid));
    }

    return goingLeft <= goingRight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<int, int>> friends(n);

    for (int i = 0; i < n; i++) {
        cin >> friends[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> friends[i].second;
    }

    // can either go north or south
    // binary search on minimum time for all n friends to meet

    double l = 0, r = 1e9;

    // optimally speaking its best if given the persons speed they go to the direction that they are closest
    // of reaching the next friend
    // 5 second time limit is telling me that they can kinda just brute force
    for (int i = 0; i < 300; i++) {
        double mid = (r + l) / 2;

        if (can(friends, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << setprecision(12) << r << "\n";
}