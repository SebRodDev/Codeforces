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

bool all_eatable(const vector<int> &packmen, std::deque<int> food, int time) {
    for (int p : packmen) {
        vector<int> have_to_eat;
        while (!food.empty() && food[0] < p) {
            have_to_eat.push_back(food[0]);
            food.pop_front();
        }

        if (have_to_eat.empty()) {
            /*
             * don't have to eat anything to the left,
             * so let's go to the right as much as possible
             */
            while (!food.empty() && food[0] - p <= time) { food.pop_front(); }
        } else {
            if (p - have_to_eat[0] > time) {
                //  we can't eat the leftmost pellet, so we can't eat all of
                //  them
                return false;
            }

            int left_time = p - have_to_eat[0];
            // test for if we went to the left first
            int right_free_time = time - 2 * left_time;
            int left_first = -1;
            while (left_first + 1 < food.size() &&
                   food[left_first + 1] - p <= right_free_time) {
                left_first++;
                   }

            // test for if we went to the right first
            right_free_time = time - left_time;
            int right_first = -1;
            while (right_first + 1 < food.size() &&
                   (food[right_first + 1] - p) * 2 <= right_free_time) {
                right_first++;
                   }

            // take the maximum
            for (int i = 0; i < std::max(left_first, right_first) + 1; i++) {
                food.pop_front();
            }
        }

        if (food.empty()) { return true; }
    }
    return food.empty();
}

int main() {
    int field_len;
    cin >> field_len;
    std::string field;
    cin >> field;
    for (char &c : field) { c = toupper(c); }

    vector<int> packmen;
    std::deque<int> food;
    for (int i = 0; i < field.length(); i++) {
        if (field[i] == 'P') {
            packmen.push_back(i);
        } else if (field[i] == '*') {
            food.push_back(i);
        }
    }

    int lo = 0;
    int hi = field.length() * 2;
    int valid = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (all_eatable(packmen, food, mid)) {
            valid = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << valid << endl;
}
