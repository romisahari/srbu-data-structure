#include <iostream>
using namespace std;

const int maxn = 1e3 + 2;
int a[3][maxn], b[3][maxn], mul[maxn][maxn];
int x[2], na, nb, m;

void m_mul(){
      for(int i = 0; i < x[0]; i ++){
            for(int j = 0; j < x[1]; j ++){
                  /*non zero elemnts shouldnt have one zero in the mul so we
                  just use saparse matrix.
                  for mul column of a should equal with row of b*/
                  if(a[1][i] == b[0][j]){
                        mul[a[0][i]][b[1][j]] += a[2][i] * b[2][j];
                  }
            }
      }
      cout <<endl <<"mul :" <<endl;
      for(int i = 1; i <= na; i ++){
            for(int j = 1; j <= nb; j ++){
                  cout <<mul[i][j] <<' ';
            }
            cout <<endl;
      }
      return;
}

int main(){
      cout <<"enter the number of rows and columns of first and second matrix" <<endl;
      int n1, ma, n2, mb;
      cin >>n1 >>ma >>n2 >>mb;
      if(ma != n2){
            cout <<"mul of these matrixs if imposible";
            return false;
      }
      na = n1;
      m = ma;
      nb = mb;
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
      m_mul();
}
