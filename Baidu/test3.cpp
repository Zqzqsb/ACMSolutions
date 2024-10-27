#include <iostream>
#include <vector>

using namespace std;

int alternatingSum(vector<int>& arr) {
    bool add = true;

    while (arr.size() > 1) {
        vector<int> newArr;
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            if (add) {
                newArr.push_back(arr[i] + arr[i + 1]);
            } else {
                newArr.push_back(arr[i] - arr[i + 1]);
            }
            add = !add;
        }
        arr = newArr;
        // for(auto i : arr)
        //     cout << i << " ";
        // cout << endl;
    }
    return arr[0];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = alternatingSum(arr);
    cout << result << endl;

    return 0;
}