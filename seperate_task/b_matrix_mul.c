/*////////////////////////////////////////////////
// Liner algebra class
// topic : matrix multiplication
// Student ID : 108820001
// Name : Yu-Hsuan, Lo
*/////////////////////////////////////////////////
#include <stdio.h>
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


void compute_b1(void);
void compute_b2(void);
bool mul_test(int, int, int, int);
void err_mg(void);

/* b. caculate F = A*C, G = C*A */
int main(){
	//b1.  F = A*C
	if(mul_test(a_row, a_col,c_row, c_col)) compute_b1();
	else {
		printf("Answer for b1. (F = A*C): \n");
		err_mg();
	}
	//b2.  G = C*A
	if(mul_test(c_row, c_col,a_row, a_col)) compute_b2();
	else {
		printf("Answer for b2. (G = C*A): \n");
		err_mg();
	}

	return 0;
}
bool mul_test(int row1, int col1, int row2, int col2 ){
	if(col1==row2) return true;
	else return false;
}
void err_mg(void){
	printf("Undefined !!!\n" );
}
void compute_b1() {
	int i, j, k;
	int F[10][10] = {0};

	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < c_col ; j++){
			for(k=0 ; k < a_col ; k++){
				F[i][j] += A[i][k] * C[k][j];
			}
		}
	}
	printf("Answer for b1. (F = A*C): \n");
	for(i=0 ; i < a_row ; i++){
		for(j=0 ; j < c_col ; j++){
			printf("%d ", F[i][j]);
		}
		printf("\n");
	}
}
void compute_b2() {
	int i, j, k;
	int G[10][10] = {0};

	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < a_col ; j++){
			for(k=0 ; k < c_col ; k++){
				G[i][j] += C[i][k] * A[k][j];
			}
		}
	}
	printf("Answer for b2. (G = C*A): \n");
	for(i=0 ; i < c_row ; i++){
		for(j=0 ; j < a_col ; j++){
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
}
