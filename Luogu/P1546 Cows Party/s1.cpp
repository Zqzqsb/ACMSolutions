#include<bits/stdc++.h>
using namespace std;

const int N=100;
int fa[N];
int n,ans,cnt;

struct E
{
	int a,b,w;
}e[N*N+10];

int find (int x)
{
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int cmp (E& a,E& b)
{
	return a.w<b.w;
}

void kruskal()
{

	for (int i=1;i<=n*n;i++){
		if (cnt==n-1) break;
		int x=find(e[i].a),y=find(e[i].b);
		if (x==y) continue;
		
		fa[y]=x;
		ans+=e[i].w;
		cnt++;
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int index = (i-1)*n + j;
			cin >> e[index].w;
			e[index].a=i;
			e[index].b=j;
		}
	}
	sort(e+1,e+1+n*n,cmp);
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	

	
	kruskal();
	cout<<ans;
	return 0;
}