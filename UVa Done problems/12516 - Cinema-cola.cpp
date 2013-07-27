
using namespace std;
#include <iostream>

const int MAXR = 27;
const int MAXC = 100;

int people[MAXR][MAXC]; //0: empty, 1: Friend, 2: stranger
bool drinks[MAXR+1][MAXC]; //T: taken, F: empty

bool ans = true;

int main() {
    int columns; int rows;
    cin>>rows>>columns;
    
    while (columns!=0 && rows!=0) {
        //cleaning
        ans=true;
        
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns+1; j++) {
                people[i][j]=0;
                drinks[i][j]=false;
            }
        }
        
        //read strangers and update matrix
        int p; cin>>p;
        for (int i=0; i<p; i++) {
            int r, c, dir;
            string inPos, inDir;
            
            cin>>inPos>>inDir;
            
            r = (int) inPos.at(0) - 'A';
            
            if (inPos.length()>2) {
                c = (int) (10*(inPos.at(1) - '0') + inPos.at(2) - '0') - 1;
            } else {
                c = (int) inPos.at(1) - '0' - 1;
            }
            
            if (inDir == "-") {
                dir=0;
            } else {
                dir=1;
            }
            
            people[r][c]=2;
            drinks[r][c+dir]=true;
        }
        
        //read friends and update people matrix only
        int f; cin>>f;
        for (int i=0; i<f; i++) {
            int r; int c;
            string in;
            
            cin>>in;
            
            r = (int) in.at(0) - 'A';
            
            if (in.length()>2) {
                c = (int) (10*(in.at(1) - '0') + in.at(2) - '0') - 1;
            } else {
                c = (int) in.at(1) - '0' - 1;
            }
            
            people[r][c]=1;
        }
        
        //assign drinks position to friends (left to rigth)
        for (int i=0; i<rows && ans; i++) {
            for (int j=0; j<columns && ans; j++) {
                if (people[i][j]==1) {
                    if (!drinks[i][j]) {
                        drinks[i][j]=true;
                    } else {
                        if (!drinks[i][j+1]) {
                            drinks[i][j+1]=true;
                        } else {
                            ans=false;
                            break;
                        }
                    }
                }
            }
        }
        
        //print
        cin>>rows>>columns;
        
        if (ans) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        
        
        //if (rows!=0 && columns!=0) {
            cout<<endl;
        //}
    }
	
    return 0;
}

