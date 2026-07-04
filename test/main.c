#include <stdio.h>

int main() {

	printf("hello world \n");
	int numbers[20];
	for (int i = 0;i++;i < 20) {
		if (i % 2 == 0) {
			numbers[i] = 2 + i;
		}

		else {
			numbers[i] = -i;
		}


	}
	int j = 0;

	while (j < sizeof(numbers)) {
		printf("number[%d] = %d \n", j, numbers[j]);
		j++;
	}

	return 0;
}