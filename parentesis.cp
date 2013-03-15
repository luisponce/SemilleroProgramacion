//
//  main.cpp
//  c++ Tester
//
//  Created by Luis Ponce De Leon on 2/28/13.
//  Copyright (c) 2013 Luis Ponce De Leon. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;


int main() {
    char parentesis1 = '(';
    char parentesis2 = ')';
    char corchetes1='[';
    char corchetes2=']';
    
    stack <char> s;
    
    int cases;
    cin>>cases;
    string useles;
    getline(cin, useles);
    bool ans[cases];
    for (int i=0; i<cases; i++){
        while (s.size()) {s.pop();}
        ans[i]=true;
        string line;
        getline(cin, line);
        if (line=="") ans[i]=true;
        else {
            for (int j=0; j<line.length() && ans[i]==true; j++){
                char curChar = line[j];
                if (s.size()==0){
                    if (curChar==parentesis1 || curChar==corchetes1)
                        s.push(curChar);
                    else ans[i]=false;
                } else {
                    if (curChar==parentesis1 || curChar==corchetes1) {
                        s.push(curChar);
                    }else if (curChar==parentesis2){
                        if (s.top()==parentesis1) s.pop();
                        else ans[i]=false;
                    }else if (curChar==corchetes2) {
                        if (s.top()==corchetes1) s.pop();
                        else ans[i]=false;
                    }
                }
                
            }
            if (s.size()!=0) ans[i]=false;
        }
        printf("%s\n",ans[i]?"Yes":"No");
    }
    //for (int i=0; i<cases;i++){
    //    if (ans[i]==true) cout<<"Yes"<<endl;
    //    else cout<<"No"<<endl;
    //}
    return 0;
}

