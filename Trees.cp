/* 
 * File:   main.cpp
 * Author: luismiguel
 *
 * Created on 3 de marzo de 2013, 02:16 PM
 */


using namespace std;
#include <iostream>
#include <map>
#include <stdio.h>
#include <list>
#include <math.h>
#include <sstream>




int main() {
    int cases;
    cin>>cases;
    string useless;
    getline(cin, useless);
    getline(cin, useless);
    float counter;
    int coutLines=0;
    list<string> toPrint;
    for (int i=0; i<cases; i++) {
        map <string, int> m;
        map <string, int>::iterator it;
        
        string key;
        getline(cin,key);
        m[key]=1;
        counter=1.0f;
        while (getline(cin,key) && key!=""){
             counter++;
            // if(m.count[key]==0) m[key]=1;
             m[key]++;
        }
        for (it = m.begin(); it!=m.end(); ++it){
            float x=((it->second)*100.0f)/counter;
            stringstream ss (stringstream::in | stringstream::out);
            ss<<x;
            string valFloat =ss.str();
            float nearest = floorf(x * 10000 + 0.5) / 10000;
            toPrint.push_back(it->first + " " + valFloat + "\n");
            coutLines++;
//            m.erase(it);
        }
        if (i!=cases) toPrint.push_back("\n");
        coutLines++;
    }
    for (int i=0; i<coutLines; i++) {
        cout<<toPrint.front();
        toPrint.pop_front();
    }
    return 0;
}

