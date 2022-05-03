/*
	cards.c
        Project 3
	Cici Legarde

	Functions source file for project 3. This file includes the related function definitions for a program that will play a card-based role-playing game for two computer players.
*/

#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

Card *createCard(){
	Card *ptr;
	ptr = (Card *) malloc(sizeof(Card));
	int n = rand() % 100;

	if (n >= 0 && n <= 40){
		ptr->type = ATTACK;
		ptr->num = (rand() % 5) + 1;
	}
	else if (n >= 41 && n <= 90){
		ptr->type = DEFEND;
		ptr->num = (rand() % 6) + 3;
	}
	else{
		ptr->type = RUN;
		ptr->num = (rand() % 8) + 1;
	}
	ptr->next = NULL;

	return ptr;
}


Card *removeCard(Card *head){

	head = head->next;

	return head;
}


Card *addCard(Card *head, Card *c){
	Card *p = head;

	if (p == NULL){
		return c;
	}

	if (c->num < p->num){
		c->next = p;
		return c;
	}

	while(p->next != NULL){
		if (c->num < p->next->num){
			c->next = p->next;
			p->next = c;
			return c;
		}
		p = p->next;
	}

	p->next = c;

	return c;
}


int getLength(Card *head){
	int count = 0;
	Card *ptr;
	for(ptr = head; ptr != NULL; ptr = ptr->next){
		++count;
	}
	return count;
}


void printCard(Card *head){
	char t;
	if (head->type == ATTACK){
		t = 'A';
	}
	else if (head->type == DEFEND){
		t = 'D';
	}
	else if (head->type == RUN){
		t = 'R';
	}
	printf("%c%d ", t, head->num);
}


void printCards(Card *head){
	Card *ptr;
	
	for(ptr = head; ptr != NULL; ptr = ptr->next){
		printCard(ptr);
	}
}


Card *buildCards(int n){
	int i = 0;
	Card *head = NULL;

	for (i = 0; i < n; ++i){
		Card *x = createCard();
		head = addCard(head, x);
	}
	
	return head;
}


Card *destroyCards(Card *head){
	Card *p = head;
	
	while (p != NULL){
		Card *temp = p;
		p = p->next;
		free(temp);
	}
}
