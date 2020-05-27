#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
/*
* @author: NinhTBMHE141325
* date: 15/1/2020
* purpose: Simple Slot Manchine Programme with login(optional)
* C.L.P0003.c
*/


/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function is get 3 total random numbers using rand();
*/
void spinning(int num[]){
	int i;
	// This for loop loop 3 time
	// Each time assgn a random number to an array contains 3 random number
    for(i = 0; i < 3; i++)
    	// Random number 0 -> 9
        num[i] = rand() % 10;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function consider the prize by the given 3 spun numbers
* @return Integer big prize - 3, 50cents - 2, notthing - 1
*/
int isLucky(int luckyNum[]){
	if(luckyNum[0] == luckyNum[1] && luckyNum[0] == luckyNum[2]){
		return 3;
    }
	else if(luckyNum[0] == luckyNum[1] || luckyNum[1] == luckyNum[2] || luckyNum[0] == luckyNum[2]){
		return 2;
	}
	else
		return 1;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function show 3 spun numbers
*/
void shows(int num[]){
    int i;
    printf("The slot machine shows ");
    // This for loop loop 3 times
    // Each time print a Integer number from the array to console
    for(i = 0; i < 3; i++)
        printf("%d", num[i]);
    printf(" .\n");
}


/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function make sure user input integer numbers in range. If you want to change the range, change min and max
* @param int min and max as size of input
* @return Integer, legal output
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
* date: 16/1/2020
* Purpose: This function show bugget and the menu to console
* @param Float budget
*/
void menu(float budget){
    printf("You have $%g\n", budget);
    printf("Choose one of the following menu options:\n");
    printf("1. Play the Slot machine.\n");
    printf("2. Save game.\n");
    printf("3. Cash out.\n");
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function play the spinning game
* @param Float budget - change the budget following the prize
*/
void push1coin(float *budget){
    int randomDigit[3];
	spinning(randomDigit);
	// This line get the case of prize
    int slotcase = isLucky(randomDigit);
    shows(randomDigit);
    // The condition follow the slotcase
    // 3 - add 10 to the budget
    // 2 - add 0.5 to the budget
    // 1 - nothing
    if(slotcase == 3){
        *budget += 10;
        printf("You win the big prize, $10.00!\n");
	} else if(slotcase == 2) {
        *budget += 0.5;
        printf("You win 50 cents!\n");
	} else 
		printf("Sorry you don't win anything.\n");
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function open file by given source file or create new one if doesn't exist and return the float number
* @param String source file on local disk
* @return Float budget
*/
float openFile(char filename[]){
	float output;
	FILE *save;
	// File manipulation, read plus mode
	// read file, if file doesnt exist, return NULL to pointer
    save = fopen(filename, "r+");
    // If file doesn't exist, create new one
    if(save == NULL){
    	fclose(save);
    	// write mode, create new file by source
    	// assign a default value to file
    	save = fopen(filename, "w+");
		fprintf(save,"%f", 10.00);
    	fclose(save);
    	// re-open file by read mode
  		save = fopen(filename, "r");
	}
	// get the value in the file to output and return
    fscanf(save,"%f", &output);
    fclose(save);
    return output;
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function save file by following float parameter
* @param String source file on local disk, Float value
*/
void saveFile(char filename[], float input){
	remove(filename);
	FILE *save;
	save = fopen(filename, "w+");
	fprintf(save,"%f", input);
    fclose(save);
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function add source and extension to profile name
* @param String source file on local disk, Float value
*/
// This function is locked, because the requirement no need login
// If you want to try, uncomment them.
/*
void login(char name[]){
	printf("Enter your profile: ");
	gets(name);
	char fileExtension[] = ".txt";
	strcat(name, fileExtension);
}
*/
// Drive functions
int main() {
    srand(time(NULL));
    int loop = 1; // loop condition
    
    char filename[20];
//    login(filename);
	strcpy(filename, "profile1.txt");
    float budget = openFile(filename);
    // Initialize a infinity loop, the loop break when loop condition turn 0-false
    while(loop){
        menu(budget);
        // When player broken(buget less or equal 0), remove profile user and end game.
    	if(budget <= 0){
            remove(filename);
    		printf("Sorry, you're out of wallet!\nThankyou for playing, see you next time!");
    		break;
		}
		
        int choice = intInput(1,3);
        switch(choice){
            case 1:{
                budget -= 0.25;
                push1coin(&budget);
                break;
            }
            case 2:{
            	saveFile(filename, budget);
   				printf("Your money had saved.\n");
                break;
            }
            case 3:{
              printf("Thankyou for playing! You end with $%g!", budget);
              loop = 0; //loop condition = 0 -> break the loop
              break;
            }
        }
   }
    return 0;

}

