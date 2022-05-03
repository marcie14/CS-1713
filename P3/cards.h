
/*
	cards.h
	Project 3
	Cici Legarde
	
	Header file for project 3. This file includes the definitions for all structs, enums, and prototypes for the functions used in a program that will play a card-based role-playing game between two computer players.
*/
#ifndef CARDS_H
#define CARDS_H

/* 
	Enum: TYPE
	----------
	Determines type of card.
*/
typedef enum CardType {ATTACK, DEFEND, RUN} CardType;


/*
	Struct: Card	
	-----------------
	Represents a Card, which is also a node in a linked list.
		CardType type: type of card.
		int num:
*/
typedef struct Card {
	CardType type;
	int num;
	struct Card *next;
}Card;



/*------------------------------FUNCTIONS-----------------------------*/

/*
	Function: *createCard
	-------------------------
	This function dynamically allocates a new Card stuct object and returns a pointer to that struct object which will later be used to insert into a linked list. There are three types of cards: ATTACK, DEFEND, and RUN. ATTACK and DEFEND cards also have a value. This function assigns the cards based on these random chances: 40% ATTACK (random number between 1 and 5 inclusive), 50% DEFEND (random number between 3 and 8 inclusive), and 10% RUN (random number between 1 and 8 inclusive).
	Parameters: None.
	return: Card *head - the head of the linked list.
*/
Card *createCard();


/*
	Function: *removeCard
	---------------------
	This function removes and deallocates the first node in the linked list that the head is pointing at.
	Parameters:
		Card *head - the initial head of the linked list.
	return: Card *head - the new head of the linked list.
*/
Card *removeCard(Card *head);


/*
	Function: *addCard
	------------------
	This function adds a new Card struct object to the linked list that the head parameter is pointing at. The function will add the new node in DESCENDING order of its value regardless of the action.
	Parameters:
		Card *head - the head of the linked list.
		Card *c - the new Card struct object that is to be added to the linked list.
	return: Card *head - the new head of the linked list.
*/
Card *addCard(Card *head, Card *c);


/*
	Function: getLength
	-------------------
	This function returns the length of the linked list that the head is pointing at.
	Parameters:
		Card *head - the head of the linked list.
	return: int length - the length of the linked list.
*/
int getLength(Card *head);


/*
	Function: printCard
	-------------------
	This function prints a single card's corresponding values along with abbreviations: A for ATTACK, D for DEFEND, and R for RUN. 
	Parameters: 
		Card *head - the head of the linked list.
	return: Nothing.
*/
void printCard(Card *head);


/*
	Function: printCards
	--------------------
	This function traverses the linked list that the head is pointing to and call printCard() to print from front to back.
	Parameters: 
		Card *head - the head of the linked list.
	return: Nothing.
*/
void  printCards(Card *head);


/*
	Function: *buildCards
	---------------------
	This function builds a stack of cards using a linked list. It will use createCard() and addCard().
	Parameters:
		int n - determines how many cards are created.
	return: Card *head - the head of the new linked list.
*/
Card *buildCards(int n);


/*
	Function: *destroyCards
	-----------------------
	This function is the destructor for a linked list that the head is pointing at.
	Parameters: 
		Card *head - the head of the linked list.
	return: NULL
*/
Card *destroyCards(Card *head);


#endif
