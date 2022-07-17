#include <stdlib.h>
#include <stdio.h>

/*
 *	Author: Cody Botte
 *	Goal: A bubblesort implementation in c.
 */

//TODO: This program does not work. It has been gutted in preperation for my linkedlist.h library.

//TODO: Abstract clear_keyboard_buffer && ITEM to {name}-lib

//Prototypes
void clear_keyboard_buffer(void);
int bubble_sort(int* arr, int size);

int main(int argc, const char* argv[]) {
	//Predeclarations
	VECTOR hVector;

	int size, totalChanges;

	

	size = getArr(&arr);

	printArr(arr, size);
	totalChanges = bubbleSort(arr, size);
	printArr(arr, size);

	printf("Total Changes: %d\n", totalChanges);
        
	free(arr);
	
	return 0;
}

void clear_keyboard_buffer(void) {
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

//Returns number of changes needed.
int bubble_sort(VECTOR hVector, int size) {
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
