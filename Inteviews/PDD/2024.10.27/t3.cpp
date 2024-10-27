#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;

const int N = 1e5;
int H[N];
unordered_set<int> keys;

void add(int x , int m)
{
       
    if ( keys.count(x) > 0 ||  keys.size() == m) return;
    keys.insert(x);
    
    
    int tar = x % m;
    // cout << keys.size() << " insert " << x << " " << tar <<  endl;
    while(H[tar] != -1)
    {
        if(tar == m - 1) {tar = 0 ; continue;}
        tar ++;
    }
    H[tar] = x;
}

int main()
{
    memset(H , -1 , sizeof H);
    
    int n , m; cin >> n >> m;

    int x ; 
    for (int i = 1; i <= n ; i++)
    {
        cin >> x;
        add(x , m);   
    }

    for(int i = 0 ; i < m ; i++)
        cout << H[i] << " ";

    return 0;
}