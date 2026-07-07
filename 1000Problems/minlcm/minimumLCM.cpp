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

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;

    return abs(a / gcd(a, b) * b); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // reading in the input
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        // math theory problem

        // we want to find a smallest divisor that is greater as this will tell us what will actually be the greatest divisor
        long long d = n;

        // finding the smallest we only have to iterate sqrt(n) times as this would have exhausted all potential options and we skip
        // over 1 since 1 is always a divisor of every number
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }

        // a will be our largest divisor and then b is simply just the difference this works because lcm(a, b) is simply just a * b divided by gcd(a, b)
        // and for lcm to be minimized then we want to maximize the gcd(a, b) and to do that we have find the smallest divisor to get us the largest then
        // simply take the difference that needs to make b
        long long a = n / d;
        long long b = n - a;

        cout << a << " " << b << "\n";
    }
}
