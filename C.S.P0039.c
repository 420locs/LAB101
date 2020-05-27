#include <stdio.h>

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* purpose: Simple menu manages program function
* C.S.P0039.c
*/

int isLeapYear(int);
void typeDate(int*, int*, int*);
void processDateForm(int, int, int);
void printASCII(char, char);
void charInput(char*,char*);
int intInput(int, int);
void menu();

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function run the programme
* Declare variables, start loop menu
*/
int main() {
	int loop = 1;
	int month, day, year;
	char a, b;
	// This line use loop for continuously run the programme
	// Linked to each options by cases
	while(loop){
		menu();
		int choice = intInput(1,3);
		switch (choice){
			case 1:
				typeDate(&month, &day, &year);
				processDateForm(month, day, year);
				break;
			case 2:
				charInput(&a, &b);
				printASCII(a, b);
				break;
			case 3:
				loop = 0;
				break;
		}
		printf("--------------------------------\n");
	}
	printf("Thankyou for using my program!");
	return 0;
}

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function check Leap year 
*/
int isLeapYear(int n){ 
	// A leap year is a year that divisible by 400 or divisible by 4 and indivisible by 100
	// If True, return 1
	// False, return 0
	if(n%400 == 0||n%4 == 0 && n%100 != 0)
		return 1;
	else
		return 0;
}

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function input type of date and check that legit or not
*/
void typeDate(int *month, int *day, int *year){
	printf("Enter day(1-31):");
	*day = intInput(1,31);
	printf("Enter month(1-12):");
	*month = intInput(1,12);
	printf("Enter year(1-9999):");
	*year = intInput(1,9999);
}

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function use AI tech to calculate that type of date that user inputed did exist or not
* yah, of course. There're no any AI :| 
*/
void processDateForm(int month, int day, int year){
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day<=31)
			printf("\n%d-%d-%d\n",day,month,year);
		else
			printf("\nDay, month, year you entered invalid\n");
	}
	else if(month==2){
		if(isLeapYear(year)){
			if(day<=29)
				printf("\n%d-%d-%d\n",day,month,year);
			else
				printf("Day, month, year you entered invalid\n");
			}
		else{
			if(day<=28)
				printf("\n%d-%d-%d\n",day,month,year);
			else
				printf("Day, month, year you entered invalid\n");
		}
	}
	else{
		if(day<=30)
			printf("\n%d-%d-%d\n",day,month,year);
		else
			printf("Day, month, year you entered invalid\n");
	}
}

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function print ASCII value of character
* @param 2 point character a and b
*/
void printASCII(char a, char b){
	int i;	
	// If a < b, print ASCII column from b
	if(a < b)
		for(i = b; i >= a; i--)
			printf("%c:%d\n", i, i);
	// If b < a, print ASCII column from a
	else
		for(i = a; i >= b; i--)
			printf("%c:%d\n", i, i);
}

/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function checking char type and make sure user enter legit type of char
* @param return 2 characters by pointer
*/
void charInput(char *c1,char *c2){
	int check;
	char enter;
	do{
		printf("Enter 2 character: ");
		// This line use scanf get 3 characters.
		// fisrt 2 characters for return to pointer
		// last "enter" character for checking legit type of input from the keyboard
		check = scanf("%c%c%c", *(&c1), *(&c2), &enter);
        fflush(stdin);
		// If user didn't enter 2(+1 enter) characters -->return 0 to check -->back the loop
		// If input legit -->return 1 to check -->end loop
        if(check != 3 || enter != 10){
            printf("try again!!\nEnter 2 character: ");
            check = 0;
        }
        else
            check = 1;
            
    }while(check==0);

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
* date: 27/2/2020
* Purpose: This function print options to console
*/
void menu(){
	printf("1- Processing date data\n");
	printf("2- Character data\n");
	printf("3- Quit\n");
	printf("Enter your choice: ");
}

