#include <stdio.h>
#include "calc.h"


//калькулятор 
int perform_operation(int left_operand, char operator, int right_operand) {
	switch (operator) {
	       	case '+':
		       	return left_operand + right_operand;
	       	case '-':
		       	return left_operand - right_operand;
	       	case '*':
		       	return left_operand * right_operand;
	       	case '%':
		       	return left_operand % right_operand;
	       	default:
			return -1;
       	}
}
int is_operator_valid(char operator) {
       	return operator == '+' || operator == '-' || operator == '*' || operator == '%';
}

void print_results(int *results, int result_count) {
       	for (int i = 0; i < result_count; i++) {
	       	printf("Ответ №%d: %d\n", i + 1, results[i]);
       	}
}

void decrypt_results(int *results, int result_count, int key) {
       	printf("\nРезультирующая строка: ");
	int first_valid = 1;
	for (int i = 0; i < result_count; i++) {
		int decrypted_value = results[i] - key;
		if (decrypted_value >= 33 && decrypted_value <= 127) {
			if (!first_valid) {
			}
		       	printf("%c", (char)decrypted_value);
			first_valid = 0;
	       	}
       	}
       	printf("\n");
}
