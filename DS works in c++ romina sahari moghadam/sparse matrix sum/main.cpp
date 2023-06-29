#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 2;
int a[3][maxn], b[3][maxn], sum_ab[3][2 * maxn];
int n, m, x[2];

void m_sort(){
      //bubble sorting sparse matrix
      for(int i = 0; i < x[0]; i ++){
           for(int j = 1; j < x[0] - i; j ++){
                  if(a[0][j] < a[0][j - 1] or (a[0][j] == a[0][j - 1] and a[1][j] < a[1][j - 1])){
                        swap(a[0][j], a[0][j - 1]);
                        swap(a[1][j], a[1][j - 1]);
                        swap(a[2][j], a[2][j - 1]);
                  }
           }
      }
      for(int i = 0; i < x[1]; i ++){
           for(int j = 1; j < x[1] - i; j ++){
                  if(b[0][j] < b[0][j - 1] or (b[0][j] == b[0][j - 1] and b[1][j] < b[1][j - 1])){
                        swap(b[0][j], b[0][j - 1]);
                        swap(b[1][j], b[1][j - 1]);
                        swap(b[2][j], b[2][j - 1]);
                  }
           }
      }
      return;
}

void sum(){
      int pt[2] = {0, 0}, pt_s = 0;
      a[0][x[0]] = INT_MAX;
      b[0][x[1]] = INT_MAX;
      while(pt[0] + pt[1] < x[0] + x[1]){
            if((a[0][pt[0]] == b[0][pt[1]]) and (a[1][pt[0]] == b[1][pt[1]])){
                  //if rows are equal and columns too
                  sum_ab[0][pt_s] = b[0][pt[1]];
                  sum_ab[1][pt_s] = b[1][pt[1]];
                  sum_ab[2][pt_s] = b[2][pt[1]] + a[2][pt[0]];
                  pt[1] ++;
                  pt[0] ++;
            }
            else if((pt[0] == x[0]) or ((pt[1] != x[1]) and
            ((b[0][pt[1]] < a[0][pt[0]]) or ((b[0][pt[1]] == a[0][pt[0]]) and (b[1][pt[1]] <= a[1][pt[0]]))) )){
                  //row and column of b is smaler
                  sum_ab[0][pt_s] = b[0][pt[1]];
                  sum_ab[1][pt_s] = b[1][pt[1]];
                  sum_ab[2][pt_s] = b[2][pt[1]];
                  pt[1] ++;
            }
            else{
                  //row and column of a in smaler
                  sum_ab[0][pt_s] = a[0][pt[0]];
                  sum_ab[1][pt_s] = a[1][pt[0]];
                  sum_ab[2][pt_s] = a[2][pt[0]];
                  pt[0] ++;
            }
            pt_s ++;
      }
      cout <<endl <<"sum : " <<endl;
      for(int i = 0; i < pt_s; i ++)
            cout <<sum_ab[0][i] <<' ' <<sum_ab[1][i] <<' ' <<sum_ab[2][i] <<endl;
      return;
}

int main(){
      cout <<"enter the number of rows and columns" <<endl;
      cin >>n >>m;
      cout <<"enter the number of first and second sparse matrix rows" <<endl;
      cin >>x[0] >>x[1];
      cout <<"enter the first sparse matrix : (row, column, value)" <<endl;
      for(int i = 0; i < x[0]; i ++){
            cin >>a[0][i] >>a[1][i] >>a[2][i];
      }
      cout <<"enter the second sparse matrix : (row, column, value)" <<endl;
      for(int i = 0; i < x[1]; i ++){
            cin >>b[0][i] >>b[1][i] >>b[2][i];
      }
      m_sort();
      sum();
      return false;
}
