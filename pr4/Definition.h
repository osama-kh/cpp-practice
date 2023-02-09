#pragma once
#include <iostream>
using namespace std;
#include "String.h"

class Definition {
private:
	String *word;
	String* sentence;
	int size_sen;

public:
	Definition();
	Definition( String* word, int size_sen);
	~Definition(); 

	Definition& operator =(const Definition& obj);
	bool  operator == (const Definition& obj)const;
	friend ostream& operator << (ostream& out, const Definition& other);
	friend istream& operator >> (istream& in, Definition& other);
	Definition& operator +=(String);
	Definition& operator -=(int);
	String& operator [] (int);
	int getsize_def();
	bool equal_word(const Definition& obj)const;



	friend class String;


};