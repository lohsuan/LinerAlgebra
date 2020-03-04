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

// b. caculate F = A*C, G = C*A
int main(){
	//b1.  F = A*C
	compute_b1();
	//b2.  G = C*A
	compute_b2();

	return 0;
}
