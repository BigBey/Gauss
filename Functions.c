
#include "Functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int find_main(int k, int n, double** a) {
    double max = 0;
    int index = 0;
    const double eps = 0.00001;

    // Поиск строки с максимальным a[i][k]
    max = fabs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++) {
        if (fabs(a[i][k]) > max) {
            max = fabs(a[i][k]);
            index = i;
        }
    }

    if (max < eps){
        return -1;
    }
    else {
        return index;
    }
}

void transport (int k, int n, int index_of_max, double** a) {

    //меняем местами строку с макисимальным и данную верхнюю местами
    for (int j = 0; j < n; j++)
    {
        double temp = a[k][j];
        a[k][j] = a[index_of_max][j];
        a[index_of_max][j] = temp;
    }
}

void gauss(double** a,  int m,  int n) {
    int index_of_max = 0;
    int k = 0;
    const double eps = 0.000001;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        index_of_max = find_main(k,n,a);
        // Перестановка строк
        if (index_of_max != -1){
            transport(k, n, index_of_max,a);
        }


        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
        }
        k++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }


}

int solve(double** a, double* y, int m, int n){
    double* x = malloc(sizeof(double[n]));
    int index_of_max = 0;
    int k = 0;
    const double eps = 0.00001;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        index_of_max = find_main(k,n,a);
        // Перестановка строк
        if (index_of_max != -1){
            transport(k, n, index_of_max,a);
        }else{
            printf("Нет решений!");
            return 0;
        }

        double temp = y[k];
        y[k] = y[index_of_max];
        y[index_of_max] = temp;

        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }

    for(int k = n -1; k >= 0; k--){
        x[k] = y[k];
        for(int i = 0; i < k; i++){
            y[i] = y[i] - a[i][k]*x[k];
        }
    }

    for(int i = 0; i < n; i++){
        printf("x%d = ",i+1);
        printf("%lf\n", x[i]);
    }
    return 0;
}





