//
// Created by pastu on 04.03.2020.
//

#include "ex1.h"
#include "common.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

float sum1(float* tab, int len) {
    float sum = 0;
    for(int i=0; i<len; i++){
        sum += tab[i];
    }

    return sum;
}

float sum1_with_print(float* tab, int len) {
    float sum = 0;
    for(int i=0; i<len; i++){
        sum += tab[i];
        if (i%25000 == 0 && i != 0) {
            float real_sum = 13281.25*i/25000;
            float relative = fabsf((sum-real_sum)*100/real_sum);
            printf("Blad wzgledny po %d kroku: %f %%\n", i, relative);
        }
    }

    return sum;
}

float sum1_with_file_print(float* tab, int len) {
    FILE* fp = fopen("../sum1.data", "w");
    float sum = 0;
    for(int i=0; i<len; i++){
        sum += tab[i];
        if (i%25000 == 0 && i != 0) {
            float real_sum = 13281.25f*(i/25000);
            fprintf(fp, "%d\t%f\n", i, relative_error(sum, real_sum));
        }
    }

    float real_sum = 5312500;
    float relative = fabsf((sum - real_sum)*100/real_sum);

    fprintf(fp, "%d\t%f\n", len, relative);
    fclose(fp);
    return sum;
}


float sum2_recursive(float* tab, int left, int right) {
    if (left == right) {
        return tab[left];
    }

    int middle = (right - left)/2;
    return sum2_recursive(tab, left, left+middle) + sum2_recursive(tab, left+middle+1, right);
}

float sum2(float* tab, int len) {
    return sum2_recursive(tab, 0, len-1);
}

void first_exercise_main() {
    float* tab = create_tab();
    float* tab2 = create_table2();
    int len = 10000000;
    float real_sum = 5312500;

    clock_t start1 = clock();

    //float sum = sum1(tab, len);
    //float sum = sum1_with_print(tab, len);
    float sum = sum1_with_file_print(tab, len);

    clock_t end1 = clock();

    clock_t start2 = clock();
    float recursive_sum = sum2(tab, 10000000);
    clock_t end2 = clock();

    double time_taken1 = (double)(end1-start1);
    double time_taken2 = (double)(end2-start2);

    float sum_ord2 = sum1(tab2, len);
    float sum_rec2 = sum2(tab2, len);
    float real_sum2 = 2500000000000000.25f;

    printf("Blad bezwgledny normalnego sumowania: %f\n", absolute_error(sum, real_sum));
    printf("Blad wzgledny normalnego sumowania: %f %%\n", relative_error(sum, real_sum));
    printf("Blad bezwzgledny rekursji: %f \n", absolute_error(recursive_sum, real_sum));
    printf("Blad wzgledny rekursji: %f %%\n", relative_error(recursive_sum, real_sum));
    printf("----------------------------------------------\n");

    printf("Czas wykonania zwyklego sumowania: %f s\n", time_taken1);
    printf("Czas wykonania sumowania poprzez rekursje: %f s\n", time_taken2);
    printf("----------------------------------------------\n");

    printf("Sumowanie posortowanej tablicy:\n");
    printf("Blad bezwzgledny pierwszego sumowania: %f\n", absolute_error(sum_ord2, real_sum2));
    printf("Blad wzgledny normalnego sumowania: %f %%\n", relative_error(sum_ord2, real_sum2));
    printf("Blad bezwzgledny rekursji: %f \n", absolute_error(sum_rec2, real_sum2));
    printf("Blad wzgledny rekursji: %f %%\n", relative_error(sum_rec2, real_sum2));

    free(tab);
}

