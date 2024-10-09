#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 3e5+10;
int h[N] , e[N] , ne[N] , idx;
int weight[N] , dp[N][2];
bool st[N] , primes[N];

void init()
{
    memset(h , -1 , sizeof h);
}

void add(int a , int b)
{
    e[idx] = b; ne[idx] = h[a] ; h[a] = idx++;
}

void dfs(int u)
{
    st[u] = true;
    if(primes[u]) dp[u][1] += 1;
    
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        
        if(st[j] == false)
        {
            dfs(j);

            if(primes[u]) dp[u][1] += dp[j][0]; 
            dp[u][0] += max(dp[j][1] , dp[j][0]);
        }
    }
} 

bool is_prime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;  
    if (n % 2 == 0) return false; 

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    init();
    
    int n; cin >> n;
    
    for(int i = 1 ; i <= n ; i++)
        cin >> weight[i];
    
    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin >> a >> b;
        add(a , b);
        add(b , a);
        if(is_prime(weight[a] + weight[b]))
        {
            primes[a] = true;
            primes[b] = true;
        }
    }

    dfs(1);
    cout << max(dp[1][0] , dp[1][1]);
}


