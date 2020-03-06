all: bin/a_matrix_cal bin/b_matrix_mul bin/c_matrix_inv

bin/a_matrix_cal: seperate_task/a_matrix_cal.c
	g++ seperate_task/a_matrix_cal.c -o bin/a_matrix_cal

bin/b_matrix_mul: seperate_task/b_matrix_mul.c
	g++ seperate_task/b_matrix_mul.c -o bin/b_matrix_mul

bin/c_matrix_inv: seperate_task/c_matrix_inv.c
	g++ seperate_task/c_matrix_inv.c -o bin/c_matrix_inv
