//
// Created by pastu on 04.03.2020.
//

#include "ex4.h"
#include <stdio.h>
#include <stdlib.h>

float* logistic_map(float r_start, float r_end, float x_0, int n);
double* logistic_map_d (double r_start, double r_end, double x_0, int n);
int steps_until_zero(double x_0);

void fourth_exercise_main() {
    FILE* fp = fopen("../ex4.data", "w");
    int n;
    float r_start;
    float r_end;
    float x_0 = 0.1f;
    float x_0s[] = {0.0625f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1};

    // 4.A

    //r_start = 0; r_end = 4; n = 8000;
    //float* res = logistic_map(0, 4, 0.1f, n);
    r_start = 1; r_end = 4; n = 8000;
    float* res = logistic_map(r_start, r_end, x_0s[10], n);

    float r = r_start;
    for (int i=0;i<n;i++) {
        fprintf(fp, "%f\t%f\n", r, res[i]);
        r += (r_end-r_start)/n;
    }

    free(res);
    fclose(fp);

    // 4.B - float
    FILE* fp_b = fopen("../ex4b_1.data", "w");

    r_start = 3.75f;
    r_end = 3.8f;

    float* res_b = logistic_map(r_start, r_end, x_0s[0], n);

    r = r_start;
    for (int i=0;i<n;i++) {
        fprintf(fp_b, "%f\t%f\n", r, res_b[i]);
        r += (r_end-r_start)/n;
    }

    free(res_b);
    fclose(fp_b);

    // 4.B - double
    FILE* fp_d = fopen("../ex4b_2.data", "w");

    double r_start_d = 3.75;
    double r_end_d = 3.8;
    double x_0s_d[] = {0.0625, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
    int n_x = 11;

    double* res_d = logistic_map_d(r_start_d, r_end_d, x_0s_d[0], n);

    double r_d = r_start_d;
    for (int i=0;i<n;i++) {
        fprintf(fp_d, "%f\t%f\n", r_d, res_d[i]);
        r_d += (r_end_d-r_start_d)/n;
    }

    free(res_d);
    fclose(fp_d);

    // 4.C

    int* steps = calloc(n_x, sizeof(int));

    for (int i=0;i<n_x;i++) {
        steps[i] = steps_until_zero(x_0s[i]);
        printf("Ilosc krokow dla x0=%f: %d\n", x_0s[i], steps[i]);
    }

}

float* logistic_map(float r_start, float r_end, float x_0, int n) {
    int m = 5000;
    float step = (r_end-r_start)/n;
    float r = r_start;

    float* result = calloc(n, sizeof(float));

    for (int i=0;i<n;i++) {
        float x_n = x_0;
        for (int j=0;j<m;j++) {
            x_n = r*x_n*(1-x_n);
        }
        result[i] = x_n;
        r+=step;
        m+=1;
    }

    return result;
}

double* logistic_map_d (double r_start, double r_end, double x_0, int n) {
    int m = 5000;
    double step = (r_end-r_start)/n;
    double r = r_start;

    double* result = calloc(n, sizeof(double));

    for (int i=0;i<n;i++) {
        double x_n = x_0;
        for (int j=0;j<m;j++) {
            x_n = r*x_n*(1-x_n);
        }
        result[i] = x_n;
        r+=step;
    }

    return result;
}

int steps_until_zero(double x_0) {
    double r = 4;
    double epsilon = 1.0/(1024*1024);
    double x_n = x_0;
    int steps_no = 0;

    while (x_n > epsilon) {
        x_n = r*x_n*(1-x_n);
        steps_no++;
    }

    return steps_no;
}
