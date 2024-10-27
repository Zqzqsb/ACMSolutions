#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_AI = 1e5 + 5;

struct Child {
    int candies;
    int price;
};

int main() {
    int n;
    cin >> n;

    vector<Child> children(n);
    int max_ai = 0;
    for (int i = 0; i < n; ++i) {
        cin >> children[i].candies;
        if (children[i].candies > max_ai) {
            max_ai = children[i].candies;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> children[i].price;
    }

    // 按照价格排序
    sort(children.begin(), children.end(), [](const Child& a, const Child& b) {
        return a.price < b.price;
    });

    long long total_candies = 0;
    long long total_cost = 0;
    int M = max_ai;
    long long min_total_cost = LLONG_MAX;

    // 前缀和数组
    vector<long long> delta_cost(MAX_AI, 0);
    vector<int> delta_candies(MAX_AI, 0);

    // 预处理 delta_cost 和 delta_candies
    for (const auto& child : children) {
        delta_cost[child.candies] += (long long)child.price * child.candies;
        delta_candies[child.candies] += child.candies;
    }

    // 从最大 ai 开始枚举可能的 M_candidate
    for (int M_candidate = max_ai; M_candidate >= 0; --M_candidate) {
        total_candies = 0;
        total_cost = 0;

        // 计算需要购买的糖果数和总花费
        for (const auto& child : children) {
            if (child.candies > M_candidate) {
                int buy = child.candies - M_candidate;
                total_candies += buy;
                total_cost += (long long)buy * child.price;
            }
        }

        // 多多需要的糖果数
        int S_needed = M_candidate + 1;

        // 从价格最低的小朋友开始购买糖果
        long long candies_needed = S_needed - total_candies;
        long long extra_cost = 0;
        if (candies_needed > 0) {
            for (const auto& child : children) {
                int can_buy = min(child.candies, (int)candies_needed);
                extra_cost += (long long)can_buy * child.price;
                candies_needed -= can_buy;
                if (candies_needed == 0) {
                    break;
                }
            }
            if (candies_needed > 0) {
                // 无法购买足够的糖果
                continue;
            }
        }

        long long current_total_cost = total_cost + extra_cost;
        if (current_total_cost < min_total_cost) {
            min_total_cost = current_total_cost;
        }
    }

    cout << min_total_cost << endl;

    return 0;
}