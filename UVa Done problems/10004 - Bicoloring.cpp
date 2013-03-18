using namespace std;
#include <iostream>
#include <vector>
#include <queue>
const int MAXN = 200;
vector<int> g[MAXN];

int color[MAXN];// El arreglo de visitados
enum {WHITE, GRAY, BLACK, RED}; // WHITE = 1, GRAY = 2, BLACK = 3, RED = 4
bool bicolorable = true;

void dfs(int u, int c){
    if (c == 1) {
        color[u] = RED;
        for (int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            if (color[v] == RED) bicolorable = false;
            if (color[v] == WHITE) dfs(v, 0); // Visitar mis vecinos
        }
    } else {
        color[u] = GRAY;
        // Marcar el nodo como semi-visitado
        for (int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            if (color[v] == GRAY) bicolorable = false;
            if (color[v] == WHITE) dfs(v, 1); // Visitar mis vecinos
        }
    }
}

void call_dfs(int n){
    // Marcar los nodos como no visitados
    for (int u = 0; u < n; ++u) color[u] = WHITE;
    // Llamar la funcion DFS con los nodos no visitados
    for (int u = 0; u < n; ++u)
        if (color[u] == WHITE) dfs(u, 0);
}


int main()
{
    int n; int l;
    cin>>n;
    queue<string> q;
    while (n!=0) {
        cin>>l;
        
        for (int i=0; i<=n; i++) {
            g[i].clear();
        }
        
        for (int i=0; i<l; i++) {
            int u; int v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        call_dfs(n);
        
        if (bicolorable) {
            q.push("BICOLORABLE.");
        } else {
            q.push("NOT BICOLORABLE.");
        }
        
        bicolorable = true;
        
        cin>>n;
    }
    
    while (q.size()>0) {
        cout<<q.front()<<endl;
        q.pop();
    }
    
    return 0;
}
