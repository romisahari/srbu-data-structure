#include <bits/stdc++.h>
using namespace std;

stack <char> s;

bool isoperator(char c){
      if('0' <= c and c <= '9')
            return false;
      return c != 'x';
}

string prefix_to_infix(string pre){
      string ans = "";
      for(int i = 0; i < (int)pre.size() ; i ++){

            if( isoperator( pre[i] ) ){
                  ans += '(';
                  s.push( pre[i] );
            }
            else{
                  if( isoperator( s.top() ) ){
                        ans += pre[i];
                        ans += s.top();
                        s.pop();
                        s.push( 'x' );
                  }
                  else if( s.top() == 'x' ){
                        ans += pre[i];
                        while(!s.empty() and s.top() == 'x'){
                              s.pop();
                              ans += ')';
                        }
                        if(!s.empty()){
                              ans += s.top();
                              s.pop();
                        }
                        s.push('x');
                  }

            }
      }
      s.pop();
      return ans;
}

string prefix_to_postfix(string pre){
      string ans = "";
      for(int i = 0; i < (int)pre.size() ; i ++){

            if( isoperator( pre[i] ) ){
                  s.push( pre[i] );
            }
            else{
                  ans += pre[i];
                  while(!s.empty() and s.top() == 'x'){
                        s.pop();
                        ans += s.top();
                        s.pop();
                  }
                  s.push('x');
            }
      }
      return ans;
}

int main(){
      cout <<"give me a prefix" <<endl;
      string pre;
      cin >>pre;
      cout <<"infix :  " <<prefix_to_infix(pre) <<endl;
      cout <<"postfix :  " <<prefix_to_postfix(pre) <<endl;
      return false;
}
