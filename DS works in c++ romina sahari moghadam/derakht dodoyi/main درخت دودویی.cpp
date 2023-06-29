#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn], p[maxn], rc[maxn], lc[maxn];

void add(int v, int u){
      if(a[u] > a[v]){
            if(rc[v] != 0)
                  add(rc[v], u);
            else{
                  rc[v] = u;
                  p[u] = v;
            }
            return;
      }
      else{
            if(lc[v] != 0)
                  add(lc[v], u);
            else{
                  lc[v] = u;
                  p[u] = v;
            }
            return;
      }
}

int main(){
      cout <<"enter how many numbers do you want to enter" <<endl;
      int n;
      cin >>n;
      cout <<"enter the numbers" <<endl;
      for(int i = 0; i < n; i ++){
            cin >>a[i];
      }
      p[0] = -1;
      for(int i = 1; i < n; i ++){
            add(0, i);
      }
      cout <<"the tree with root in first number is: " <<endl;
      for(int i = 1; i < n; i ++){
            cout <<i + 1 <<"th number is " <<p[i] + 1 <<"th number's ";
            if(rc[p[i]] == i)
                  cout <<"right child" <<endl;
            else
                  cout <<"left child" <<endl;

      }
}
