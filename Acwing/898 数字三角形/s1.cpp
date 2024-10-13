#include<iostream>
#include<cstring>
using namespace std;

const int N = 510 , INF = 1e9;
int f[N][N];

int main()
{
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            f[i][j] = -INF;
    
    f[0][0] = 0;
    
    int n; cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            cin >> f[i][j]; 
            f[i][j] += max(f[i-1][j-1] , f[i-1][j]);
        }
    }
    
    int res = -INF;
    for(int i = 1 ; i <= n ; i++) res = max(res , f[n][i]);
    
    cout << res;
}