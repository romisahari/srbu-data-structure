#include <bits/stdc++.h>
using namespace std;

stack <char> s;

bool isoperator(char c){
      if(c == ')' or c == '(' or ('0' <= c and c <= '9'))
            return false;
      return true;
}

string infix_to_prefix(string infix){
      string ans = "";
      for(int i = (int)infix.size(); i >= 0; i --){
            //saving operators in stack 
            if(infix[i] == ')'){
                  continue;
            }
            else if(infix[i] == '('){
                  //in this case the operator for "(" is the first one in the right
                  //the first operator => top of the stack
                  ans += s.top();
                  s.pop();
            }
            else if( isoperator( infix[i] ) ){
                  s.push( infix[i] );
            }
            else{
                  //in case we have num we should add them in their order
                  ans += infix[i];
            }
      }
      //the answer in generated from the end so it is vice versa
      for(int i = 0; i < (int)ans.size()/ 2; i ++){
            swap(ans[i], ans[(int)ans.size() - i - 1]);
      }
      return ans;
}

string infix_to_postfix(string infix){
      /*this func is similar to upper func.the diffrent is we walk on string from
      start to end. and we do that for ")" */
      string ans = "";
      for(int i = 0; i < (int)infix.size(); i ++){
            if(infix[i] == '('){
                  continue;
            }
            else if(infix[i] == ')'){
                  ans += s.top();
                  s.pop();
            }
            else if( isoperator( infix[i] ) ){
                  s.push(infix[i]);
            }
            else{
                  ans += infix[i];
            }
      }
      return ans;
}

int main(){
      string infix;
      cout <<"give me a infix" <<endl;
      cin >>infix;
      cout <<"prefix :  " <<infix_to_prefix(infix) <<endl;
      cout <<"postfix :  " <<infix_to_postfix(infix) <<endl;
}
