
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

char toChar(int n){
    if(n<=25) return n + 'a';
    else return n -26 + 'A';
}

const int MAXN = 51;

char building[2][MAXN][MAXN];

int main (){
    int n;
    while(cin>>n){
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                building[1][j][i]=toChar(i);
                building[0][i][j]=toChar(i);
            }
        }
        
        //print
        cout<<n<<" "<<n<<" "<<2<<endl;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<n; k++) {
                    cout<<building[j][i][k];
                }
                
                cout<<endl;
            }
            
            cout<<endl;
        }
    }
    
    return 0;
}

