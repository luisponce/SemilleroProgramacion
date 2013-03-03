//
//  main.cpp
//  c++ Tester
//
//  Created by Luis Ponce De Leon on 2/28/13.
//  Copyright (c) 2013 Luis Ponce De Leon. All rights reserved.
//
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

int getNextTo (int n, int d, int c) { //n=numero, d=decimal, c: pos=1 neg=-1
    int a[4];
    for (int i=3; i>=0; i--) {
        a[i]= (n+10)%10^i;
    }
    
    a[d]+=c;
    
    int result=0;
    for (int i=0; i<4; i++) {
        result+=a[i]*10^i;
    }
    return result;
    
//    int result = n/10^d;
//    int resultOk = result+c;
//    resultOk=resultOk%10;
//    resultOk=resultOk*10^d;
//    return (n-((result%10)*10^d))+resultOk;
}

void crearGrafo() {
    for (int i=0; i<MAXN; i++) d[i] = -1;
    
    for (int i=0; i<10000; i++) {
        for (int d=0; d<4; d++) {
            g[i].push_back(getNextTo(i, d, 1));
            g[i].push_back(getNextTo(i, d, -1));
        }
    }
}

int readCombination() {
    int a[4];
    for (int i=3; i>=0; i--) {
        cin>>a[i];
    }
    int res=0;
    for (int i=0; i<4; i++) {
        res+=a[i]*10^i;
    }
    return res;
}

int main() {
    
    crearGrafo();
    
    int casos;
    cin>>casos;
    for (int i=0; i<casos; i++) {
        int s = readCombination();
        int t = readCombination();
        int n;
        cin>>n;
        for (int j=0; j<n; j++) {
            d[readCombination()]=-2;
        }
        
        bfs(s);
        
        cout<<d[t]<<endl;
        
    }
    
    return 0;
}

