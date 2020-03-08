#include<stdio.h>
void add(double [10][10], double[10][10], int ,int);
void minus(double [10][10], double[10][10], int ,int);
void multiplication(double [10][10], double[10][10], int, int, int, int);
void anserse(double [10][10], double);
void transpose(double [10][10], int, int);
bool add_test(int m1, int n1, int m2, int n2);
bool mul_test(int m1, int n1, int m2, int n2);
double second_order_anserse_test(double [10][10]);
void err_mg(void);
void print_matrix(int,int);
double ans[10][10] = {0};
int main(){
  int kind;
  int n1, m1, n2, m2, i, j;
  double det;
  double matrix1[10][10], matrix2[10][10];
  printf("Please enter which kind of operation you like to do :\n" );
  printf("1: add  2: minus  3: multiplication\n4: inverse  5: transpose\n" );
  printf("Please enter corresponding number: " );
  scanf("%d", &kind);
  /* input to matrix */
  if (kind == 4){
    m1 = n1 = m2 = n2 = 2;

    printf("Please enter 2x2 matrix's elements: \n" );
    for(i=0 ; i<m1 ; i++){
      for(j=0 ; j<n1 ; j++){
        printf("(%d) X%d: ",i+1,j+1);
        scanf("%lf", &matrix1[i][j]);
      }
    }
  }else if(kind == 5){
    printf("\nNumber of matrix's row (m): " );
    scanf("%d", &m1);
    printf("Number of matrix's column (n): " );
    scanf("%d", &n1);
    printf("Please enter elements: \n" );
    for(i=0 ; i<m1 ; i++){
      for(j=0 ; j<n1 ; j++){
        printf("(%d) X%d: ",i+1,j+1);
        scanf("%lf", &matrix1[i][j]);
      }
    }
  }else {
    printf("\nNumber of first matrix's row (m): " );
    scanf("%d", &m1);
    printf("Number of first matrix's column (n): " );
    scanf("%d", &n1);
    printf("Please enter elements: \n" );
    for(i=0 ; i<m1 ; i++){
      for(j=0 ; j<n1 ; j++){
        printf("(%d) X%d: ",i+1,j+1);
        scanf("%lf", &matrix1[i][j]);
      }
    }
  }
  if(kind == 1 || kind ==2 || kind == 3){
    printf("\nNumber of second matrix's row (m): " );
    scanf("%d", &m2);
    printf("Number of second matrix's column (n): " );
    scanf("%d", &n2);
    for(i=0 ; i<m2 ; i++){
      for(j=0 ; j<n2 ; j++){
        printf("(%d) X%d: ",i+1,j+1);
        scanf("%lf", &matrix2[i][j]);
      }
    }
  }
  switch (kind) {
    case 1:
      if (add_test(m1,n1,m2,n2)) {
        add(matrix1,matrix2,m1,n1);
        print_matrix(m1,n1);
      }
      else err_mg();
      break;
    case 2:
      if (add_test(m1,n1,m2,n2)) {
        minus(matrix1,matrix2,m1,n1);
        print_matrix(m1,n1);
      }
      else err_mg();
      break;
    case 3:
      if (mul_test(m1,n1,m2,n2)) {
        multiplication(matrix1,matrix2,m1,n1,m2,n2);
        print_matrix(m1,n2);
      }
      else err_mg();
      break;
    case 4:
      if (second_order_anserse_test(matrix1)) {
        det = second_order_anserse_test(matrix1);
        anserse(matrix1,det);
        print_matrix(m1,n1);
      }

      break;
    case 5:
      transpose(matrix1,m1,n1);
      print_matrix(n1,m1);
      break;
  }

  return 0;
}
void print_matrix(int m1, int n1){
  int i,j;
  printf("Answer : \n");
	for(i=0 ; i < m1 ; i++){
		for(j=0 ; j < n1 ; j++){
			printf("%.2lf ", ans[i][j]);
		}
		printf("\n");
	}
}
void add(double matrix1[10][10], double matrix2[10][10], int m1, int n1){
  int i, j;
	for(i=0 ; i < m1 ; i++){
		for(j=0 ; j < n1 ; j++){
			ans[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}
void minus(double matrix1[10][10], double matrix2[10][10], int m1, int n1){
  int i, j;
  for(i=0 ; i < m1 ; i++){
    for(j=0 ; j < n1 ; j++){
      ans[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}
void multiplication(double matrix1[10][10], double matrix2[10][10],
                      int m1, int n1, int m2, int n2){
  int i,j,k;
  for(i=0 ; i<m1 ; i++){
    for(j=0 ; j<n2 ; j++){
      for(k=0 ; k<n1 ; k++){
        ans[i][j] += matrix1[i][k] *  matrix2[k][j];
      }
    }
  }
}
void anserse(double matrix1[10][10], double det){
  int i, j;
  ans[0][0] = matrix1[1][1]/det;
  ans[1][1] = matrix1[0][0]/det;
  ans[0][1] = -matrix1[0][1]/det;
  ans[1][0] = -matrix1[1][0]/det;
}
void transpose(double matrix1[10][10], int m1, int n1){
  int i, j;
  for(i=0 ; i<m1 ; i++){
    for(j=0 ; j<n1 ; j++){
      ans[j][i] = matrix1[i][j];
    }
  }
}
bool add_test(int m1, int n1, int m2, int n2){
  if((m1==m2) && (n1==n2)) return true;
  else return false;
}
bool mul_test(int m1, int n1, int m2, int n2){
  if(n1==m2) return true;
	else return false;
}
double second_order_anserse_test(double matrix1[10][10]){
  return matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
}
void err_mg(void){
	printf("Undefined !!!\n" );
}
