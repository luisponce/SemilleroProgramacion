
#include <iostream>
using namespace std;
#include<queue>
#include<vector>
#include <algorithm>

typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
const int MAXN = 1001;
const int INF = 1<<30;
vector <edge> g[MAXN];
vector <int> path;
int d[MAXN];
int p[MAXN];

void dijkstra(int s, int n){
	for (int i=0; i<=n; i++){
		d[i]=INF;
		p[i]=-1;
	}
	priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
	d[s]=0;
	q.push(dist_node(0,s));
	while(!q.empty()){
		int dist = q.top().first;
		int cur = q.top().second;
		q.pop();
		
		if(dist > d[cur]) continue;
		for (int i=0; i<g[cur].size(); ++i) {
			int next = g[cur][i].first;
			int w_extra = g[cur][i].second;
			if (d[cur] + w_extra < d[next]){
				d[next] = d[cur] + w_extra;
				p[next] = cur;
				q.push(dist_node(d[next], next));
			}
		}
	}
	
}

void findPath (int t) {
	int cur = t;
	while (cur!= -1){
		path.push_back(cur);
		cur=p[cur];
	}
	
	reverse(path.begin(), path.end());
}

int main() {
	int n;
    cin>>n;
    int caseNumber=0;
    while(n!=0) {
    	caseNumber++;
    	path.clear();
    	for (int i=0; i<=n;i++){
    		g[i].clear();
    	}
		for (int u=0; u<n; u++){
			int to;
			cin>>to;
			while(to--){
				int v; int w;
				cin>>v >>w;
				v--; w;
				g[u].push_back(edge(v,w));
			}
		}
				
		int s; int t;
		cin>>s>>t;
		s--; t--;
		
		dijkstra(s, n);
		findPath(t);
		
		cout<<"Case "<<caseNumber<<": Path =";
		for (int i=0; i<path.size(); i++) cout<<" "<<(path[i]+1); 
		cout<<"; "<<d[t]<<" second delay"<<endl;
		
		cin>>n;
	}
	
    
    return 0;
}

