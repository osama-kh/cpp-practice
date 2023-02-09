#pragma once
#include<iostream>
#include "Pile.h"

using namespace std;

class Game {

private:
	Pile *cards;
	int choose_card();
	
public:
	
	Game( int choice);
	void Run();



};