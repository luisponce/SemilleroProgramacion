using namespace std;
 
#include <iostream>

long const MAXN = 1000000000;

int digiSum[MAXN];

int DigiSum(int num) {
  if (digiSum[num] >= 0) return digiSum[num];
  else {
    int ans=0;
    while(num >= 10){
      ans = ans + num%10;
      num = num/10;
    }
    ans = ans + num;
    digiSum[num]=ans;
    return ans;
  }
}

int main(){

  for (int i=0; i<MAXN; i++){
    digiSum[i]=-1;
  }

    int n, m;
    cin>>n>>m;
    while(n!=0 && m!=0){
      int sum=0;
      for (int i=n; i<=m; i++){
	sum = sum + DigiSum(i);
      }

      //output
      cout<<sum<<endl;
      cin>>n>>m;
    }

    return 0;
}
