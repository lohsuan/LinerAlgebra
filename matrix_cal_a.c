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

void compute_a1(void);
void compute_a2(void);
void compute_a3(void);
void compute_a4(void);
bool add_test(int, int, int, int);
void err_mg(void);
// a. caculate A + 2B, C-E, A's transpose, E's transpose
int main(){
	//a1. A +2B
	if(add_test(a_row, a_col,b_row, b_col)) compute_a1();
	else errmg();

	//a2. C-E
	if(add_test(c_row, c_col, e_row, e_col)) compute_a2();
	else errmg();

	// transpose of A
	compute_a3();
	// transpose of E
	compute_a4();

	return 0;
}
bool add_test(int row1,int col1,int row2, int col2 ){
	if((row1==row2) && (col1==col2)) return true;
	else return false;
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
