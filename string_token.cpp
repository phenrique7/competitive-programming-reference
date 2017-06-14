#include <bits/stdc++.h>

using namespace std;

int main()
{
	string myText("some-text-to-tokenize");
    istringstream iss(myText);
    string token;
    while(getline(iss, token, '-')){
        cout << token << endl;
    }

    return 0;
}