/*
    route-records.c
    Project 2
    Cici Legarde
    Functions source file for project 2. This file includes the related function definitions for
    a program that will conduct a series of queries that a user asks for.
*/

#include <stdio.h>
#include <string.h>
#include "routerecords.h"

RouteRecord *createRecords(FILE *fileIn){
    char buffer[200];
    int rows = 0;
    int counter = 0;
    int i = 0;
    while (fgets(buffer, 200, fileIn) != NULL){
        ++counter;    
    }
    rewind(fileIn);
    RouteRecord *r = (RouteRecord*)malloc(counter*sizeof(RouteRecord));
    for(i = 0; i < counter; ++i){
        r[i].passengers[0] = 0;
        r[i].passengers[1] = 0;
        r[i].passengers[2] = 0;
        r[i].passengers[3] = 0;
        r[i].passengers[4] = 0;
        r[i].passengers[5] = 0;
    }
    return r;    
}




int fillRecords(RouteRecord *r, FILE *fileIn){
    char buffer[200];
    int rows = 0;
    int counter = 0;
    int i = 0;
    int airLength = 0;
    int month, travellers;
    char orig[4], dest[4], air[4], pax[12];
    while(fgets(buffer, 200, fileIn) != NULL){
        if(counter > 0){
            sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%d", &month, orig, dest, air, pax, &travellers);
            for(i = 0; i < strlen(air); ++i){
                if (air[i] >= 65 && air[i] <= 90){
                    airLength = airLength + 1;    
                }
            }
            if(airLength == 2){
                int redundanceCheck = findAirlineRoute(r, rows, orig, dest, air);
                if(redundanceCheck != -1){
                    r[redundanceCheck].passengers[month] = r[redundanceCheck].passengers[month] + travellers;
                }
                else{
                    strcpy(r[rows].origin, orig);
                    strcpy(r[rows].destination, dest);
                    strcpy(r[rows].airline, air);
                    r[rows].passengers[month] = travellers;
                    ++rows;
                }
            }
        }
        ++counter;
    }
    return rows;    
}




int findAirlineRoute(RouteRecord *r, int length, const char *orig, const char *dest,
    const char *air){
    int index = -1;
    int i = 0;
    for (i = 0; i < length; ++i){
        if(strcmp(r[i].origin, orig) == 0 && strcmp(r[i].destination, dest) == 0 
            && strcmp(r[i].airline, air) == 0){
            index = i;
            break;
        }
    }
    return index;    
}




void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType st){
    int i = 0;
    int printCheck = 0;
    int totalPassengers = 0;
    int pass0 = 100;
    int pass1 = 0;
    int pass2 = 0;
    int pass3 = 0;
    int pass4 = 0;
    int pass5 = 0;
    double avgPass = 0;
    char fly[4], begin[4], end[4];
    printf("Length: %d\n", length);
    for(i = 0; i < length; ++i){
        if(st == ROUTE){
            if(strcmp(r[i].origin, key1) == 0 && strcmp(r[i].destination, key2) == 0){
                    strcpy(fly, r[i].airline);
                    strcpy(begin, r[i].origin);
                    strcpy(end, r[i].destination);
                    printCheck = 1;
                    
                    pass0 = 1 + pass0 + r[i].passengers[0];
                    pass1 = pass1 + r[i].passengers[1];
                    pass2 = pass2 + r[i].passengers[2];
                    pass3 = pass3 + r[i].passengers[3];
                    pass4 = pass4 + r[i].passengers[4];
                    pass5 = pass5 + r[i].passengers[5];
            }
        }
        else{
            if(st == ORIGIN){
                if(strcmp(r[i].origin, key1) == 0){
                    strcpy(fly, r[i].airline);
                    strcpy(begin, r[i].origin);
                    strcpy(end, r[i].destination);
                    printCheck = 1;
                    
                    pass0 = pass0 + r[i].passengers[0];
                    pass1 = pass1 + r[i].passengers[1];
                    pass2 = pass2 + r[i].passengers[2];
                    pass3 = pass3 + r[i].passengers[3];
                    pass4 = pass4 + r[i].passengers[4];
                    pass5 = pass5 + r[i].passengers[5];
                }
            }
            else if(st == DESTINATION){
                if(strcmp(r[i].destination, key1) == 0){
                    strcpy(fly, r[i].airline);
                    strcpy(begin, r[i].origin);
                    strcpy(end, r[i].destination);
                    printCheck = 1;
                
                    pass0 = pass0 + r[i].passengers[0];
                    pass1 = pass1 + r[i].passengers[1];
                    pass2 = pass2 + r[i].passengers[2];
                    pass3 = pass3 + r[i].passengers[3];
                    pass4 = pass4 + r[i].passengers[4];
                    pass5 = pass5 + r[i].passengers[5];
                }
            }
            else{
                if(strcmp(r[i].airline, key1) == 0){
                    strcpy(fly, r[i].airline);
                    strcpy(begin, r[i].origin);
                    strcpy(end, r[i].destination);
                    printCheck = 1;
                    
                    pass0 = pass0 + r[i].passengers[0];
                    pass1 = pass1 + r[i].passengers[1];
                    pass2 = pass2 + r[i].passengers[2];
                    pass3 = pass3 + r[i].passengers[3];
                    pass4 = pass4 + r[i].passengers[4];
                    pass5 = pass5 + r[i].passengers[5];
                }
            }
        }
        if(printCheck != 0){
            printf("Airline: %s\tRoute: %s -> %s\n", fly, begin, end);
            printCheck = 0;
        }
    }

    totalPassengers = pass0 + pass1 + pass2 + pass3 + pass4 + pass5;
    avgPass = totalPassengers / 6.00;

    if(totalPassengers != 0){
        printf("Total Passengers: %d\n", totalPassengers);
        printf("January Passengers: %d\n", pass0);
        printf("February Passengers: %d\n", pass1);
        printf("March Passengers: %d\n", pass2);
        printf("April Passengers: %d\n", pass3);
        printf("May Passengers: %d\n", pass4);
        printf("June Passengers: %d\n", pass5);
        printf("Average Monthly Passengers: %lf\n", avgPass);
    }
    else {
        printf("Search was inconclusive. Please try another search.\n");    
    }
}




void printMenu(){
    printf("\n\n######### Airline Route Records Database MENU #########\n");
    printf("1. Search by Route\n");
    printf("2. Search by Origin Airport\n");
    printf("3. Search by Destination Airport\n");
    printf("4. Search by Airline\n");
    printf("5. Quit\n");
    printf("Enter your selection:\n");
}
