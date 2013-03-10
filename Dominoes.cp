/* 
 * File:   main.cpp
 * Author: luismiguel
 *
 * Created on 3 de marzo de 2013, 02:16 PM
 */


using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 100005;
//lista de adyacencia del nodo normal
vector <int> g[MAXN];
//nodos visitados
bool seen[MAXN];
//lista de adyacencia del nodo inverso
vector <int> grev[MAXN];
//lista ordenamiento topologico
vector <int> topo;
//componentes fuertemente conexas
int scc[MAXN];
//numero de aristas que entran a una componente
int in[MAXN];

void dfs1 (int i) {
    seen[i]=true;
    for (int j=0; j<g[i].size(); ++j) {
        int next = g[i][j];
        if (seen[next]==false) dfs1(next);
    }
    topo.push_back(i);
}

//segundo dfs que le asigna la componente dada al nodo i en css (y a sus hijos)
void dfs2 (int i, int comp){
    scc[i]=comp;
    for (int j=0; j<grev[i].size(); ++j){
        int next = grev[i][j];
        if (scc[next]==-1) dfs2(next, comp);
    }
}

int main() {
    int cases; cin>>cases;
    while (cases--) {
        //n=num de nodos, m=num de aristas
        int n; int m;
        cin>>n>>m;
        
        topo.clear();
        for (int i=0; i<=n; i++) {
             g[i].clear();
             seen[i]=false;
             grev[i].clear();
             scc[i] = -1;
             in[i]=0;
        }
        
        //crear los grafos g y grev
        for (int i=0; i<m; ++i) {
            int x, y; cin>>x>>y;
            x--; y--;
            g[x].push_back(y);
            grev[y].push_back(x);
        }
        
        //crear lista topografica
        for (int i=0; i<n; ++i){
            if(!seen[i]) dfs1(i);
        }
        reverse(topo.begin(), topo.end());
        
        //segundo dfs para obtener componentes (css)
        int comp=0;
        for (int i=0; i<n; ++i) {
            int next = topo[i];
            if (scc[next]==-1) dfs2(next, comp++);
        }
        
        //cuantas aristas tiene las componentes (se guarda en in[])
        for (int i=0; i<n; ++i) {
            for (int j=0; j<g[i].size(); ++j) {
                int target = g[i][j];
                if (scc[i]!=scc[target]) in[scc[target]]++;
            }
        }
        
        //cuantas componentes no le llegan aristas
        int sum=0;
        for (int i=0; i<comp; ++i){
            if (in[i]==0) sum++;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}

