#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(int argc, char *argv[]) {
       	if (argc < 5) {
	       	printf("Хуй аргументов. Использование: %s <operand1> <operator> <operand2> ... -k <key>\n", argv[0]);
	       	return 1;
	}
       	int *results = malloc(sizeof(int) * (argc / 3));  
       	if (results == NULL) {
	       	printf("Ошибка выделения памяти!\n");
		return 1;
       	}
       	int result_count = 0;
        int key = 0;
       	int i = 1;

       	while (i < argc) {
	       	if (strcmp(argv[i], "-k") == 0) {
		       	if (i + 1 < argc) {
			       	key = atoi(argv[i + 1]);
			}
		       	else {
			       	printf("Отсутствует ключ дешифрования после '-k'.\n");
			       	free(results);
			       	return 1;
			}
		       	break;
		}
	       
		if (i + 2 >= argc || !is_operator_valid(argv[i + 1][0])) {
		       	printf("Ошибка: некорректный ввод. Ожидается: <operand> <operator> <operand>.\n");
		       	free(results);
		       	return 1;
		}
	       	int left_operand = atoi(argv[i]);
	       	char operator = argv[i + 1][0];
	        int right_operand = atoi(argv[i + 2]);
	        int result = perform_operation(left_operand, operator, right_operand);
	       	if (result == -1) {
		       	printf("Ошибка: некорректный оператор '%c'.\n", operator);
			free(results);
		       	return 1;
		}
		results[result_count++] = result;
	       	i += 3;
	}
       	print_results(results, result_count);
	decrypt_results(results, result_count, key);
       	free(results); 
	return 0;
}
