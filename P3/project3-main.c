/*
	project3-main.c
	Project 3
	Cici Legarde

	File for project 3 that contains the main function. This file includes the main function for a card-based role-playing game between two computer players in which they battle each other with action cards.
*/


#include <stdio.h>
#include "cards.h"

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("ERROR: Not enough arguments.");
	}
	else{
		int numCards = -1;
		int scanCheck = 0;
		scanCheck = sscanf(argv[1], "%d", &numCards); 
		if (scanCheck == 0){
			printf("ERROR: Argument entered was not an integer.");
		}
		else{
			if (numCards <= 0){
				printf("ERROR: Argument entered was not above 0.");
			}	
			else{
				printf("\n\n============ PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
				printf("Start size: %d\n", numCards);
				/* use *buildCards for each player's Card linked list */
				Card *player1 = buildCards(numCards);
				Card *player2 = buildCards(numCards);

				/* Print out each player's Cards with printCards() */
				printf("Player 1 starting cards: ");
				printCards(player1);
				printf("\nPlayer 2 starting cards: ");
				printCards(player2);
				
				printf("\n");
				/* Start game loop (while) as long as cards are available */
				
				int player1Cards = getLength(player1);
				int player2Cards = getLength(player2);
				int roundCount = 1;
				while (player1Cards =! 0 && player2Cards != 0){
					printf("----- ROUND %d -----\n", roundCount);
					/* Print player name & number of cards & current card */
					printf("Player 1 (%d): ", player1Cards);
					printCard(player1);
					printf("Player 2 (%d): ", player2Cards);
					printCard(player2);
					printf("\n");

					/* Implement outcomes for each permuation */
					if(player1->type == ATTACK && player2->type == ATTACK){
						printf("Player 1 ATTACKs and Player 2 ATTACKs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						if(player1->num > player2->num){
							printf("Player 1 wins and gets a new card. Player 2 loses their next card into the abyss.\n\n");	
						}
						else{
							printf("Player 1 loses their next card into the abyss. Player 2 wins and gets a new card.\n\n");
						}
					}
					else if (player1->type == ATTACK && player2->type == DEFEND){
						printf("Player 1 ATTACKs and Player 2 DEFENDs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						if (player1->num > player2->num){
							printf("Player 1 wins and gets a new card.\n\n");
						}
						else if (player1->num <= player2->num){
							printf("Player 1 loses, and Player 2 survives.\nPlayer 1 loses their next card into the abyss.\n\n");
						}
					}
					else if (player1->type == ATTACK && player2->type == RUN){
						printf("Player 1 ATTACKs and Player 2 RUNs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						printf("Player 2 loses their next card into the abyss.\n\n");
					}
					else if (player1->type == DEFEND && player2->type == ATTACK){
						printf("Player 1 DEFENDs and Player 2 ATTACKs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						if(player2->num > player1->num){
							printf("Player 1 loses their next card into the abyss. Player 2 wins and gets a new card.\n\n");
						}
						else{
							printf("Player 1 wins and gets a new card. Player 2 loses their next card into the abyss.\n\n");
						}
					}
					else if (player1->type == DEFEND && player2->type == DEFEND){
						printf("Player 1 DEFENDs and Player 2 DEFENDs.\n");
						printf("Nothing happens.\n\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
					}
					else if (player1->type == DEFEND && player2->type == RUN){
						printf("Player 1 DEFENDs and Player 2 RUNs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						printf("Player 1 gets a new card. Player 2 loses their next card into the abyss.\n\n");
					}
					else if (player1->type == RUN && player2->type == ATTACK){
						printf("Player 1 RUNs and Player 2 ATTACKs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						printf("Player 1 loses their next card into the abyss.\n\n");
					}
					else if (player1->type == RUN && player2->type == DEFEND){
						printf("Player 1 RUNs and Player 2 DEFENDs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						printf("Player 1 loses their next card into the abyss. Player 2 gets a new card.\n\n");
					}
					else if (player1->type == RUN && player2->type ==  RUN){
						printf("Player 1 RUNs and Player 2 RUNs.\n");
						player1 = removeCard(player1);
						player2 = removeCard(player2);
						printf("Player 1 loses their next card into the abyss. Player 2 loses their next card into the abyss.\n\n");
					}
					player1Cards = getLength(player1);
					player2Cards = getLength(player2);
					++roundCount;
					
				}
				/* Determine the winner and print outcomes **or both losers** */
				printf("============ GAME OVER ============\n\n");
				printf("Player 1 ending cards: ");
				printCards(player1);
				printf("\nPlayer 2 ending cards: ");
				printCards(player2);
				printf("\n");
				if (player1Cards < player2Cards){
					printf("Player 1 ran out of cards. Player 2 wins!\n");
				}
				else if (player1Cards > player2Cards){
					printf("Player 2 ran out of cards. Player 1 wins!\n");
				}
				else {
					printf("Both players ran out of cards. No one wins!\n");
				}
				printf("The end.\n");
				player1 = destroyCards(player1);
				player2 = destroyCards(player2);
			}
		}
	}
	return 0;
}
