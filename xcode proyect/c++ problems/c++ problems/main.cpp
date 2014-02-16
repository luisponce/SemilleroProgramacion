//
//  main.cpp
//  c++ problems
//
//  Created by Luis Ponce De Leon on 9/27/13.
//  Copyright (c) 2013 Luis Ponce De Leon. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, p;
    cin>>n>>p;
    
    string junk;
    
    for (int i=n; i>0; i--) {
        getline(cin, junk);
    }
    
    string best;
    int bestPrice, bestCompilance;
    
    getline(cin, best);
    cin>>bestPrice>>bestCompilance;

    
    
    bestCompilance=bestCompilance/n;
    p--;
    
    
    return 0;
}

