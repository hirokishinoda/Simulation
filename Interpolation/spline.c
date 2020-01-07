#include <stdio.h>

#define N 12
//extern double a[N][N+1];

int gauss(double a[N][N+1]);
int gauss_jordan(double a[N][N+1]);
void disp_ans(double a[N][N+1]);
void disp_mat(double a[N][N+1]);

int main(void){
  // test data
  double a[N][N+1] = {{1.0,  1.0, 1.0, 1.0,   0,  0,  0, 0,    0,   0,  0, 0, 9},
                      {  8,    4,   2,   1,   0,  0,  0, 0,    0,   0,  0, 0, 4},
                      {  0,    0,   0,   0,   8,  4,  2, 1,    0,   0,  0, 0, 4},
                      {  0,    0,   0,   0,  27,  9,  3, 1,    0,   0,  0, 0, 6},
                      {  0,    0,   0,   0,   0,  0,  0, 0,   27,   9,  3, 1, 6},
                      {  0,    0,   0,   0,   0,  0,  0, 0,   64,  16,  4, 1, 3},
                      { 12,    4,   1,   0, -12, -4, -1, 0,    0,   0,  0, 0, 0},
                      { 12,    2,   0,   0, -12, -2,  0, 0,    0,   0,  0, 0, 0},
                      {  0,    0,   0,   0,  27,  6,  1, 0,  -27,  -6, -1, 0, 0},
                      {  0,    0,   0,   0,  18,  2,  0, 0,  -18,  -2,  0, 0, 0},
                      {  6,    2,   0,   0,   0,  0,  0, 0,    0,   0,  0, 0, 0},
                      {  0,    0,   0,   0,   0,  0,  0, 0,   24,   2,  0, 0, 0}};

  disp_mat(a);

  // 消去法
  gauss_jordan(a);

  // 拡大係数行列表示用
  disp_mat(a);

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
