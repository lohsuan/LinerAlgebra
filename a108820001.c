/*////////////////////////////////////////////////
// Liner algebra class
// topic : matrix caculate
// student ID : 108820001
// Name : Yu-Hsuan, Lo
*/////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
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

void compute_a1(void);
void compute_a2(void);
void compute_a3(void);
void compute_a4(void);
void compute_b1(int [2][2]);
void compute_b2(void);
void compute_inverse(int , int [2][2]);
void compute_c2(int [2][2]);
int second_order_inverse_test(int [2][2]);
bool mul_test(int, int, int, int);
bool add_test(int, int, int, int);
void err_mg(void);

int main(){
  int det;
  int F[2][2] = {0};
  /* a. caculate A + 2B, C-E, A's transpose, E's transpose */
	//a1. A +2B
	if(add_test(a_row, a_col,b_row, b_col)) compute_a1();
	else err_mg();
	//a2. C-E
	if(add_test(c_row, c_col, e_row, e_col)) compute_a2();
	else err_mg();
	// a3. transpose of A
	compute_a3();
	// a4. transpose of E
	compute_a4();

  /* b. caculate F = A*C, G = C*A */
  //b1.  F = A*C
	if(mul_test(a_row, a_col,c_row, c_col)) compute_b1(F);
	else {
		printf("Answer for b1. (F = A*C): \n");
		err_mg();
	}
	//b2.  G = C*A
	if(mul_test(c_row, c_col,a_row, a_col)) compute_b2();
	else {
		printf("\nAnswer for b2. (G = C*A): \n");
		err_mg();
	}

  /*  c. F's inverse   */
  if(second_order_inverse_test(F)) {
    det = second_order_inverse_test(F);
    compute_inverse(det, F);
  }
  else {
		printf("\nAnswer for c1. (inversion of F): \n");
		err_mg();
	}

  compute_c2(F);

	return 0;
}

bool add_test(int row1, int col1, int row2, int col2 ){
	if((row1==row2) && (col1==col2)) return true;
	else return false;
}
bool mul_test(int row1, int col1, int row2, int col2 ){
	if(col1==row2) return true;
	else return false;
}
/* det(F) != 0 */
int second_order_inverse_test(int matrix[2][2]){
  return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
void err_mg(void){
	printf("Undefined !!!\n" );
}

void compute_a1(void) {
	int i, j;
	int ans[10][10];
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < a_col ; j++){
			ans[i][j] = A[i][j] + 2 * B[i][j];
		}
	}
	printf("Answer for a1. (A + 2*B): \n");
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < a_col ; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
void compute_a2(void) {
	int i, j;
	double ans[10][10];
	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < c_col ; j++){
			ans[i][j] = C[i][j] - E[i][j];
		}
	}
	printf("\nAnswer for a2. (C - E): \n");
	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < c_col ; j++){
			printf("%.3f ", ans[i][j]);
		}
		printf("\n");
	}
}
void compute_a3(void) {
	int i, j;
	int ans[5][5];
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < a_col ; j++){
			ans[j][i] = A[i][j];
		}
	}
	printf("\nAnswer for a3. (A.t): \n");
	for(i=0 ; i < a_col ; i++){
		for(j=0 ; j< a_row ; j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}
void compute_a4(void) {
	int i, j;
	double ans[5][5];
	for(i=0 ; i < e_row ; i++){
		for(j=0 ; j < e_col ; j++){
			ans[j][i] = E[i][j];
		}
	}
	printf("\nAnswer for a4. (E.t): \n");
	for(i=0 ; i < e_col ; i++){
		for(j=0 ; j< e_row ; j++){
			printf("%.3f ",ans[i][j]);
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
	printf("\nAnswer for b1. (F = A*C): \n");
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < c_col ; j++){
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
}
void compute_b2(void) {
	int i, j, k;
	int G[10][10] = {0};

	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < a_col ; j++){
			for(k=0 ; k < c_col ; k++){
				G[i][j] += C[i][k] * A[k][j];
			}
		}
	}
	printf("\nAnswer for b2. (G = C*A): \n");
	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < a_col ; j++){
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
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
