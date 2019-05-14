#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    double** a;
    double* y;
    scanf("%d %d", &n, &m);
    a = malloc(sizeof(double*[n]));
    y = malloc(sizeof(double[n]));
    for(int i = 0; i < n; i++){
        a[i] = malloc(sizeof(double[n]));
        for(int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &y[i]);
    }
    //gauss(a, m, n);
    solve(a, y, m, n);
    return 0;
}