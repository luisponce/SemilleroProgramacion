//
//  main.cpp
//  c++ Tester
//
//  Created by Luis Ponce De Leon on 2/28/13.
//  Copyright (c) 2013 Luis Ponce De Leon. All rights reserved.
//


#include <iostream>
using namespace std;
#include <stdio.h>


int main() {
    while(EOF) {
        int count=0;
        int cigs, k;
        cin>>cigs>>k;
        while (cigs--) {
            count++;
            if (count%k==0) count++;
        }
        
        cout<<count<<endl;
    }
    
    return 0;
}



