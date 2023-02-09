#pragma once
#include"Definition.h"
#include <iostream>
using namespace std;

class Dictionary {

private:
	int size_def;
	Definition* text;
public:
	Dictionary();
	Dictionary(int size,Definition* text);
	Dictionary(const Dictionary& other);
	~Dictionary();

	Dictionary& operator =(const Dictionary& obj);
	bool  operator == (const Dictionary& obj)const;
	friend ostream& operator << (ostream& out, const Dictionary& other);
	friend istream& operator >> (istream& in, Dictionary& other);
	Dictionary& operator +=(Definition);
	Dictionary& operator -=(int index);
	Definition& operator [] (int);




	friend class Defination;




};