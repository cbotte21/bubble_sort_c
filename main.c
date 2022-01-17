#include <stdlib.h>
#include <stdio.h>

/*
 * My attempt at a c-language bubble sort.
 */

//Prototypes
int getArr(int** arr);
void copyArr(int* old, int* new, int size);
void printArr(int* arr, int size);
void clearKeyboardBuffer(void);
void swapValues(int* arr, int one, int two);
int bubbleSort(int* arr, int size);

int main(int argc, const char* argv[]) {
	//Predeclarations
	int* arr = NULL;
	int size, totalChanges;

	size = getArr(&arr);

	printArr(arr, size);
	totalChanges = bubbleSort(arr, size);
	printArr(arr, size);

	printf("Total Changes: %d\n", totalChanges);
        
	free(arr);
	
	return 0;
}

int getArr(int** arr_p) {
	int* arr;
	int* tmp;
	int size, val;
	for (size = 1; scanf(" %d", &val) == 1; size++, clearKeyboardBuffer()) {
		tmp = (int*)malloc(sizeof(int) * size);
		arr = *arr_p;
		copyArr(arr, tmp, size);
		tmp[size-1] = val;
		free(arr);
		*arr_p = tmp;
	} 
	return size-1;
}

void copyArr(int* old, int* new, int size) {
	if (size == 1) return;
	for (int i = 0; i < size; i++) {
		new[i] = old[i];
	}
}

void printArr(int* arr, int size) {
	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void clearKeyboardBuffer(void) {
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void swapValues(int* arr, int one, int two) {
	int tmp;
	tmp = arr[one];
	arr[one] = arr[two];
	arr[two] = tmp;
}

//Returns number of changes needed.
int bubbleSort(int* arr, int size) {
	int changesMade = 0, totalChanges = 0;
	do {
		changesMade = 0;
		for (int i = 0; i < size; i++) {
			if (i != 0) {
				if (arr[i] < arr[i - 1]) {
					swapValues(arr, i, i-1);
					changesMade++;
				}
			}
			if (i != size-1) {
				if (arr[i] > arr[i + 1]) {
					swapValues(arr, i, i+1);
					changesMade++;
				}
			}
		}
		totalChanges += changesMade;
	} while (changesMade != 0);
	return totalChanges;
}
