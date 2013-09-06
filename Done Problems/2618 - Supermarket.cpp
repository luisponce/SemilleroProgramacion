
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXM = 101;
const int MAXN = 100001;

const int INF = 1 << 30;

int list[MAXM];
int market[MAXN];
float price[MAXN];

float dp[MAXN][MAXM];

void bestSolution(int n, int m){
    if(market[n]==list[m]){
        dp[n][m]= min(dp[n-1][m-1]+price[n], dp[n-1][m]); //comprar o haber comprado
    }
    else{
        dp[n][m]= dp[n-1][m];
    }
}

int main (){
    int m, n;
    cin>>m>>n;
    while(m!=0 && n!=0){
        //cleaning
        for(int i=0; i <= n; i++){
            for (int j=0; j<=m; j++){
                dp[i][j]=INF;
            }
        }
    
        //read list products
        for (int i=1; i<=m; i++) {
            cin>>list[i];
        }
        for (int i=1; i<=n; i++){
            cin>>market[i]>>price[i];
        }
        
        //base case
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        
        
        
        //recursividad
        for(int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                bestSolution(i, j);
            }
        }
        //debug
        /*
        cout<<m<<" "<<n<<endl;
        for (int i=0; i<=n; i++){
            for (int j=0; j<=m; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        cout<<endl<<endl;
        */
        
        //output
        if(dp[n][m]!=INF){
            cout<<fixed<<setprecision(2)<<dp[n][m]<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
        
         
        //read next case
        cin>>m>>n;
    }
    
    return 0;
}

