#include <iostream>
#include <String>

using namespace std;

int main() {

	string str;
	cin>>str;

	int count = 1;
	int ans = 0;
	char cur = str[0];

	for (int i = 1; i < str.length(); ++i)
	{
		if(str[i] == cur) {
			count++;
		} else {
			if(count%2 == 0) ans++;
			
			cur = str[i];
			count = 1;
			
		}
	}

	if(count%2 == 0){
		ans++;
	}

	cout<<ans<<endl;

	return 0;
}