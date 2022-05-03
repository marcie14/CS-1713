/*
    project2-main.c
    Project 2
    Cici Legarde 
    File for project 2 that contains the main function. This file includes the main function
    for a program that will conduct a variety of queries that a user asks for.
*/

#include <stdio.h>
#include <stdlib.h>
#include "routerecords.h"

int main( int argc, char *argv[] )
{
    /* 1. Declare variables here */
    FILE *fileIn = NULL;
    int userChoice = -1;
    int scanCheck = -1;
    int c = 0;
    SearchType search;
    char key_One[5];
    char key_Two[5];
    /* 2. Check command line arguments here. If a command line argument (for the file name) 
        is missing, print out the following: ERROR: Missing file name and end the program */
    if (argc >= 2){    
    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
        printf("Opening %s...\n", argv[1]);
        fileIn = fopen(argv[1], "r");
    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open 
        file and end the program. */
        if(fileIn != NULL){
    
    /* 5. Do the following to load the records into an array of RouteRecords
    	5.1 Call createRecords(), which will dynamically allocate memory for an array of 
            RouteRecords based on what fillRecords() returns. createRecords() returns a pointer 
            to that array. */
                RouteRecord *r = createRecords(fileIn);
   /* 5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will 
        then return the actual number of items the array has. Recall that not all records in 
        the original CSV file will be entered into the array. Print the number of unique routes 
        operated by different airlines: Unique routes operated by airlines: ???*/		
                int size = fillRecords(r, fileIn);
    /*5.3 Close the the file.*/
                fclose(fileIn);
    
    /* 6. Create an infinite loop that will do the following:*/
                while (userChoice != 5){
    		/* 6.1 Call printMenu()*/
    		    printMenu();
    		/*6.2 Ask the user to input a value for the menu*/
    		    scanCheck = scanf("%d", &userChoice);
    		/*6.3 Handle the case in which a non-integer value is entered*/
    		    while (scanCheck == 0) {
                        printf("ERROR: Not an integer. Please try again.");
                        while((c = getchar()) != EOF && c!= '\n'); 
                        scanCheck = scanf("%d", &userChoice);
                    }
    		/*6.4 Create a switch/case statement to handle all the menu options*/
    	            switch (userChoice){
	    		/*6.4.1 Each option requires the user to enter a search key*/
	    		case 1:
                            printf("You've selected to search by Route\n");
                            search = ROUTE;
                            printf("Please enter an origin and destination\n");
                            scanf("%s %s", key_One, key_Two);
                            printf("Searching for %s -> %s...\n", key_One, key_Two);
                            searchRecords(r, size, key_One, key_Two, search);
                            break;
                        case 2: 
                            printf("You've selected to search by Origin\n");
                            search = ORIGIN;
                            printf("Please enter an origin airport code\n");
                            scanf("%s", key_One);
                            printf("Searching for %s as an origin...\n", key_One);
                            searchRecords(r, size, key_One, key_Two, search);
                            break;
                        case 3:
                            
                            printf("You've selected to search by Destination\n");
                            search = DESTINATION;
                            printf("Please enter a destination airport code\n");
                            scanf("%s", key_One);
                            printf("Searching for %s as a destination...\n", key_One);
                            searchRecords(r, size, key_One, key_Two, search);
                            break;
                        case 4:
                            
                            printf("You've selected to search by Airline\n");
                            search = AIRLINE;
                            printf("Please enter an airline code\n");
                            scanf("%s", key_One);
                            printf("Searching for %s as an airline code...\n", key_One);
                            searchRecords(r, size, key_One, key_Two, search);
                            break;
	    		/*6.4.2 Quit needs to free the array */
                        case 5:
                        default:
                            free(r);
                            break;
                    }
                }
        }
        else{
            printf("ERROR: Could not open file.\n");    
        }
    }
    else{
        printf("ERROR: Missing file name.\n");    
    }
    return 0;
}
