#include <stdio.h>
#include <float.h>
#include <math.h>

#define N 3

int main(void){
  double A[N][N] = {{7, 1, 2},
                    {1, 8, 3},
                    {2, 3, 9}};
  double b[N] = {10, 8, 6};
  double x[N] = {-10, -10, -1};
  double tmp_x[N] = {0, 0, 0};
  int j,k;
  double error, tmp_ans, out;

  error = 1.0;
  // 誤差が小さくなるまで
  while(error > DBL_EPSILON){
    // 誤差を初期化
    error = 0.0;
    tmp_ans = 0.0;

    // 各ベクトルを更新
    for(j = 0; j < N; j++){
      // 最初にその行のbを代入
      tmp_x[j] = b[j];
      // bからそれぞれの値を引いていく
      for(k = 0; k < N; k++){
        if(k == j) {
          // 同じインデックス(j,j)は計算しない
          continue;
        }else{
          // 前のxに対して係数を掛けて引いていく
          tmp_x[j] -= A[j][k] * x[k];
        }
      }
      // 最後に自分の係数で割る
      tmp_x[j] /= A[j][j];
    }

    // 誤差を計算する
    // 前の値と現在の値での誤差を計算するパターン
    /*for(j = 0;j < N;j++){
      error += pow((x[j] - tmp_x[j]), 2);
    }*/

    // 出力結果と実際の答え(b)での誤差(RMSE)を計算するパターン
    for(j = 0;j < N;j++){
      tmp_ans = 0;
      for(k = 0; k < N;k++){
        tmp_ans += A[j][k] * tmp_x[k];
      }
      error += pow(tmp_ans - b[j], 2);
    }
    error = sqrt(error / N);
    printf("error = %lf\n",error);

    // 仮の値を本当のxに代入
    for(j = 0; j < N; j++){
      x[j] = tmp_x[j];
      printf("x[%d] = %lf\n",j ,x[j]);
    }
    printf("\n");
  }

  // 結果を確認
  for(j = 0;j < N;j++){
    out = 0;
    for(k = 0;k < N;k++){
      out += A[j][k] * x[k];
    }
    printf("b[%d]:%lf, my_ans[%d]:%lf\n",j,b[j],j,out);
  }

  return 0;
}
