/*////////////////////////////////////////////////
// Liner algebra class
// topic : matrix inverse
// Student ID : 108820001
// Name : Yu-Hsuan, Lo
*/////////////////////////////////////////////////
#include<stdio.h>
#include <math.h>
#define PI 3.1415926
const int A[2][3] = {{-1, 2, 0}, {2, 0, 3}};
const int a_row = 2, a_col = 3;
const int B[2][3] = {{2, 0, -1}, {1, -2, 0}};
const int b_row = 2, b_col = 3;
const int C[3][2] = {{0, 2}, {1, 0}, {-1,1}};
const int c_row = 3, c_col = 2;
const double E[3][2] = {{2, -1}, {PI, log10(2)}, {-2, 6}};
const int e_row = 3, e_col = 2;
const int I[2][2] = {{1, 0}, {1, 0}};
const int i_row = 2, i_col = 2;
double inv[2][2];


int second_older_inverse_test(int [][2]);
void compute_inverse(int , int [2][2]);
void err_mg(void);
void compute_b1(int [2][2]);
void compute_c2(int [2][2]);
/*  c. inverse F  */
int main(){
  int det;
  int F[2][2] = {0};

  compute_b1(F);
  if(second_older_inverse_test(F)) {
    det = second_older_inverse_test(F);
    compute_inverse(det, F);
  }
  else {
		printf("Answer for c1. (inverse of F): \n");
		err_mg();
	}
  compute_c2(F);

  return 0;
}
void err_mg(void){
	printf("Undefined !!!\n" );
}
/* det(F) != 0 */
int second_older_inverse_test(int matrix[2][2]){
  return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
void compute_inverse(int det, int F[2][2]){
  int i, j;
  inv[0][0] = (double)F[1][1]/det;
  inv[1][1] = (double)F[0][0]/det;
  inv[0][1] = (double)-F[0][1]/det;
  inv[1][0] = (double)-F[1][0]/det;

  printf("\nAnswer for c1. (inversion of F) :\n");
  for(i=0 ; i<2 ; i++){
    for(j = 0 ; j<2 ; j++){
      printf("%.2f ", inv[i][j]);
    }
    printf("\n");
  }
}
void compute_b1(int F[2][2]) {
	int i, j, k;

	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < c_col ; j++){
			for(k=0 ; k < a_col ; k++){
				F[i][j] += A[i][k] * C[k][j];
			}
		}
	}
	printf("Answer for F (A*C) : \n");
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < c_col ; j++){
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
}
void compute_c2(int F[2][2]){
  int i, j, k;
  double I[2][2] = {0};
  for(i=0 ; i<2 ; i++){
    for(j=0 ; j<2 ; j++){
      for(k=0 ; k<2 ; k++){
        I[i][j] += (double)F[i][k] * inv[k][j];
      }
    }
  }
  printf("\nAnswer for c2. (F * F's inverse) :\n");
  for(i=0 ; i<2 ; i++){
    for(j=0 ; j<2 ; j++){
      printf("%.2f ", I[i][j]);
    }
    printf("\n");
  }
  printf("Is equal to I(2*2)\n");
}
