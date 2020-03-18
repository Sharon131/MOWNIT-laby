//
// Created by pastu on 04.03.2020.
//

#include "ex3.h"
#include <math.h>
#include <stdio.h>

float riemann_elem(float s, int k) {
    return (1/powf(k, s));
}

float dirichlet_elem(float s, int k) {
    return (powf(-1, k-1)*riemann_elem(s, k));
}

float sum_upwards(float s, int n, float(*sum_f)(float s, int k)) {
    float sum = 0;

    for (int k=1; k<=n; k++) {
        sum += sum_f(s, k);
    }
    return sum;
}

float sum_backwards(float s, int n, float(*sum_f)(float s, int k)) {
    float sum = 0;

    for (int k=n; k>=1; k--) {
        sum += sum_f(s, k);
    }
    return sum;
}

double riemann_elem_d(double s, int k) {
    return (1/powl(k, s));
}

double dirichlet_elem_d(double s, int k) {
    return (powl(-1, k-1)*riemann_elem_d(s, k));
}

double sum_upwards_d(double s, int n, double(*sum_f)(double s, int k)) {
    double sum = 0;

    for (int k=1; k<=n; k++) {
        sum += sum_f(s, k);
    }
    return sum;
}

double sum_backwards_d(double s, int n, double(*sum_f)(double s, int k)) {
    double sum = 0;

    for (int k=n; k>=1; k--) {
        sum += sum_f(s, k);
    }
    return sum;
}


void third_exercise_main() {

    float s[] = {2, 3.6667f, 5, 7.2f, 10};
    int n[] = {50, 100, 200, 500, 1000};

    float dzeta_up[5][5];
    float eta_up[5][5];
    float dzeta_back[5][5];
    float eta_back[5][5];

    double dzeta_up_d[5][5];
    double eta_up_d[5][5];
    double dzeta_back_d[5][5];
    double eta_back_d[5][5];

    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            dzeta_up[i][j] = sum_upwards(s[i], n[j], riemann_elem);
            eta_up[i][j] = sum_upwards(s[i], n[j], dirichlet_elem);
            dzeta_back[i][j] = sum_backwards(s[i], n[j], riemann_elem);
            eta_back[i][j] = sum_backwards(s[i], n[j], dirichlet_elem);
            dzeta_up_d[i][j] = sum_upwards_d(s[i], n[j], riemann_elem_d);
            eta_up_d[i][j] = sum_upwards_d(s[i], n[j], dirichlet_elem_d);
            dzeta_back_d[i][j] = sum_backwards_d(s[i], n[j], riemann_elem_d);
            eta_back_d[i][j] = sum_backwards_d(s[i], n[j], dirichlet_elem_d);
        }
    }

    printf("Pojedyncza precyzja:\n");

    printf("Sumowanie w przod:\n");
    printf("Dzeta Riemanna:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], dzeta_up[i][0], dzeta_up[i][1], dzeta_up[i][2], dzeta_up[i][3],
                dzeta_up[i][4]);
    }
    printf("------\n");
    printf("Eta dirichleta:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], eta_up[i][0], eta_up[i][1], eta_up[i][2], eta_up[i][3], eta_up[i][4]);
    }
    printf("-------------------------------------------------\n");
    printf("Sumowanie w tyl:\n");

    printf("Dzeta Riemanna:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], dzeta_back[i][0], dzeta_back[i][1], dzeta_back[i][2], dzeta_back[i][3],
                dzeta_back[i][4]);
    }
    printf("------\n");
    printf("Eta dirichleta:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], eta_back[i][0], eta_back[i][1], eta_back[i][2], eta_back[i][3],
               eta_back[i][4]);
    }
    printf("===================================================\n");
    printf("Podwojna precyzja:\n");
    printf("Sumowanie w przod:\n");
    printf("Dzeta:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], dzeta_up_d[i][0], dzeta_up_d[i][1], dzeta_up_d[i][2], dzeta_up_d[i][3],
                dzeta_up_d[i][4]);
    }
    printf("------\n");
    printf("Eta dirichleta:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], eta_up_d[i][0], eta_up_d[i][1], eta_up_d[i][2], eta_up_d[i][3], eta_up_d[i][4]);
    }
    printf("-------------------------------------------------\n");

    printf("Sumowanie w tyl:\n");

    printf("Dzeta Riemanna:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], dzeta_back_d[i][0], dzeta_back_d[i][1], dzeta_back_d[i][2], dzeta_back_d[i][3],
                dzeta_back_d[i][4]);
    }
    printf("------\n");
    printf("Eta dirichleta:\n");
    printf("\t 50 100 200 500 1000\n");
    for (int i=0;i<5;i++) {
        printf("%f\t%.8f %.8f %.8f %.8f %.8f\n", s[i], eta_back_d[i][0], eta_back_d[i][1], eta_back_d[i][2], eta_back_d[i][3],
               eta_back_d[i][4]);
    }

}
