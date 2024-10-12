#include<iostream>
using namespace std;

const int N = 1e3 + 10;
int weight[N] , value[N] , f[N];

int main()
{
    int n , v; cin >> n >> v;
    for(int i = 1 ; i <= n ; i++)
        scanf("%d %d" , &weight[i] , &value[i]);
        
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = weight[i] ; j <= v ; j++)
        {
            f[j] = max(f[j] , f[j-weight[i]] + value[i]);
        }
    }
    cout << f[v];
}