//
// Created by pastu on 04.03.2020.
//

#include "ex2.h"
#include "ex1.h"
#include "common.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

float kahan_sum_algorithm(float* tab, int len) {
    float sum = 0;
    float err = 0;

    for (int i=0; i<len; i++) {
        float y = tab[i] - err;
        float temp = sum + y;
        err = (temp - sum) - y;
        sum = temp;
    }
    return sum;
}

void second_exercise_main() {
    float* tab = create_tab();
    float* tab2 = create_table2();
    int len = 10000000;
    float real_sum = 5312500;

    clock_t start1 = clock();
    float sum = sum1(tab, len);
    clock_t end1 = clock();

    clock_t start2 = clock();
    float recursive_sum = sum2(tab, len);
    clock_t end2 = clock();

    clock_t start3 = clock();
    float kahan_sum = kahan_sum_algorithm(tab, len);
    clock_t end3 = clock();

    double time_taken1 = (double)(end1-start1);
    double time_taken2 = (double)(end2-start2);
    double time_taken3 = (double)(end3-start3);

    printf("Blad bezwgledny normalnego sumowania: %f\n", absolute_error(sum, real_sum));
    printf("Blad wzgledny normalnego sumowania: %f %%\n", relative_error(sum, real_sum));
    printf("Blad bezwzgledny rekursji: %f \n", absolute_error(recursive_sum, real_sum));
    printf("Blad wzgledny rekursji: %f %%\n", relative_error(recursive_sum, real_sum));
    printf("Blad bezwgledny kahana: %f \n", absolute_error(kahan_sum, real_sum));
    printf("Blad wzgledny kahana: %f %%\n", relative_error(kahan_sum, real_sum));
    printf("---------------------------------------------------\n");

    printf("Czasy dla pierwszej tablicy:\n");
    printf("Czas wykonania zwyklego sumowania: %f s\n", time_taken1);
    printf("Czas wykonania rekursji: %f s\n", time_taken2);
    printf("Czas wykonania kahana: %f s\n", time_taken3);
    printf("----------------------------------------------------\n");

    clock_t start1_2 = clock();
    float sum_2 = sum1(tab2, len);
    clock_t end1_2 = clock();

    clock_t start2_2 = clock();
    float recursive_sum_2 = sum2(tab2, len);
    clock_t end2_2 = clock();

    clock_t start3_2 = clock();
    float kahan_sum_2 = kahan_sum_algorithm(tab2, len);
    clock_t end3_2 = clock();

    double time_taken1_2 = (double)(end1_2-start1_2);
    double time_taken2_2 = (double)(end2_2-start2_2);
    double time_taken3_2 = (double)(end3_2-start3_2);

    printf("Czasy dla drugiej tablicy:\n");
    printf("Czas wykonania zwyklego sumowania: %f s\n", time_taken1_2);
    printf("Czas wykonania rekursji: %f s\n", time_taken2_2);
    printf("Czas wykonania kahana: %f s\n", time_taken3_2);

    free(tab);
    return;
}
