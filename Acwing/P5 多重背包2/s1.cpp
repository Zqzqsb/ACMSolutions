#include<iostream>
using namespace std;

const int N = 1e4 + 10;
int W[N] , V[N] , gidx;
int f[N];

int main()
{
    int n , v; cin >> n >> v;
    
    for(int i = 1 ; i <= n ; i++)
    {
        int wi , vi , si; cin >> wi >> vi >> si;
        
        int split = 1;
        while(si >= 2 * split)
        {
            W[gidx] = wi * split;
            V[gidx] = vi * split;
            
            gidx ++;
            si -= split;
            split *= 2;
        }
        
        if(si) 
        {
            W[gidx] = wi * si;
            V[gidx] = vi * si;
            
            gidx ++;
        }
    }
    
    for(int i = 0 ; i < gidx ; i++)
    {
        for(int j = v ; j >= W[i] ; j--)
        {
            f[j] = max(f[j] , f[j-W[i]] + V[i]);        
        }
    }

    cout << f[v];
}