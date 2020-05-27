#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* purpose: Array manipulation
* C.S.P0043.c
*/

int intInput(int, int);
void functions(int*, int*);
void addValue(int*, int*);
void display(int*, int);
void search(int*, int);
void swap(int*, int*);
int delet(int*, int, int*);
void remove1(int*, int*);
void removeAll(int*, int*);
void increase(int*, int);
void decrease(int*, int index);
void menu();

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: initialize malloc and run linked to functions
*/
int main(){
	int *arr;
	int index = 0;
	arr = (int*)malloc(index * sizeof(int));
	functions(arr, &index);
	printf("Thankyou for using my program!");
	free(arr);
	return 0;
}

/*
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function make sure user input integer numbers in range. If you want to change the range, change min and max
* @param int min and max as size of input
* @return integer, that user want to enter(as right way we want)
*/
int intInput(int min, int max){
	int i, output, check;
	char ch;
	while(1){
		// This line scan 2 variables integer and character to get out-buffer-flow values or wrong input
		// fflush(stdin); clear junk value and out-buffer-flow values
		check = scanf("%d%c", &output, &ch);
		fflush(stdin);
		//fpurge(stdin);
		// If scanf get more than 2 input, return 2, if fail to get input return 0
		// If scanf did not normally enter right type (a integer and an "enter" - 10 (ASCII) character) --> Not Pass, return to consolse wrong input
		if(check != 2 || ch != 10)
			printf("Wrong input!\nTry again: ");
		// If value input out of default range --> Not Pass, return to consolse wrong input
		else if(output < min || output > max)
			printf("Outrange input!(%d-%d)\nTry again: ",min,max);
		else return output;
	}
}



/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function print menu to console
*/
void menu(){
	printf("1 - Add a value\n");
	printf("2 - Search a value\n");
	printf("3 - Remove the first existence of a value\n");
	printf("4 - Remove all existences of a value\n");
	printf("5 - Print out the array\n");
	printf("6 - Sort the array in ascending order (positions of elements are preserved)\n");
	printf("7 - Sort the array in descending order (positions of elements are preserved)\n");
	printf("8 - Quit\n");
	printf("Enter your choice: ");
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function do a multiple choices linked to all functions of the programme
* This function will be called by main function
*/
void functions(int *arr, int *index){
	int choice, loop = 1;
	// This line use loop for continuously run the programme
	// Linked to each options by cases
	while(loop){
		menu();
		choice = intInput(1,8);
		switch (choice){
			case 1:
				addValue(arr, &(*index));
				break;
			case 2:
				search(arr, *index);
				break;
			case 3:
				remove1(arr, &(*index));
				break;
			case 4:
				removeAll(arr, &(*index));
				break;
			case 5:
				display(arr, *index);
				break;
			case 6:
				increase(arr, *index);
				break;
			case 7:
				decrease(arr, *index);
				break;
			case 8:
				loop = 0;
				break;
		}
		printf("--------------------------------\n");
	}
	
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function add a value to array
*/
void addValue(int *arr, int *index){
	// This line increased array length 1 unit
	// Use realloc to resize dynamic array
	// New element in the array will get an integer value from keyboard(checked by intInput)
	*index += 1;
	arr = (int*) realloc(arr, *index * sizeof(int));
	printf("Input an integer to store: ");
	arr[*index-1] = intInput(INT_MIN,INT_MAX);
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function display current array to console
*/
void display(int *arr, int index){
	printf("All you current array:");
	int i;
	for(i = 0; i < index; i++)
		printf("\t%d", arr[i]);
	printf("\n");
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function search a number and print to console the result
*/
void search(int *arr, int index){
	int searchNumber, i;
	printf("What number you wanna search? ");
	// This line get a integer that user wanna search from the array
	searchNumber = intInput(INT_MIN,INT_MAX);
	// Start a loop start from 0 to maximum length of the array
	// Compare search number to each element of the array 
	// If found, return location of the element. If not print that not found
	for(i = 0; i < index; i++){
		if(searchNumber == arr[i]){
			printf("Your number is in slot number %d in array.\n", i+1);
//			break; // If you want to search only first number found, uncomment this line
		}
	}
	if(i == index)
		printf("Your number not found.\n");
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function swap position of 2 integer number
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function get location of an array and remove it from the array
* @param the function get 1 array, 1 integer number that will remove, size of the array
* @return return to 1 if delete completed. If not found return 0
*/
int delet(int *arr, int deletNum, int *index){
	int detector = -1;
	int i;
	// This line start from 0 to last element of the array
	// Compare each element in the array to number that user want to locate the position of delete number
	// If found, assign location to "detector"
	for(i = 0; i < *index; i++){
		if(deletNum == arr[i]){
			detector = i;
			break;
		}
	}
	// If found the number, detector will different default(-1)
	// Delete completed --> return 1
	// Detector at default(not found) --> return 0
	if(detector != -1){
	// Start a loop from detected location to last element
	// one-by-one swap delete number outside
	// size of the array decrease 1 unit --> fully removed!
		for(i = detector; i < *index; i++){
	        arr[i] = arr[i+1];
	    }
		*index -= 1;
		arr = (int*) realloc(arr, *index * sizeof(int));
	}
	else 
		return 0;
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function remove 1 element from the array and print to console result
* @param the function get 1 array, size of array, pointer to resize the array
*/
void remove1(int *arr, int *index){
	int deletNum;
	printf("What number you wanna remove? ");
	// This line get delete integer number from the keyboard
	// called to function "delet"(return 1-true if delete completed)
	deletNum = intInput(INT_MIN,INT_MAX);
	if(delet(arr, deletNum, &(*index))){
		printf("Removed!\n");
		display(arr, *index);
	}
	else
		printf("Your number not found!\n");
	
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function remove elements that user input from the keyboard and print to console result
* @param the function get 1 array, size of array, pointer to resize the array
*/
void removeAll(int *arr, int *index){
	// "uselessAlert" use to detect that found and removed the number or not
	int i, deletNum, uselessAlert = 0;
	printf("What number you wanna remove? ");
	deletNum = intInput(INT_MIN,INT_MAX);
	// Start loop from 0 to last element of the array
	// called to "delet" function to remove all the existant of the number in the array
	// Deleted --> assign 1-true to "uselessAlert"
	int size = *index;
	for(i = 0; i < size; i++){
			int g = 0;
		if(delet(arr, deletNum, &(*index)))
			uselessAlert = 1;
	}
	// print to console the result and call "display" to show current array
	if(uselessAlert)
		printf("Removed all!\n");
	else
		printf("Your number not found!\n");
	display(arr, *index);
	
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function use bubble sort, sorting the array in ascending order
* @param the function get 1 array, size of array
*/
void increase(int *arr, int index){
	int copy[index];
	int i, j;
	// This loop create a "copy" array of main array and will not change elements' position
	for(i = 0; i < index; i++)
		copy[i] = arr[i];
	// Start loop from 0 to last element of the array
	// Compare each element to every elements entire array
	// Swap these positions if the number that be compared to smaller than the compare number
	for(i = 0; i < index-1; i++)
		for(j = i+1; j < index; j++)
			if(copy[i] > copy[j])
				swap(&copy[i], &copy[j]);
	// After sorting, call to display for print the sorted array to console
	display(copy, index);
}

/*
* @author: NinhTBMHE141325
* date: 26/2/2020
* Purpose: This function use bubble sort, sorting the array in descending order
* @param the function get 1 array, size of array
*/
void decrease(int *arr, int index){
	int copy[index];
	int i, j;
	// This loop create a "copy" array of main array and will not change elements' position
	for(i = 0; i < index; i++)
		copy[i] = arr[i];
	// Start loop from 0 to last element of the array
	// Compare each element to every elements entire array
	// Swap these positions if the number that be compared to bigger than the compare number
	for(i = 0; i < index-1; i++)
		for(j = i+1; j < index; j++)
			if(copy[i] < copy[j])
				swap(&copy[i], &copy[j]);
	// After sorting, call to display for print the sorted array to console
	display(copy, index);
}





