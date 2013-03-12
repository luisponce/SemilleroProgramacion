/* 
 * File:   main.cpp
 * Author: luismiguel
 *
 * Created on 3 de marzo de 2013, 02:16 PM
 */


using namespace std;
#include <iostream>
#include <stack>

int main() {
    char parentesis1 = 40;
    char parentesis2 =41;
    char corchetes1=91;
    char corchetes2=93;
    
    stack <char> s;
    
    int cases;
    cin>>cases;
    bool ans[cases];
    for (int i=0; i<cases; i++){
        
        
        char curChar;
        cin>>curChar;
        ans[i]=true;
        if (curChar==32) ans[i]==true;
        else {
            
            
            if (s.size()>0){
                if (s.top()==parentesis1){
                    if (curChar==parentesis2) s.pop();
                    else ans[i]==false;
                }
                else {
                    if (s.top()==corchetes1){
                        if (curChar==corchetes2) s.pop();
                        else ans[i]==false;
                    }
                }
            } else {
                s.push(curChar);
            }
        }
    }
    for (int i=0; i<cases;i++){
        if (ans[i]) cout<<"yes";
        else cout<<"no";
    }
    return 0;
}
