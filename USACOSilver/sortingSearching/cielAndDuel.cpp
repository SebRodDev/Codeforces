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

struct Card {
    int type;
    int strength;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<Card> jiro;
    vector<Card> ciel;

    for (int i = 0; i < n; i++) {
        string type; int strength; cin >> type >> strength;

        jiro.push_back({type == "ATK", strength});
    }

    for (int i = 0; i < m; i++) {
        int strength; cin >> strength;

        ciel.push_back({1, strength});
    }

    sort(jiro.begin(), jiro.end(), [](const Card &a, const Card &b) {
        if (a.type == b.type) return a.strength < b.strength;

        return a.type > b.type;
    });

    sort(ciel.begin(), ciel.end(), [](const Card &a, const Card &b) {
        return a.strength > b.strength;
    });

    int firstPossible = 0;


    for (int i = 0; i < min(n, m); i++) {
        if (!jiro[i].type || ciel[i].strength <= jiro[i].strength) { break; }

        firstPossible += ciel[i].strength - jiro[i].strength;
    }

    reverse(ciel.begin(), ciel.end());
    reverse(jiro.begin(), jiro.end());

    vector<bool> done(m);
    int secondPossible = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < m; j++) {
            if (!done[j] && ((jiro[i].type && ciel[j].strength >= jiro[i].strength) ||
                             (!jiro[i].type && ciel[j].strength > jiro[i].strength))) {
                done[j] = true;

                if (jiro[i].type) { secondPossible += ciel[j].strength - jiro[i].strength; }

                found = true;
                break;
            }
        }

        // if stuck at this index
        if (!found) {
            cout << firstPossible << "\n";
            return 0;
        }
    }

    // direct damage when done playing
    for (int i = 0; i < m; i++) {
        if (!done[i]) secondPossible += ciel[i].strength;
    }

    cout << max(secondPossible, firstPossible) << "\n";
}
