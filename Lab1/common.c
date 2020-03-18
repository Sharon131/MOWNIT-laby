//
// Created by pastu on 04.03.2020.
//

#include "common.h"
#include <stdlib.h>
#include <math.h>

float* create_tab() {
    int len = 10000000;
    float* tab = malloc(sizeof(float)*len);

    for(int i=0; i<len;i++){
        tab[i] = 0.53125f;
    }

    return tab;
}

float* create_table2() {
    int len = 10000000;
    float* tab = malloc(sizeof(float)*len);

    for(int i=0; i<len;i++){
        tab[i] = 0.53125f+(i*10);
    }

    return tab;
}

float absolute_error(float approx_value, float real_value) {
    return fabsf(approx_value-real_value);
}

float relative_error(float approx_value, float real_value) {
    return fabsf((approx_value-real_value)/real_value)*100;
}