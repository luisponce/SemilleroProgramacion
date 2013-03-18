
#include <iostream>
using namespace std;
#include<queue>
#include<vector>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
const int MAXN = 501;
const int INF = 1<<30;
vector <edge> g[MAXN];
vector <int> fireH;
vector <int> posible;
int d[MAXN];
int dFinal[MAXN];
bool isFireH[MAXN];
int ans;

void dijkstra(int s, int n){
	priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
	q.push(dist_node(0,s));
	for (int i=0; i<n; i++) d[i]=INF;
	d[s]=0;
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
				q.push(dist_node(d[next], next));
			}
		}
	}
	
//	for(int i=0; i<n; i++){
//		dFinal[i]+=d[i];
//	}
}

int main() {
	int cases;
	cin>>cases;
	while(cases--){		
		//lee datos
		int f; int n;
		cin>>f>>n;
		
		//limpieza
		int ans=-1;
		fireH.clear();
		posible.clear();
		for (int i=0; i<n; i++){
			g[i].clear();
			dFinal[i]=0;
			d[i]=INF;
			
			isFireH[i]=false;
		}
		
		//guarda datos de las estaciones
		for (int i=0; i<f; i++){
			int firePos;
			cin>>firePos; firePos--;
			isFireH[firePos]=true;
			fireH.push_back(firePos);
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
		
		ans=-1;
		int menorDistancia=INF;
		for (int u=0; u<n; u++){
			if (!isFireH[u]) {
				isFireH[u]=true;
				fireH.push_back(u);
				
				int maxDistancia=0;;
				for (int i=0; i<n; i++){
					if (!isFireH[i]){
						dijkstra(i, n);
						int distMejorEstacion=INF;
						for (int j=0; j<fireH.size(); j++){
							if (d[fireH[j]]<distMejorEstacion)
								distMejorEstacion = d[fireH[j]];
						}
						
						if (distMejorEstacion>maxDistancia) 
							maxDistancia=distMejorEstacion;
					}
				}
				
				if (maxDistancia<menorDistancia) {
					menorDistancia=maxDistancia;
					ans=fireH[u];
				}
				
				isFireH[u]=false;
				fireH.pop_back();
			}
			
			
		}
		
		
//		if (f==0){
//			for (int i=0; i<n; i++) dFinal[i]=0;
//			for (int i=0; i<n; i++){
//				dijkstra(i, n);
//			}
//			
//			int curBest=0;
//			for (int i=0; i<n; i++){
//				if (dFinal[i]<dFinal[curBest]) curBest=i;
//			}
//			ans=curBest;
//		} else {
//			
//			//guarda en dFinal las sumas de distancias entre las f estaciones
//			dFinal[fireH[0]]=0;
//			for(int i=0; i<f; i++) dijkstra(fireH[i], n);
//			
//			
//			//obtiene cual es el valor de distacia maximo
//			int max=0;
//			for(int i=0; i<n; i++) {
//				if(dFinal[i]>=max) max=dFinal[i];
//			}
//			
//			//obtiene los posibles lugares para la estacion
//			//y revisa que no exista ya una estacion en el posible nodo
//			for (int i=0; i<n; i++) {
//				if(dFinal[i]==max){
//					bool notPosible = false;
//					for (int j=0; j<f && !notPosible; j++) {
//						if (i==fireH[j]) notPosible=true;
//					}
//					if (!notPosible) posible.push_back(i);
//				} 
//			}
//			
//			//de los posibles obtiene el mejor candidato para la estacion
//			int bestDif=INF;
//			int curDif=0;
//			for (int i=0; i<posible.size(); i++){
//				dijkstra(posible[i], n);
//				curDif = d[fireH[0]];
//				for (int j=1; j<f; j++){
//					curDif-=d[fireH[j]];
//				}
//				curDif=abs(curDif);
//				if (curDif<bestDif){
//					ans=posible[i];
//					bestDif=curDif;
//				}
//			}
//			
//		}
		
		//print
		if (cases!=0) cout<<(ans+1)<<endl<<endl;
		else cout<<(ans+1);
	}
	
    
    return 0;
}

