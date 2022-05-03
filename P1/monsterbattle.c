/*
    monsterbattle.c
    Project 1
    Cici Legarde
    Functions source file for project 1, task 1 & 2. This file includes the related function 
    definitions for a game in which a player goes through a series of rooms that can hold 
    either a prize or a monster to fight.
*/

#include <stdio.h>
/* ENABLES USE OF RAND, FREE, & MALLOC */
#include <stdlib.h>
/* USER DEFINED FILE */
#include "monsterbattle.h"



/*
    Function: getRandomNumber
    -------------------------
    This function computes a random number between a min and a max (inclusive) and returns it.
        int min: minimum value
        int max: maximum value
    Returns: (int) a random integer between the two parameter values (inclusive)
*/
int getRandomNumber( int min, int max ) {
    /* variable declarations */
    int val = 0;
    int seedNum = rand(); /* sets random seed */
    srand(seedNum);
    
    /* random generator for random number between min & max (inclusive) */
    val = (rand() % max) + min;
    
    return val;
}


/*
    Function: fillRooms
    -------------------
    This function fills the array of rooms with a prize, monster, or nothing (empty). There is
    a 10% chance the room is empty, a 40% chance the room has a prize, and a 50% chance the 
    room has a monster in it. This function utilizes the function getRandomNumber() to generate
    a random number between 0 and 9, inclusive, and use those values to deternine which type to
    set.
        Rooms *rooms:
        int length:
    Returns: (void) nothing
*/
void fillRooms( Room *rooms, int length ) {
    int num = 0;
    int i = 0;
    
    for (i = 0; i < length; ++i){
        /* Randomly selects an integer between 1 and 10, inclusive */
        num = getRandomNumber(1, 10);
        
        /* Determines the contents of the room based on the variable num */
        switch(num){
            case 1: /* 10% chance of EMPTY */
                rooms[i].contents = EMPTY;
                break;
            case 2:
            case 3:
            case 4:
            case 5: /* 40% chance of PRIZE */
                rooms[i].contents = PRIZE;
                
                /* Randomly assigns prize with a value between 5 and 10, inclusive*/
                rooms[i].prize.points = getRandomNumber(5, 10);
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10: /* 50% chance of MONSTER */
                rooms[i].contents = MONSTER;
                
                /* Randomly assigns monster's HP with a value between 10 and 30, inclusive */
                rooms[i].enemy.hitPoints = getRandomNumber(10, 30);
                
                /* Conditional statements for determining monster's XP based on HP */
                if(rooms[i].enemy.hitPoints % 3 == 0) {
                    rooms[i].enemy.experiencePoints = 1;
                }
                else {
                    rooms[i].enemy.experiencePoints = 0;    
                }
                break;
            default:
                break;
        }
    }
}

/*
    Function: enterRoom
    -------------------
    This function simulates the character entering a room.
        Room room:
        Character player:
        int *resultHP:
        int *resultXP:
    Returns: (void) nothing
*/
void enterRoom( Room room, Character player, int *resultHP, int *resultXP ) {
    
    /* Conditional statements for player's interaction with room based on contents */
    if(room.contents == PRIZE) { /* if room contains a prize */
        /* print room contents */
        printf("This room has a PRIZE! (Points: %d)\n", room.prize.points);    
        
        /* calculation for HP & XP gained/lost in room */
        *resultHP = room.prize.points;
        *resultXP = 0;
    }    
    else if(room.contents == MONSTER){ /* if room contains a monster */
        /* print room contents */
        printf("This room has a MONSTER! ");
        
        /* print monster's HP & XP */
        printCharacter(room.enemy);
        
        /* calculation for HP & XP gained/lost in room */
        if(player.experiencePoints > room.enemy.hitPoints){
            /* no HP lost if player's XP is greater than monster's HP */
            *resultHP = 0;
        }
        else{
            /* HP lost is monster's HP - player's XP */
            *resultHP = -(room.enemy.hitPoints - player.experiencePoints);
        }
        
        /* player's result XP = monster's XP */
        *resultXP = room.enemy.experiencePoints;
    }
    else { /* if room is empty */
        /* print room contents */
        printf("This room is EMPTY!\n");

        /* calculation for HP & XP in room; unchanged if empty */
        *resultHP = 0;
        *resultXP = 0;
    }
}


/*
    Function: printCharacter
    ------------------------
    This function prints out the Character's data member in the format:
    "Player (HP: X, XP: Y)"
    It will only be used to print out the player's information.
        Character c: 
    Returns: (void) nothing
*/
void printCharacter( Character c ) {
    printf("(HP: %d, XP: %d)\n", c.hitPoints, c.experiencePoints);
}
