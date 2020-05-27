#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* purpose: Convert binary, octal and hexadecimal to decimal programme
* C.S.P0011.c
*/

int bin2dec(char*);
int hex2dec(char*);
int oct2dec(char*);
int intInput();
int inBinCheck(char*);
int inOctCheck(char*);
int inHexCheck(char*);


/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function is main function of programme. Change mainstream data, change this function
*/
int main(){
	char n[50], ch;
	// This line start a while loop running for continuously play game
	// loop will end when loop value get false
	int loop = 1;
	while(loop){
		printf("1. Convert binary number to decimal number\n2. Convert octal number to decimal number\n3. Convert hexadecimal number to decimal number\n4. Exit\n");
		printf("Please choose number (1 - 4): ");
		// This line start switch cases choice (1-4) linked to 3 functions we have
		// Each case will call to a checking function of every type input
		// If checker return 0 user need to enter again until input legit
		// After that call to converting function and print result to console
		int choice = intInput(1,4);
		switch (choice){
			case 1:
				printf("Enter binary number: ");
				while(!inBinCheck(n)) 
					printf("\nPlease input correct form of binary!\nTry again: ");
				printf("Decimal number is: %d\n", bin2dec(n));
				break;
			case 2:
				printf("Enter octal number: ");
				while(!inOctCheck(n)) 
					printf("\nPlease input correct form of octal!\nTry again: ");
				printf("Decimal number is: %d\n", oct2dec(n));
				break;
			case 3:
				printf("Enter hexadecimal number: ");
				while(!inHexCheck(n)) 
					printf("\nPlease input correct form of hexadecimal!\nTry again: ");
				printf("Decimal number is: %d\n", hex2dec(n));
				break;
			case 4: 
			// Exiting choice. This case assign false-0 to "loop" variable for end the loop
				loop = 0;
				break;
		}
		// This line will stop the programme and user can exit the programme by press ESC
		// The loop will continue until user press any key EXCEPT ECS
		// getch(); stop the prgram for debugging and return the key that user press to "ch" char
		// if ch get 'ESC' key, assign 0 to "loop" --> end loop
		printf("\nPress any key to continue, Esc to exit the program\n");
		ch = getch();
		if(ch == 27)
			loop = 0;
	}
	printf("\nThankyou for using Program!<3");
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function convert binary to decimal
* @param String *n contains binary number
* @return decimal number that converted
*/
int bin2dec(char *n){
    int dec = 0;
   	int i, j;
    int length = strlen(n) - 1;
    // This line start a loop from i = 0 to i = length of String binary
    // "j" run backward to read following convert type
    // n[j] - 48 for convert character '1' and '0' to real 1 and 0 value (ASCII)
   	for(i = 0, j = length;i < strlen(n); i++, j--){
   		int temp = n[j] - 48;
   		dec += temp * pow(2,i);
	}
    return dec;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function convert hexadecimal to decimal
* @param String *n contains hexadecimal number
* @return decimal number that converted
*/
int hex2dec(char *n){
    int dec = 0;
    int arrCount = strlen(n) - 1;
   	int i, j;
    // This line start a loop from i = 0 to i = length of String hexadecimal
    // "j" run backward to read following convert type
    // n[j] - 48 for convert digit characters to decimal value (ASCII)
    // n[j] - 55 for convert A,B,C,D,... characters to decimal value (ASCII)
    // n[j] - 87 for convert a,b,c,d,... characters to decimal value (ASCII)
   	for(i = 0, j = arrCount;i < strlen(n); i++, j--){
   		int temp;
		if(isdigit(n[j]))
			temp = n[j] - 48;
		else if(isupper(n[j]))
			temp = n[j] - 55;
		else if(islower(n[j]))
			temp = n[j] - 87;
		
   		dec += temp * pow(16,i);
	}
    return dec;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function convert octal to decimal
* @param String *n contains octal number
* @return decimal number that converted
*/
int oct2dec(char *n){
	int dec = 0;
    int arrCount = strlen(n) - 1;
   	int i, j;
    // This line start a loop from i = 0 to i = length of String octal
    // "j" run backward to read following convert type
    // n[j] - 48 for convert digit characters to decimal value (ASCII)
   	for(i = 0, j = arrCount;i < strlen(n); i++, j--){
   		int temp;
		temp = n[j] - 48;
		
   		dec += temp * pow(8,i);
	}
    return dec;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function checking input by binary number form
* @param String *n contains binary number
* @return boolean value that represent by 1-true 0-false
*/
int inBinCheck(char *n){
	gets(n);
	int i;
    // This line start a loop from i = 0 to i = length of String binary
    // If n[i] = 48 or 49 --> 0 , 1 (ASCII) --> pass
    // If all elements legit, return 1
    // If not, return 0
   	for(i = 0; i < strlen(n); i++){
		if(n[i] == 48 || n[i] == 49) continue;
		else 
			return 0;
	}
	return 1;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function checking input by octal number form
* @param String *n contains octal number
* @return boolean value that represent by 1-true 0-false
*/
int inOctCheck(char *n){
	gets(n);
	int i;
    // This line start a loop from i = 0 to i = length of String octal
    // If n[i] in range from 48 to 55 --> [0,8] (ASCII) --> pass
    // If all elements legit, return 1
    // If not, return 0
   	for(i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 55) continue;
		else return 0;
	}
	return 1;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020 
* Purpose: This function checking input by hexadecimal number form
* @param String *n contains hexadecimal number
* @return boolean value that represent by 1-true 0-false
*/
int inHexCheck(char *n){
	gets(n);
	int i;
    // This line start a loop from i = 0 to i = length of String binary
    // If n[i] in range from 48 to 57 --> decimal vaule (ASCII) --> pass
    // If n[i] in range from 65 to 70 --> A,B,C,D... (ASCII) --> pass
    // If n[i] in range from 97 to 102 --> a,b,c,d... (ASCII) --> pass
    // If all elements legit, return 1
    // If not, return 0
	for(i = 0; i < strlen(n); i++){
		if(n[i] >= 48 && n[i] <= 57) continue;
		else if(n[i] >= 65 && n[i] <= 70) continue;
		else if(n[i] >= 97 && n[i] <= 102) continue;
		else return 0;
	}
	return 1;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
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


