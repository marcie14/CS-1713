/*
    monsterbattle.h
    Project 1
    Cici Legarde
    Header file for project 1, task 1. This file includes the definitions for all the structs,
    enums, and prototypes for the functions used in a game in which a player goes through a
    series of rooms that can hold either a prize or a monster to fight.
*/

#include <stdio.h>
/* enables the use of rand */
#include <stdlib.h>


#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H


/*
    Enum: TYPE
    ----------
    Determines what is in the room.
*/
typedef enum TYPE { EMPTY, PRIZE, MONSTER } TYPE;


/*
    Struct: Character
    -----------------
    Collection of variables related to a character or player in the game
        int hitPoints: Relative endurance of enemy
        int experiencePoints: Relative difficulty of enemy
*/
typedef struct Character_struct {
    int hitPoints;
    int experiencePoints;
}Character;


/*
    Struct: Prize
    -------------
    Collection of Variables related to the prize in a room in the game
*/
typedef struct Prize_struct {
    int points;
}Prize;


/*
    Struct: Room
    Collection of variables related to an individual room in the game
        TYPE contents: Enum type that determines whether the room is empty, 
            holds a prize, or holds a monster (enum type)
        double size: Provides how large the room is in square meters.
        Character enemy: Struct type that holds information of monster if 
        room holds one.
*/
typedef struct Room_struct {
     TYPE contents;     // empty, prize, monster
     Character enemy;   // if there is a monster
     Prize prize;       // if there is a prize
}Room;



/*------------------------------FUNCTIONS-----------------------------*/

/*
    Function: getRandomNumber
    -------------------------
    This function computes a random number between a min and a max 
    (inclusive) and returns it.
        int min: minimum value
        int max: maximum value
*/
int getRandomNumber(int min, int max);


/*
    Function: fillRooms
    -------------------
    This function fills the array of rooms with EMPTY, PRIZE, or MONSTER.
    There is a 10% chance the room is empty, a 40% chance the room has a 
    prize, and a 50% chance the room has a monster in it. This function 
    utilizes the function getRandomNumber() to generate a random number 
    between 0 and 9, inclusive, and use those values to determine which
    type to set.
        Rooms *rooms: the array of the rooms the player will encounter
        int length: length of the array parameter
    Returns: (void) nothing
*/
void fillRooms(Room *rooms, int length);


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
void enterRoom(Room room, Character player, int *resultHP, int *resultXP);


/*
    Function: printCharacter
    ------------------------
    This function prints out the Character's data members in the format:
    "Player (HP: X, XP: Y)"
    It will only be used to print out the player's information.
        Character c: The character (type: struct) that will be printed
    Returns: (void) nothing
*/
void printCharacter(Character c);


#endif
