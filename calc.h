#ifndef CALC_H
#define CALC_H

int perform_operation(int left_operand, char operator, int right_operand);
int is_operator_valid(char operator);
void print_results(int *results, int result_count);
void decrypt_results(int *results, int result_count, int key);

#endif

