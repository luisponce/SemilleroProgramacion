#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string ans;
string str;

int main() {
  while (getline(cin, str)){
    //cleaning
    ans="";
    
    stringstream ss(str);
    string word;
    while(ss>>word){
      reverse(word.begin(), word.end());
      ans += word;
    }
    cout<<ans<<endl;
  }

  return 0;
}
