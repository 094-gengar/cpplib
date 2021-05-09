#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long
#define P pair<int,int>
template<class T>int chmin(T&a,const T&b){if(b<a){a=b;return 1;}return 0;}

void dijkstra()
{
	int n,m,s,t;cin>>n>>m>>s>>t;
	vector<vector<P>>g(n);
	for(int i=0;i<m;i++)
	{
		int a,b,cst;cin>>a>>b>>cst;
		g[a].push_back(make_pair(b,cst));
	}
	vector<int>dist(n,(1LL<<60));dist[s]=0;
	vector<int>prev(n,-1);
	priority_queue<P,vector<P>,greater<P>>pq;
	pq.push(make_pair(dist[s],s));
	while(!pq.empty())
	{
		auto[d,v]=pq.top();
		pq.pop();
		if(d>dist[v])continue;
		for(auto e:g[v])if(chmin(dist[e.first],dist[v]+e.second))
		{
			prev[e.first]=v;
			pq.push(make_pair(dist[e.first],e.first));
		}
	}
	vector<int>keiro;
	for(int cur=t;cur!=-1;cur=prev[cur])keiro.push_back(cur);
	reverse(keiro.begin(),keiro.end());
	if(dist[t]==1LL<<60)cout<<-1<<' ';
	else
	{
		cout<<dist[t]<<' ';
		int size_of_keiro=keiro.size()-1;
		cout<<size_of_keiro<<endl;
		for(int i=0;i<size_of_keiro;i++)cout<<keiro[i]<<' '<<keiro[i+1]<<endl;
	}
}

main(){dijkstra();}