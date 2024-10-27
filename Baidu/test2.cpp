#include <iostream>
#include <list>

using namespace std;

int main() {
    // 输入字符串
    string S;
    cin >> S;
    int n = S.size();

    // 将字符串转换成链表
    list<char> ll(S.begin(), S.end());

    // 初始化迭代器指向链表头部
    auto it = ll.begin();

    for (int i = 1; i <= n; ++i) {
        // 将当前元素移动到链表末尾
        auto current = it;
        it ++; it ++;

        // 将当前元素移动到末尾
        ll.splice(ll.end(), ll, current);
    }

    for (char c : ll) {
        cout << c;
    }
    cout << endl;

    return 0;
}