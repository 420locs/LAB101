#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* @author: NinhTBMHE141325
* date: 19/2/2020
* purpose: Student management program
* C.S.P0047.c
*/

// Seft-define new type of value to store students' information.
// type Student
typedef struct Student{
	char name[100];
//	No needed yet
//   int id; 
} Student;
// Constructor
int intInput(int, int);
void addStudent(char[], int*);
void searchStudent(Student[], int);
int search(Student[], char[], int, int*);
void removeStudent(Student[], int*);
void xoaPhanTu(Student[], int*, int);
void strdisplay(char[]);
void displayAll(Student[], int);
void menu();
int cmpfunc (const void * a, const void * b);
/*
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: run module-functions and make choice to each others
*/
int main(){
	// Declare an array of students, maxium 100 students
    Student student[100];
    int stt = 0, choice;
    // Declare loop value. 1 is True, 0 is False
    int loop = 1;
    printf("=========== Student Management ===========\n");
    while(loop){
    	// Display menu programme to console
    	menu();
    	printf("Enter your choice: ");
    	// Enter input to Choice, value from 1 to 5
    	choice = intInput(1,5);
    	switch (choice){
    		case 1:
    			addStudent(student[stt].name, &stt);
    			break;
    		case 2:
    			removeStudent(student, &stt);
    			break;
    		case 3:
    			searchStudent(student, stt);
    			break;
    		case 4:
    			qsort(student, stt, sizeof(Student), cmpfunc);
    			displayAll(student, stt);
    			break;
    		case 5:
    			printf("Exiting...");
    			// Assign False to loop for end looping
    			loop = 0;
		}
	}	
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
* date: 19/2/2020
* Purpose: This function add new student element to student array
* @param String student_name, int length_of_list (changeable)
*/
void addStudent(char name[], int *stt){
	// If database had enough student return to user that cannot add more
	if(*stt>99)
		printf("The list has full. It cannot add a new student.");
	else{
		// Add name of student as String type
	    printf("Enter new student name: ");
	    gets(name);
	    // list of student decrease 1 element
	    *stt += 1;
	    printf("Student has been added to list successfully!");
	}
}

/*
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function find a student of list by a name that user enter in. And return the position of student if found
* @param Student[] array_of_student, int length_of_list
*/
void searchStudent(Student student[], int stt){
	int pos;
	// Enter a name that user want to search
	char nameSearch[100];
	printf("Who you want to search? ");
	gets(nameSearch);
	// This line call to search function process
	// If found, show to consolse the position of the student
	// If not, say "not found!" :D
	if(search(student, nameSearch, stt, &pos)){		
		printf("found "); strdisplay(nameSearch); printf(" at slot number %d\n", pos+1);
	} 
	else
		printf("not found!\n");
}

/*
* @author: NinhTBMHE141325
* date: 20/2/2020
* Purpose: These functions is "core-engine" to searching function and comparing
* @param Student[] array_of_student, char[] search_name, int length_of_list, int* return_found_position
* @return Boolean value of found or not
*/
int search(Student student[], char nameSearch[], int stt, int *position){
	int i;
	// Scan  all name attributes from object student
	// this line using "String Compare" compare to the name that user entered
	// If found get the position that found and function return True as 1
	// If not, return 0
	for(i = 0; i < stt; i++){
		if(strcmp(student[i].name, nameSearch) == 0){
			*position = i;
			return 1;
		}
	}
	return 0;
}
int cmpfunc (const void * a, const void * b){
     return ( *(char*)a - *(char*)b );
}

/**
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function remove a student from array of students
* @param Student[] array_of_student, int length_of_list (changeable)
*/
void removeStudent(Student student[], int *stt){
	char nameRemove[100];
	printf("what student you want to remove? ");
	gets(nameRemove);
	int i, where;
	// This line called to search function to get position of student that user want to remove
	// If student not exist, print that not found
	if(search(student, nameRemove, *stt, &where) == 0){
		printf("Student name doesn't exist in list.\n");
	}
	// Process remove the student from array and resize the array of student
	// start from the position that user want ti remove
	// present element will be replaced by before it. After that again and again until end of array
	else{
		for(i = where; i < *stt - 1; i++){
	        student[i] = student[i+1];
	    }
	    // Length of array decrease 1 element
		*stt-=1;
		printf("Student name has been removed from list successfully!\n");
	}
}

/**
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function display a String 
* @param String display as single character
*/
void strdisplay(char str[]){
	int i;
	// Loop start from 0 to end of string length
	// Display every single character of array
	for(i = 0; i < strlen(str); i++){
		printf("%c", str[i]);
	}
}

/**
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function display all students from array
* @param Student[] array_of_student, int length_of_list
*/
void displayAll(Student student[], int stt){
	int i;
	// Loop start from 0 to end of student list
	// Listing every student name by called to strdisplay display String
	for(i = 0; i < stt; i++){
		strdisplay(student[i].name);
		printf("\n");
	}
}

/**
* @author: NinhTBMHE141325
* date: 19/2/2020
* Purpose: This function show menu to consolse
*/
void menu(){
	printf("\n*****************************\n");
	printf("1 - Add a student.\n");
	printf("2 - Remove a student.\n");
	printf("3 - Search a student.\n");
	printf("4 - Print list students in an ascending older.\n");
	printf("5 - Exit.\n");
	printf("*****************************\n");
}

