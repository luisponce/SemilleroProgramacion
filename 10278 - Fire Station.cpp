
using namespace std;
#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>

typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
const int MAXN = 505;
const int INF = 1<<30;
vector <edge> g[MAXN];
vector <int> fireH;
int d[MAXN];
bool isFireH[MAXN];
int ans;

int dijkstra(int s){
	priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
	q.push(dist_node(0,s));
	for (int i=0; i<MAXN; i++) d[i]=INF;
	d[s]=0;
	while(!q.empty()){
		int dist = q.top().first;
		int cur = q.top().second;
		q.pop();
		if (isFireH[cur]) {
			if (dist<d[cur]) return dist;
			else return d[cur];
		}
		if(dist > d[cur]) continue;
		for (int i=0; i<g[cur].size(); ++i) {
			int next = g[cur][i].first;
			int w_extra = g[cur][i].second;
			if (d[cur] + w_extra < d[next]){
				d[next] = d[cur] + w_extra;
				q.push(dist_node(d[next], next));
			}
		}
	}
}

int main() {
	int cases;
	int maxDistancia;
	cin>>cases;
	while(cases--){		
		//lee datos
		int f; int n;
		cin>>f>>n;
		
		//limpieza
		int ans=-1;
		for (int i=0; i<MAXN; i++){
			g[i].clear();
			
			isFireH[i]=false;
		}
		
		//guarda datos de las estaciones
		for (int i=0; i<f; i++){
			int firePos;
			cin>>firePos; firePos--;
			isFireH[firePos]=true;
		}
		
		string tmp;
		getline(cin, tmp);
		
		//guarda datos de las calles
		string line;
		getline(cin, line);
		while(line.size()!=0 && cin){
			stringstream ss(line);
			int x; int y; int w;
			ss>>x>>y>>w;
			x--; y--;
			g[x].push_back(edge(y,w));
			g[y].push_back(edge(x,w));
			
			getline(cin, line);
		}
		ans = -1;
		int menorDistancia=INF;
		for (int u=0; u<n; u++){
				bool originalVal=isFireH[u];
				isFireH[u]=true;
				maxDistancia=0;
				for (int i=0; i<n; i++){
						int dist = dijkstra(i);
						if (dist > maxDistancia){
							maxDistancia= dist;
						}
				}
				
				if (maxDistancia<menorDistancia) {
					menorDistancia=maxDistancia;
					ans=u;
				}
				
				isFireH[u]=originalVal;
			
			
		}
		
		//print
		cout<<(ans+1);
		if (cases>=0) {
			puts(""); puts("");
		}
	}
	
    return 0;
}

