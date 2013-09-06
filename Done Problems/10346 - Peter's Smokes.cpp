
#include <iostream>
using namespace std;
#include <stdio.h>

int main() {
    int x, k;
    cin>>x>>k;
	while(cin) {
        int smoked=0;
        smoked=x;
        while (x>=k) {
            smoked+=x/k;
            x=x/k+x%k;
        }
        
        cin>>x>>k;
        
        
        cout<<smoked<<endl;
	}
    return 0;
}

