#include "Pile.h"

void Pile::mix()// to mix the cards
{
	int i;
	int index1,index2;
	card s;
	for (i = 0; i < size * 3; i++) {
		index1 = rand() % size;
		index2 = rand() % size;
		
		s = pile[index1];
		pile[index1] = pile[index2];
		pile[index2] = s;
		
	}
}




Pile::Pile()// default constructor
{
	size = 20;
	put_in_card();

}


Pile::Pile(int size)//to check if the enterd size legal
{
	if (size <= 52 && size>=2) {

		if (size % 2 == 0)
			this->size = size;

		else  
			this->size = size-1;
		
	}

	else {
		this->size = 20;
	}

	put_in_card();


}

Pile::Pile(const Pile& other)
{
	this->pile = other.pile;
	this->size = other.size;
}

Pile::~Pile()// destuctor 
{
	delete[] pile;
}




card& Pile::index_input(int index)// to get into the selected card
{
	if (index < size && index >= 0) {
		return	pile[index];
	}

	else{
		cout << "Error! the number you entered is'nt correct.";
			exit(1);}
	
}

void Pile::print_pile()// to print the pile 
{
	int i,row=1;
	cout << "	";
	for (i = 0; i < maxrow; i++) {
		cout << "	" << i + 1;
	}
	cout << endl;

	for (i = 0; i < size; i++) {
		
		
		if (i % maxrow == 0) {

			cout << endl;
			cout << row++ << "	";
		}
       pile[i].print_card();


	}

	cout << endl;
}

void Pile::put_in_card()// to fill the cards with values
{
	pile = new card[size];
	char A = 'A';
	
	for (int i = 0; i < size; i++) {

		pile[i++] = card(true, A);
		pile[i] = card(true, A++);
		
	}
	mix();
}

void Pile::show_pile()// to show the pile for a specific time
{
	cout << endl << "get ready you have 30 second to memorize:" << endl;
	print_pile();
	int sec=CD;
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);

	system("cls");
	
	for (int i = 0; i < size; i++) {
		pile[i].change_case();
	}
	

}

