
using namespace std;
#include <iostream>
#include <map>
#include <stdio.h>
#include <list>
#include <math.h>
#include <sstream>

map <string, int> m;

int main() {
    int cases;
    cin>>cases;
    string useless;
    getline(cin, useless);
    getline(cin, useless);
    while (cases--) {
    	m.clear();
        
        string key;
        int counter = 0;
        while (getline(cin, 		key)){
        	if (key == "") break;
            // if(m.count[key]==0) m[key]=1;
             m[key]++;
             counter++;
        }
        
        map <string, int>::iterator it;
        for (it = m.begin(); it!=m.end(); ++it){
			double x= 100.0 * it->second /counter;
            printf("%s %.4lf\n",(it->first.c_str()), x);
//            m.erase(it);
        }
        if (cases != 0) cout<<endl;
    }
    return 0;
}

