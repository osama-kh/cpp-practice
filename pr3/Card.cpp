#include "Card.h"
#define _CRT_SECURE_NO_WARNINGS 



card::card()// defaulte constructor
{
	cards = false;
	input = 'emp';
}

card::card(const bool cards,const char input)
{
	this->cards = cards;
	this->input = input;

}

card::card(const card& other)
{
	this->cards = other.cards;
	this->input = other.input;
}

void card::change_case() // to flip the cards
{
	if (cards == true)
		cards = false;
	else
		cards = true;

}

bool card::If_equal(const card& other)const //to check if the cards are equal in value
{
	if (this->input == other.input)
		return true;
	else return false;
}


void card::print_card()// to print the cards input
{
	
	if (cards == false)
		cout << " [  ?  ] ";
	else {
		cout << " [  " << input << "  ] ";
	}
}
