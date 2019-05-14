//
// Created by zenbook on 14.05.2019.
//

#ifndef GAUSS_FUNCTIONS_H
#define GAUSS_FUNCTIONS_H

int find_main(int k,int n, double** a);
void trasport(int k,int n, int index_of_max, double** a);
void gauss(double** a, int m, int n);
int solve(double** a, double* y, int m, int n);


#endif //GAUSS_FUNCTIONS_H
