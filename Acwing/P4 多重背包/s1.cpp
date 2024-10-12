#include<iostream>
using namespace std;

const int N = 1e3 + 10;
int W[N] , V[N] , S[N];
int f[N];

int main()
{
    int n , v; cin >> n >> v;
    for(int i = 1 ; i <= n ; i++)
        cin >> W[i] >> V[i] >> S[i];
    
    for(int i = 1  ; i <= n ; i++)
    {
        for(int j = v ; j >= 0 ; j--)
        {
            for(int k = 0 ; k * W[i] <= j && k <= S[i] ; k++)
            {
                f[j] = max(f[j] , f[j-k*W[i]] + k * V[i]);
            }
        }
    }
    
    cout << f[v];
}