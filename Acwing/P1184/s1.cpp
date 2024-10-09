#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10 , M = 4e5+10;

/*
    对于有向图 m 条边 会存储在 0 - m-1 这些 下标位置
    对于无向图 2m 条边 会存储在 0 - 2m-1 这些 下表位置
    
    对向边 存储在 诸如 (0 , 1) : 1 , (2 , 3) : 2  , (4 ,5) : 3 这些位置
*/
int h[N] , e[M] , ne[M] , idx;
int din[N] , dout[N];
int ans[M] , cnt;
int use[M];
int type;

void init()
{
    memset(h , -1 , sizeof h);
}

void add(int a , int b)
{
    e[idx] = b ; ne[idx] = h[a] ; h[a] = idx ++;
}

void dfs(int u)
{
    for(int& i = h[u] ; i != -1 ; )
    {
        if(use[i])
        {
            i = ne[i];
            continue;
        }
        
        use[i] = true;
        if(type == 1) use[i ^ 1] = true;
        
        int t;
        if(type == 1)
        {
            t = i / 2 + 1;
            if(i % 2 == 1) t = -t;
        }
        else t = i + 1;
        
        int j = e[i];
        i = ne[i];
        
        dfs(j);
        
        ans[ ++ cnt ] = t;
    }
}


int main()
{
    init();
    
   cin >> type;
   int n , m; cin >> n >> m;
   
   for(int i = 0 ; i < m ; i++)
   {
       int a , b; scanf("%d %d" , &a , &b);
       add(a , b);
       if(type == 1) add(b , a);
       
       din[b] ++ ; dout[a] ++;
   }
   
   if(type == 1)
   {
       for(int i = 1 ; i <= n ; i ++)
       {
           if( (din[i] + dout[i]) % 2 == 1)
           {
               cout << "NO";
               return 0;
           }
       }
   }
   else
   {
       for(int i = 1 ; i <= n ; i++)
       {
           if(din[i] != dout[i])
           {
               cout << "NO";
               return 0;
           }
       }
   }
   
   
   for(int i = 1 ; i <= n ; i++)
   {
       if(h[i] != -1)
       {
           dfs(i);
           break;
       }
   }
   
   if(cnt != m)
   {
       cout << "NO";
       return 0;
   }
   
   cout << "YES" << endl;
   for(int i = m ; i >= 1 ; i--) cout << ans[i] << " ";
}