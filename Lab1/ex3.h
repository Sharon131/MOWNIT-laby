//
// Created by pastu on 04.03.2020.
//

#ifndef LAB1_EX3_H
#define LAB1_EX3_H

float riemann_elem(float s, int k);
float dirichlet_elem(float s, int k);
float sum_upwards(float s, int n, float(*sum_f)(float s, int k));
float sum_backwards(float s, int n, float(*sum_f)(float s, int k));

double riemann_elem_d(double s, int k);
double dirichlet_elem_d(double s, int k);
double sum_upwards_d(double s, int n, double(*sum_f)(double s, int k));
double sum_backwards_d(double s, int n, double(*sum_f)(double s, int k));

void third_exercise_main();


#endif //LAB1_EX3_H
