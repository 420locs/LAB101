#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
* @author: NinhTBMHE141325
* date: 16/3/2020
* purpose: Generate day of year, day of week and week of year from a string in date format. 
* C.L.P0021.c
*/

// Initialize Date type
typedef struct Date{
	int day;
	int month;
	int year;
} Date;


void menu();
Date setDate();
char* dayOfweek(Date);
int dayOfyear(Date);
int weekOfyear(Date);
void showDetails(Date);
int isLeapYear(int);
int isDateForm(Date);
int _zeller(int, int, int);
int zeller(Date date);

int main(){
	// Initialize a date number and a loop condition
	Date date;
	int loop = 1;
	// Enter loop condition for a infinity loop
	while (loop){
		menu();
		date = setDate();
		showDetails(date);
		
		printf("\nPress any key to continue, Esc to exit the program...\n");
		// This line use getch() to catch the key and return to ch
		char ch = getch();
		if(ch == 27)
			loop = 0;
	}
	return 0;
}

/*
* @author: NinhTBMHE141325
* date: 16/3/2020
* Purpose: This function show menu to console
*/
void menu(){
	printf("Please enter a date (dd/mm/yyyy): ");
}

/*
* @author: NinhTBMHE141325
* date: 17/3/2020
* Purpose: This function caculate day of the week implement Zeller Algorithm
* input Date date
* output String day of the week
*/
int _zeller(int d, int m, int y) {
	// by Zeller Algorithm, january and febnuary must represent for 13 and 14 FOR CACULATING IN ALGORITHM
	// e.g: 13/2/2020 -> 13/14/2019
	if (m == 1){ 
	    m = 13; 
	    y--; 
	}
	if (m == 2){ 
	    m = 14; 
	    y--;
	} 
	// Split yy as number of Year (e.g: 1996 -> 96) cc as number of Century (e.g: 1996 -> 19)
	int yy = y % 100; 
	int cc = y / 100; 
	// Apply Zeller formula
	// More details: https://en.wikipedia.org/wiki/Zeller%27s_congruence
	return (d + 13*(m+1)/5 + yy + yy/4 + cc/4 + 5*cc) % 7;
}
// Rewrite the function to call by Date type
int zeller(Date date) {
   return _zeller(date.day, date.month, date.year);
}
// Return day of the week by the returned number caculated
char* dayOfweek(Date date){
	switch (zeller(date)){
		case 0:
			return "Satuday";
		case 1:
			return "Sunday";
		case 2:
			return "Monday";
		case 3:
			return "Tuesday";
		case 4:
			return "Wednesday";
		case 5:
			return "Thursday";
		case 6:
			return "Friday";
	}
}


/*
* @author: NinhTBMHE141325
* date: 27/2/2020
* Purpose: This function check Leap year 
* @param Integer year
* @return boolean 1-true 0-false
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
* Purpose: This function use AI tech to calculate that type of date that user inputed did exist or not
* yah, of course. There is no any AI :| 
* @param Date type
* @return boolean 1-true 0-false
*/
int isDateForm(Date date){
	int month = date.month;
	int day = date.day;
	int year = date.year;
	// If the given date out of date form -> return false
	// The number of year should between 1000 and 9999 to get most accurate result
	if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999)
		return 0;
	// If the month is 1, 3, 5, 7, 8, 10 or 12, days of month should less or equals 31
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		// if condition true -> return 1. If not return 0
		return day <= 31 ? 1 : 0; 
	// If the month febnuary, days of month should less or equals 28. If leap year, less or equals 29
	else if(month==2){
		if(isLeapYear(year))
			// if condition true -> return 1. If not return 0
			return day <= 29 ? 1 : 0;
		else
			// if condition true -> return 1. If not return 0
			return day <= 28 ? 1 : 0;
	}
	// If the month is 4, 6, 9 or 11, days of month should less or equals 30
	else
		// if condition true -> return 1. If not return 0
		return day <= 30 ? 1 : 0;
}

/*
* @author: NinhTBMHE141325
* date: 17/3/2020
* Purpose: This function set date and check valid of a Date type
* @return Date type
*/
Date setDate(){
	char c1, c2, enter;
	Date date;
	while(1){
		// This line scan by date form d/m/y
		// fflush(stdin); clear junk value and out-buffer-flow values
		int check = scanf("%d%c%d%c%d%c", &date.day, &c1, &date.month, &c2, &date.year, &enter);
		fflush(stdin);
		// If scanf get check not 6 -> wrong type input
		if(check != 6 || enter != 10 || c1 != '/' || c2 != '/')
			printf("Wrong input!\nTry again: ");
		// This condition call to isDateFrom to check valid date
		// If invalid Date form -> print annouce to console and back the loop
		// !(true) -> false
		else if(!isDateForm(date))
			printf("Day, month, year you entered invalid\nTry again: ");
		// If legal Date, return date
		else 
			return date;
	}
}

/*
* @author: NinhTBMHE141325
* date: 16/3/2020
* Purpose: This function caculates number of days in the year from the given date
* @param Date type
* @return boolean 1-true 0-false
*/
int dayOfyear(Date date){
	// Initialize index, total days of months
	int i, dayOfmonths = 0;
	for(i = 1; i < date.month; i++){
		// Add 31 if that month have 31days
		if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			dayOfmonths += 31;
		// Add 29 if febnuary of given year is a leap year. If not add 28 
		else if(i == 2){
			dayOfmonths += 28;
		// This condition call to isLeapYear(int) function to check a year
			if(isLeapYear(date.year))
				dayOfmonths += 1;
		}
		// Add 30 if that month have 30days
		else
			dayOfmonths += 30;
	}
	// return total days in date and days of rest months
	return date.day + dayOfmonths;
}

/*
* @author: NinhTBMHE141325
* date: 16/3/2020
* Purpose: This function caculates number of current week from given date
* @param Date type
*/
int weekOfyear(Date date){
	// get ceil of total days div 7 -> current week
	return ceil(dayOfyear(date) / 7.0);
}

/*
* @author: NinhTBMHE141325
* date: 16/3/2020
* Purpose: This function show details of the given date
* @param Date type
*/
void showDetails(Date date){
	printf("Day of year: %d\n", dayOfyear(date));
	printf("Day of week: %s\n", dayOfweek(date));
	printf("Week of year: %d\n", weekOfyear(date));
}

/*
* @author: NinhTBMHE141325
* date: 16/1/2020
* Purpose: This function is main function of programme. Change mainstream data, change this function
*/

