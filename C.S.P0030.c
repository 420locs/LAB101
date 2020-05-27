#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
* @author: NinhTBMHE141325
* date: 20/2/2020
* purpose: Addition of odd/even numbers programme
* C.S.P0030.c
*/

/*
* @author: NinhTBMHE141325
* date: 20/2/2020
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
* date: 20/2/2020
* Purpose: This function input all elements into array
* @param n is called to length of array *arr
*/
void inputMany(int *arr, int n){
	// This function use a for loop start from 1 to last element of the array
	// Enter on-by-one every element until end loop
	printf("Input elements:\n");
	int i;
	for(i = 0; i < n; i++){
		printf("\tElement %d=",i+1);
		arr[i] = intInput(0, INT_MAX);
	}
}

/*
* @author: NinhTBMHE141325
* date: 20/2/2020
* Purpose: This function sum all odd numbers and all even numbers and print result to console 
* @param n is called to length of array *arr
*/
void sumFunction(int *arr, int n){
	// This function use a for loop start from 1 to last element of the array
	// Adding number to "odd" and "even" variable 
	int i, odd = 0, even = 0;	
	for(i = 0; i < n; i++){
	// If arr[i] devide by 2 --> even number
	// If not				 --> odd number
		if(arr[i]%2 == 0)
			even += arr[i];
		else
			odd += arr[i];
	}
	// Print result to console for user 
	printf("Sum of Even=%d\nSum of Odd=%d",even, odd);
}

/*
* @author: NinhTBMHE141325
* date: 20/2/2020
* Purpose: This function is main function of programme. Change mainstream data, change this function
*/
int main(){
	// This line declares "n" variable for get number of elements user want to calculate
	int n;
	printf("Sum Even Odd program\n");
	printf("Enter a number of element n=");
	n = intInput(1, INT_MAX);
	// This line declare a dynamic array following number of element that user entered
	int *arr;
	arr = (int*) malloc (n * sizeof(int));
	// This line called to inputMany for enter all element of array
	// Called to sumFunction for calculate
	inputMany(arr, n);
	sumFunction(arr, n);
	// Free dynamic array
	free(arr);
}
