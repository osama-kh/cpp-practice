#pragma once
#include"Dictionary.h"
#include<iostream>
using namespace std;


class menu {

private:
	Dictionary* dec;

public:
	menu();
	menu(Dictionary* dec);
	~menu();
	void MainMenu();


	friend class Dictionary;


};