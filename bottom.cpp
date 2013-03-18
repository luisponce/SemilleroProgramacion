#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN =5000;
vector <int> g[MAXN];
int p[MAXN];
bool isSink[MAXN];
int d[MAXN];

bool findP(int s, int p, int n){//
//     for (int i=0; i<g[s].size(); i++){
//         
//         if (g[s][i]==p){
//            
//            return true;
//         }
//     }
     for (int i=0; i<n; i++) d[i]=-1;
     queue <int> q;
     q.push(s);
     while (q.size()> 0) {
           int cur = q.front(); q.pop();
           
           if (cur == p) return true;
           for (int i =0; i<g[cur].size(); i++) {
               int next = g[cur][i];
               if (d[next]==-1){
                  d[next]++;
                  q.push(next);
               }
           }
     }
     return false;
}

int main()
{
    int n;
    cin>>n;
    while (n!=0){
          //limpieza
          for(int i =0; i<n; i++){
                  g[i].clear();
                  p[i]=-1;
                  isSink[i]=true;
          }
          //crear lista ad.
          int u;
          cin>>u;
          for (int i=0; i<u; i++){
              int x; int y;
              cin>>x>>y;
              x--; y--;
              g[x].push_back(y);
          }
          // look if is sink
          for (int i=0; i<n; i++) {
              for(int j=0; j<g[i].size() && isSink[i]==true; i++){
                      int next = g[i][j];
                      p[next]=i;
                      //cout<<i<<"-"<<g[i][j]<<endl;
                      
                      isSink[i] = isSink[i] && findP(next, p[next], n);
                      
              }
          }
          for (int i=0; i<n; i++) {
             if(isSink[i]) cout<<(i+1)<<" ";
             //cout<<isSink[i];
              
          }
          cout<<endl;
          cin>>n;
    }
    
    return EXIT_SUCCESS;
}
