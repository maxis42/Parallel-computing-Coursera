#pragma once

void Init(double **u, double **f, int N);
int Calc_par_block(double** u, double** f, int N, double eps);
int Calc_seq(double** u, double** f, int N, double eps);
int Calc_seq_block(double** u, double** f, int N, double eps);
void UOutput(double** u, int N);
double** new_arr(int N);
int delete_arr(double** arr, int N);