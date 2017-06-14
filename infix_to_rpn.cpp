/*
Notacao convencional p/ notacao polonesa reversa. Operandos: a, b, ..., z.
Operadores em ordem de precedencia: ^/*-+, expressoes com parentizacao.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 200;

void in_fix_2_reverse_polish(const string & s){
   int n = s.size(), topo = 0;
   int pilha[N];
   string res, operators = "+-*/^";
   for(int i = 0; i < n; i++){
      if(isalpha(s[i])){
      	printf("%c", s[i]);
      }
      else if( s[i] == '('){
	      pilha[topo++] = '(';
      }
      else if( s[i] == ')') {
         while(topo != -1){
            if(pilha[topo - 1] == '('){
            	topo--;
            	break;
            }
            printf("%c", pilha[--topo]);
         }
      }
      else if( operators.find(s[i]) != string::npos ) {
         while(topo && operators.find(pilha[topo - 1]) != string::npos && operators.find(s[i]) <= operators.find(pilha[topo - 1]) ){
	         printf("%c", pilha[--topo]);
	      }
         pilha[topo++] = s[i];
      }
   }
   while(topo != 0){
   	printf("%c",pilha[--topo]);
   }
   puts("");
}

int main()
{
	string str = "a+b";
	string str2 = "(a+b)/c";
	string str3 = "((a*b)-(c*d))/(e*f)";

	in_fix_2_reverse_polish(str);
	in_fix_2_reverse_polish(str2);
	in_fix_2_reverse_polish(str3);


	return 0;
}