#include<iostream>
using namespace std;

const int N = 1e3;
int weights[N][N] , values[N][N] , groupNums[N];
int f[N];

using namespace std;

int main()
{
    int n , v; cin >> n >> v;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> groupNums[i];
        
        for(int j = 1 ; j <= groupNums[i] ; j++)
        {
            cin >> weights[i][j] >> values[i][j];
        }
    }
    
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = v ; j >= 1 ; j--)
        {
            for(int k = 1 ; k <= groupNums[i] ; k++)
            {
                if(j - weights[i][k] >= 0)
                    f[j] = max(f[j] , f[j-weights[i][k]] + values[i][k]);
            }
        }
    }
    
    cout << f[v];
}