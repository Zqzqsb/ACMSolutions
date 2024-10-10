#include<iostream>
using namespace std;

const int N = 1e3 + 10;
int weights[N] , values[N] , f[N][N];

int main()
{
    int n , v; cin >> n >> v;
    
    for(int i = 1 ; i <= n ; i++)
        scanf("%d %d", &weights[i] , &values[i]);
        
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= v ; j++)
        {
            f[i][j] = f[i-1][j];
            if(j - weights[i] >= 0)
                f[i][j] = max(f[i][j] , f[i-1][j-weights[i]] + values[i]);
                
        }
    }
    
    cout << f[n][v];
}