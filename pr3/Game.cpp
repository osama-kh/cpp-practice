#include "Game.h"
#define _CRT_SECURE_NO_WARNINGS 

int Game::choose_card()// to transform from the entered col and rom to the place of the card
{
	int row, col;
	cout << "row:";
	cin >> row;
	cout << "colmun:";
	cin >> col;

	
	return (row-1)*maxrow+(col-1);
}



Game::Game(int size)// to build a daynamic array of cards
{

	this->cards=new Pile(size);
}

void Game::Run()// the game main run system
{
	int card1, card2;
	cards->show_pile();
	int choose;
	do {


		cout << "choose the first card by entering the row and the colmun:" << endl;
		card1 = choose_card();

		cards->index_input(card1).change_case();
		
		cards->print_pile();

		cout << "choose the second card by entering the row and the colmun:" << endl;
		card2 = choose_card();
		cards->index_input(card2).change_case();
		cards->print_pile();
		int count = 0;
		if (card1 != card2) {

			if (cards->index_input(card1).If_equal(cards->index_input(card2))) {
				cout << "match, ";
				count++;
				if (count == cards->size / 2) {
					cout << endl << "------------------ congratulation! you win ------------------  " << endl;
					exit(1);
			}
				
			}
			else {
				cout << "not match, ";
				cards->index_input(card2).change_case();
				cards->index_input(card1).change_case();
			}
			
		}
		else {
			cout << "Error! you can't choose same cards ";

		}
		
		do{
		cout << "do you want to continue? 1-yes,0-no " << endl;
	
		cin >> choose;
		} while (choose!=1 && choose!=0);

		
	}

	while (choose == 1);

	
}
