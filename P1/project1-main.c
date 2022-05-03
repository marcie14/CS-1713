/*
    project1-main.c
    Project 1
    Cici Legarde
    File for project 1 that contains the main function, task 3. This file includes the 
    main function for a game in which a player goes through a series of rooms that can 
    hold either a prize or a monster to fight.
*/

#include <stdio.h>
/* ENABLES USE OF RAND, FREE, & MALLOC */
#include <stdlib.h>
/* USER DEFINED FILE */
#include "monsterbattle.h"

int main()
{
    /*---------------------------- VARIABLE DECLARATIONS ----------------------------- */
    
    /* Number of rooms; to be initialized by user later in code */
    int NUM_RMS = -1;
    
    /* Struct that holds the array of rooms and their contents */
    Room* GAME;

    /* Struct that holds user's hit points and experience points */
    Character player;
    
    /* Variable used in loop */
    int i = 0;
    
    /* Hit Points lost in the room (if any), expressed as a positive number */
    int resultHP = 0;
    
    /* Experience Points gained in the room the user is in */
    int resultXP = 0;
    
    /* variable for random seed */ 
    int seedNum = getRandomNumber(0, 100000);

    /* Set Random Seed */
    srand(seedNum);

    /*
        Initializes the player struct object, to have 50 hitpoints and 0 experience
        points by default 
    */
    player.hitPoints = 50;
    player.experiencePoints = 0;
    
    
    /*
        Welcme Statement and request for user to enter input for NUM_RMS. Dynamically 
        allocates an array of Room structs with the number the user entered. Assumes 
        that the user has entered a positive number. 
    */
    printf("Welcome to the MONSTER BATTLE rooms v.1\n");
    printf ("Please enter the number of rooms you want to endure:\n");
    scanf("%d", &NUM_RMS);
    printf("\n");
    GAME = (Room*)malloc(NUM_RMS * sizeof(Room));


    /* Calls the fillRooms function() to initialize the rooms */
    fillRooms(GAME, NUM_RMS);


    /* 
        Prints out a message to say how many rooms there are and that the challenge 
        has started. 
    */
    printf("%d rooms have been initialized. Let the challenge begin.\n\n", NUM_RMS);
    

    /* Calls printPlayer() to print out the beginning stats */
    printCharacter(player);


    /* ---- BEGIN FOR LOOP that traverses the array of rooms, for each room: ---- */
    for(i = 0; i < NUM_RMS; ++i){
        printf("\n----- ROOM %d OF %d -----\n", (i + 1), NUM_RMS);
        
        /* Calls enterRoom() */
        enterRoom(GAME[i], player, &resultHP, &resultXP);
       
	/*  
            Prints out a message about how many hitpoints were lost or gained 
            while in this room. Prints out this value in a positive number (You lost 
            5 hitpoints while in this room).
        */
        if (resultHP > 0) {
            printf("You gained %d hitpoints in this room.\n", resultHP);    
        }
        else{
            printf("You lost %d hitpoints in this room.\n", (-resultHP));
        }
        
        /*
            Determines if entering the room resulted in a gain in experience points, 
            and print out an appropriate message stating as such. If not experience 
            points were gained, do not print out a message.
        */
        if(resultXP != 0) {
            printf("You gained %d experince points in this room.\n", resultXP);    
        }
        
        
        /*  
            Updates the player's hitpoints with the loss or gain. Never allows for the 
            player's hitpoints to be negative. If it goes below zero, it simply sets the 
            player's hitpoints to 0. If the player's hitpoints are zero, it breaks the 
            loop as the game is over. 
        */
        player.hitPoints = player.hitPoints + resultHP;
        if (player.hitPoints < 0 || player.hitPoints == 0) {
            player.hitPoints = 0;
            player.experiencePoints = player.experiencePoints + resultXP;
            printf("Player ");
            printCharacter(player);
            break;
        }
        
        /* Updates the player's Experience Points */
        player.experiencePoints = player.experiencePoints + resultXP;
        printf("Player ");
       

	/* Calls printPlayer() to print out the updated player's stats. */
        printCharacter(player);

    }
    /*----------------------------- END FOR LOOP --------------------------------- */


    /* 
        Outside the loop, prints out a message of congratulations if the player has any
        hitpoints left. If a player has zero hitpoints, prints out a message of regret. 
    */ 
    if (player.hitPoints == 0){
        printf("\nYou did not survive the MONSTER BATTLE. GAME OVER.\n\n");    
    }
    else{
        printf("\nCongratulations! You've won the MONSTER BATTLE!\n\n");    
    }


    /* Deallocates the array of Rooms */
    free(GAME);
    
    return 0;
}
