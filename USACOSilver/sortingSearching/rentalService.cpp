#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

#define int long long
#define usaco

#ifdef usaco
std::ifstream cin("rental.in");
std::ofstream cout("rental.out");
#endif

int32_t main() {
    // must decide between deciding if a cow should be milked or rented to a farmer to maximize the amount of money per day

    int n, m, r; cin >> n >> m >> r;

    // looks more like a custom comparators problem
    // there could be cases where its more optimal to rent out all the cows rather than selling milk
    // sort by decreasing cost, increasing cow count to fulfill request
    // since r requests are only 1 cow and the others are as many cows as needed to fulfill request
    // there are edge cases with this idea though
    // since you dont have to produce exactly the amount of milk that is needed then you dont really want to milk cows completely

    std::vector<int> cows(n); for (auto& x : cows) cin >> x;
    std::sort(cows.begin(), cows.end());

    std::vector<std::pair<int, int>> orders(m);

    for (int i = 0; i < m; i++) {
        cin >> orders[i].first >> orders[i].second;
    }

    std::sort(orders.begin(), orders.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    });

    // either milk the most producing cow or rent the least producing price depending on which is greater

    std::vector<int> milk_pre(m + 1);
    std::vector<int> cents_pre(m + 1);

    for (int i = 0; i < m; i++) {
        milk_pre[i + 1] = milk_pre[i] + orders[i].first;
        cents_pre[i + 1] = cents_pre[i] + orders[i].second * orders[i].first;
    }

    std::priority_queue<int> rent_orders;

    for (int i = 0; i < r; i++) { // only the max rent order is consumed so we can use a priority queue
        int order; cin >> order;
        rent_orders.push(order);
    }

    // greedily consume cows
    int rentIndex = 0, sellIndex = n - 1;

    int totalSold = 0, totalSell = 0, profit = 0;

    while (rentIndex <= sellIndex) {
        // can either choose to rent the cow or milk the cow which is selling

        // choose to sell and milk the cows
        // figuring out how many gallons on top of what has been sold to figure out the total amount of gallons sold
        int buyerIndex = std::lower_bound(milk_pre.begin(), milk_pre.end(), totalSold + cows[sellIndex]) - milk_pre.begin() - 1;

        // can fill every order
        int sellProfit = cents_pre.back() - totalSell;

        if (buyerIndex < m) {
            // - totalSell computes the entire profit of what we have sold so far
            sellProfit = (cents_pre[buyerIndex + 1] - (milk_pre[buyerIndex + 1] - (totalSold + cows[sellIndex])) * orders[buyerIndex].second) - totalSell;
        }

        // could either rent
        int rentProfit = rent_orders.empty() ? 0 : rent_orders.top();

        if (sellProfit >= rentProfit) {
            profit += sellProfit;
            totalSold += cows[sellIndex];
            totalSell += sellProfit;
            sellIndex--;
        } else {
            profit += rentProfit;
            rentIndex++;
            rent_orders.pop();
        }
    }

    cout << profit << "\n";

}