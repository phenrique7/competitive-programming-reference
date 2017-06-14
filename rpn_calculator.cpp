#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

bool operation(char op){
	return (op == '+' || op == '-' || op == '*' || op == '/'); 
}

int evaluate_rpn(const string &expression){
   int l, r, ans;
   stringstream postfix(expression);
   vector<int> temp;
   string s;
   bool flag = false;
   while(postfix >> s){
      if(operation(s[0])){         
         if(temp.size() < 2){
         	return inf;
         }
         r = temp.back();
         temp.pop_back();
         l = temp.back();
         temp.pop_back();
         if(s[0] == '+'){
				ans = l + r;         
         }
         else if(s[0] == '-'){
				ans = l - r;         
         }
         else if(s[0] == '*'){
				ans = l * r;         
         }
         else if(s[0] == '/'){
         	if(r == 0){
					ans = 1;
					flag = true;         	
         	}
         	else{
					ans = l / r;
				}
         }
         temp.push_back(ans);
      }
      else{
         temp.push_back(stoi(s));
      }
   }
   if(temp.size() != 1){
   	return inf;
   }
  	if(flag){
     	return -inf;
   }
   return temp[0];
}

int main()
{
	int tt;
	string str;

	/*
	input:
   3
   5 1 2 + 4 * + 3 -
   5 1 3 + 4 - / 3 -
   + 5 1  + 4 - / 3 -
	*/

	scanf("%d ", &tt);
	for(int qq = 1; qq <= tt; qq++){
		getline(cin, str);
     	int ans = evaluate_rpn(str);
   	if(ans == inf){
   		puts("Invalid expression.");
   	}
   	else if(ans == -inf){
   		puts("Division by zero.");
   	}
   	else{
   		printf("%d\n", ans);
   	}
	}

	return 0;
}