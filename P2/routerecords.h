/* 
    route-records.h
    Project 2
    Cici Legarde
    Header file for project 2. This file includes the definitions for all the structs, enums, and
    prototypes for the functions used in a program that will conduct a series of queries a user
    asks for.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef ROUTERECORDS_H
#define ROUTERECORDS_H


/*
    ENUM: SearchType
    ----------------
    Determines what type of search will be conducted.
*/
typedef enum SearchType {ROUTE, ORIGIN, DESTINATION, AIRLINE} SearchType;

/*
    STRUCT: RouteRecord
    -------------------
    Holds the information about a route that is operated by one airline.
        char *origin: origin airport code
        char *destination: destination airport code
        char *airline: airline code
        int *passengers: array of passenger counts. There are six months worth
                    data for each route. (index 0 will represent January's)
*/
typedef struct RouteRecord_struct{
    char origin[4];
    char destination[4];
    char airline[6];
    int passengers[6];
}RouteRecord;


/*-------------------------------- FUNCTIONS -----------------------------------*/

/*
    FUNCTION: createRecords
    -----------------------
    This function creates the array of RouteRecord's and initializes it. The function takes
    in a file pointer, counts the total number of records, dynamically allocates memory for 
    an array of RouteRecords based on the count, and Rewinds. Note that all RouteRecord struct 
    objects has an array of 6 integers. These values are initialized to 0.
    Parameters:
        FILE *fileIn: The csv file that the program will read from.
    Returns: 
        RouteRecord *r: The pointer to the array that was dynamically allocated.
*/
RouteRecord *createRecords(FILE *fileIn);

/*
    FUNCTION: fillRecords
    ---------------------
    This function will process the data in the CSV file. It will go through each record, parse 
    out the record, and enter it into the array.
    Parameters:
        RouteRecord *r: The pointer to the array that was dynamically allocated.
        FILE *fileIn: The csv file that the program will read from.
    Returns:
        int: The number of RouteRecord's used in the array. Note that the actual size will be 
            less than this number since not all records will be used.
*/
int fillRecords(RouteRecord *r, FILE *fileIn);


/*
    FUNCTION: findAirlineRoute
    --------------------------
    This function finds a record in the RouteRecord array with the same origin and destination 
    airport codes and airline.
    Parameters:
        RouteRecord *r: The pointer to the array that was dynamically allocated.
        int length: the length of the array passed in.
        const char *origin: The origin of the flight in question.
        const char *destination: The destination of the flight in question.
        const char *airline: The airline of the flight in question.
    Returns:
        int index: The index number in which these three strings appear in the array. Note that
            the function will return -1 if it cannot find these three strings in the same 
            struct object.
*/
int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination,
    const char *airline);

/*
    FUNCTION: searchRecords
    -----------------------
    This function searches the RouteRecord array and prints out the results of the search.
    Parameters: 
        RouteRecord *r: The pointer to the array that was dynamically allocated.
        int length: The length of the array passed in.
        const char *key1:
        const char *key2:
        SearchType st:
    Returns: Nothing.
*/
void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType st);

/*
    FUNCTION: printMenu
    -------------------
    This function prints the menu.
    Parameters: None.
    Returns: Nothing.
*/
void printMenu();

#endif
