#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
double C[N] , A[N] , Fprev[2*N] , Fcurr[2*N];

int main() {
    int n;
    cin >> n;

    for (int i = 1 ; i <= n; i++) {
        cin >> C[i] >> A[i];
    }
    
    int offset = n;
    int size = 2 * n + 1;
    
    // 初始时 差值为零的概率为 1
    Fprev[0 + offset] = 1.0;

    // 进行每个项目
    for (int i = 1 ; i <= n; ++i) {
        // fill(dp_curr.begin(), dp_curr.end(), 0.0);
        fill(Fcurr, Fcurr + size, 0.0);
        // 遍历每一种可能的差值
        for (int d = -i; d <= i; d++) {
            // 定位这个差值
            int idx = d + offset;
            // 如果这种概率存在
            if (Fprev[idx] > 0) {
                // C胜利 多赢一枚
                Fcurr[d + 1 + offset] += Fprev[idx] * C[i];
                // 反之
                Fcurr[d - 1 + offset] += Fprev[idx] * A[i];
                // 无事发生
                Fcurr[d + offset] += Fprev[idx] * (1.0 - C[i] - A[i]);

                // cout << Fcurr[d + 1 + offset] << " " << Fcurr[d - 1 + offset] << " " << Fcurr[d + offset] << endl;
            }
        }
        memcpy(Fprev , Fcurr,  sizeof Fcurr);
    }

    double result = 0.0;
    // 统计差值大于零的所有情况
    for (int d = 1; d <= n; ++d) {
        result += Fprev[d + offset];
    }

    printf("%.3f" , result);
    
    return 0;
}