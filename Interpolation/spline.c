#include <stdio.h>
#include "data.h"

//#define N 4
//extern double a[N][N+1];

int gauss(double a[N][N+1]);
int gauss_jordan(double a[N][N+1]);
void disp_ans(double a[N][N+1]);
void disp_mat(double a[N][N+1]);

int main(void){
  // test data
  // ans : x=1,y=2,z=2,w=1
  double a[N][N+1] = {{2.0,  1.0, -3.0, -2.0, -4.0},
                      {2.0, -1.0, -1.0,  3.0,  1.0},
                      {1.0, -1.0, -2.0,  2.0, -3.0},
                      {-1.0, 1.0,  3.0, -2.0,  5.0}};
  int cnt_a,cnt_b;
  cnt_a = cnt_b = 0;

  // 消去法
  //cnt_a = gauss(a);
  // 掃き出し法
  cnt_b = gauss_jordan(a);

  // 拡大係数行列表示用
  //disp_mat(a);

  // 演算回数比較用
  printf("gauss : %d\ngauss-jordan : %d\n",cnt_a,cnt_b);

  return 0;
}

// はきだし法(ガウス・ジョルダン法)
int gauss_jordan(double a[N][N+1]){
  int i,j,k;
  int cnt = 0;// 演算回数計算用

  for(k = 0;k < N;k++){
    for(j = k+1;j < N+1;j++){
      a[k][j] = a[k][j] / a[k][k];
      cnt++;
      for(i = 0;i < N;i++){
        // i == k 自分の行に対して操作する意味は無い
        if(i == k) continue;
        a[i][j] = a[i][j] - a[k][j] * a[i][k];
        cnt += 2;
      }
    }
  }
  disp_ans(a);

  return cnt;
}

// ガウスの消去法
int gauss(double a[N][N+1]){
  int i,j,k;
  double x[N];
  int cnt = 0;// 演算回数計算用

  // 前進法
  for(k = 0;k < N;k++){
    for(j = k+1;j < N+1;j++){
      a[k][j] = a[k][j] / a[k][k];
      cnt++;
      for(i = k+1;i < N;i++){
        a[i][j] = a[i][j] - a[k][j] * a[i][k];
        cnt += 2;
      }
    }
  }

  // 後退法
  x[N-1] = a[N-1][N];
  for(k = N-1;k >= 0;k--){
    x[k] = a[k][N];
    for(j=k+1;j < N;j++){
      x[k] = x[k] - a[k][j] * x[j];
      cnt += 2;
    }
  }

  // Answer 表示
  for(i = 0;i < N;i++){
    printf("x[%d] = %f\n",i,x[i]);
  }

  return cnt;
}

/*
 * N+1列目にできた解答を表示
 * */
void disp_ans(double a[N][N+1]){
  int i;

  for(i = 0;i < N;i++){
    printf("x[%d] : %lf\n",i,a[i][N]);
  }
}

/*
 * 拡大係数行列を表示する
 * */
void disp_mat(double a[N][N+1]){
  int i,j;

  for(i = 0;i < N;i++){
    for(j = 0;j < N+1;j++){
      printf("%lf ",a[i][j]);
    }
    puts("");
  }
}
