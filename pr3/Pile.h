#pragma once

#include<iostream>
#include"Card.h"
#include <ctime>
#include <stdlib.h>
# define CD 30
# define maxrow 5
using namespace std;

class Pile {

private:
	card* pile;
	int size;
	void mix();
public:
	Pile();
	Pile(int size);
	Pile(const Pile& other);
	~Pile();
	card& index_input(int );
	void print_pile();
	void put_in_card();
	void show_pile();
	



	friend class Game;








};