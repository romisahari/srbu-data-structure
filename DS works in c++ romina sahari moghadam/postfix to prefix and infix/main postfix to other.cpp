#include <bits/stdc++.h>
using namespace std;

stack <char> s;

bool isoperator(char c){
      if(c == 'x' or ('0' <= c and c <= '9'))
            return false;
      return true;
}

string postfix_to_prefix(string post){
      /*we walk on the postfix string from end and push operators and any thing that 
      didnt find its (), in the stack*/ 
      string ans = "";
      for(int i = (int)post.size(); i >= 0; i --){
           if( isoperator(post[i]) ){
                  //in this case the members of () are in the left
                  s.push(post[i]);
           }
           else{
                  //we should use num in ther order
                  ans += post[i];
                  if( isoperator( s.top() ) ){
                        //this num is one of numbers of this operation
                        s.push('x');
                  }
                  else{
                        //we have a operation that have its two numbers
                        //we should calculate the result and push it like x on top of the stack 
                        while(!s.empty() and s.top() == 'x'){
                              s.pop();
                              ans += s.top();
                              s.pop();
                        }
                        s.push('x');
                  }
           }
      }
      //the ans is vise versa 
      for(int i = 0; i < (int)ans.size()/2 ; i ++){
            swap(ans[i], ans[(int)ans.size() - 1 - i]);
      }
      s.pop();
      return ans;
}


string postfix_to_infix(string post){

      string ans = "";
      for(int i = (int)post.size() - 1; i >= 0; i --){
            if( isoperator( post[i] ) ){
                  s.push(post[i]);
                  ans += ')';
            }
            else{
                  if( isoperator( s.top() ) ){
                        ans += post[i];
                        ans += s.top();
                        s.pop();
                        s.push('x');
                  }
                  else{
                        ans += post[i];
                        while(!s.empty() and s.top() == 'x'){
                              ans += '(';
                              s.pop();
                        }
                        if(!s.empty()){
                              ans += s.top();
                              s.pop();
                        }
                        s.push('x');
                  }
            }
      }
      for(int i = 0; i < (int)ans.size()/2 ; i ++){
            swap(ans[i], ans[(int)ans.size() - 1 - i]);
      }
      return ans;
}

int main(){
      cout <<"give me a postfix" <<endl;
      string post;
      cin >>post;
      cout <<"prefix :  "<<postfix_to_prefix(post) <<endl;
      cout <<"infix :  "<<postfix_to_infix(post) <<endl;
}
