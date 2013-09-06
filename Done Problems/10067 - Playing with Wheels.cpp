using namespace std;
#include <iostream>
#include <vector>
#include <queue>
const int MAXN = 10005;
vector<int> g[MAXN];
int d[MAXN];

void bfs (int s) { 
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (q.size()>0) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i<g[cur].size(); i++) {
            int next = g[cur][i];
            if (d[next]==-1) {
                q.push(next);
                d[next]=d[cur]+1;
            }
        }
    }
}

int find_neighbour(int u, int d, int dir){
	vector <int> a(4);
	for (int i = 0; i < 4; ++i){
		a[i] = u % 10;
		u /= 10;
	}
	a[d] = (a[d] + 10 + dir) % 10;
	
	int ans = 0;
	for (int i = 3; i >= 0; --i){
		ans *= 10; ans += a[i];
	}
	return ans;

}

void crearGrafo() {
    for (int i=0; i<MAXN; i++) d[i] = -1;
    
    for (int i=0; i<10000; i++) {
        for (int d=0; d<4; d++) {
            g[i].push_back(find_neighbour(i, d, 1));
            g[i].push_back(find_neighbour(i, d, -1));
        }
    }
}

int get_num(){ // Read nodes and convert them to an integer
	int ans = 0;
	for (int i = 0; i < 4; ++i){
		int d; cin >> d;
		ans = ans * 10 + d;
	}
	return ans;
}

int main() {
    
    crearGrafo();
    
    int casos;
    cin>>casos;
    for (int i=0; i<casos; i++) {
        int s = get_num();
        int t = get_num();
        int n;
        cin>>n;
        for (int i = 0; i < MAXN; ++i) d[i] = -1;
        for (int j=0; j<n; j++) {
            d[get_num()]=-2;
        }
        
        bfs(s);
        
        cout<<d[t]<<endl;
        
    }
    
    return 0;
}

