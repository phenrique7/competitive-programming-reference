#include <bits/stdc++.h>

using namespace std;

struct teste{
	int x, y;
	teste(){}
	teste(int _x, int _y) : x(_x), y(_y){}
	bool operator < (teste tt) const{
   	return !(x == tt.x && y == tt.y);
	}
};      

int main()
{
	set<teste> st;

	st.insert(teste(1, 2));
	st.insert(teste(1, 2));
	st.insert(teste(2, -12));

   cout << st.size() << endl;

	return 0;
}
