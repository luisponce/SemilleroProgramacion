#include <iostream>
#include <String>
#include <algorithm>

using namespace std;



string str;
int best [1000];

int bestFromMe(int j){
		char cur = str[j];
		for (int i = j+1; i < str.length(); ++i)
		{
			if (str[i] == cur && (i-j-1)%2==0)
			{
				best[j] = max(bestFromMe(i)+1, best[j]);
			}
		}

		return best[j];
	}

int main() {
	cin>>str;

	// if (str.length()<2){
	// 	cout<<1;
	// 	return 0;
	// }

	int ans;

	for (int i = 0; i < str.length(); ++i)
	{
		best[i] = 1;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		ans = max(bestFromMe(i), ans);
	}

	cout<<ans<<endl;

	return 0;
}