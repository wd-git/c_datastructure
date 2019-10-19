#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}

void main() {
	int i = 0;
	int target;

	printf("피보나치 수열을 구합니다.\n f(n) -> n : ");
	scanf("%d", &target);

	printf("%d \n", fibonacci(target));

}