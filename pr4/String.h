#pragma once
#include <iostream>
using namespace std;

class String {

private:
	char* string;
	int size;

public:
	String();
	String(const char* string);
	String(const String& other);
	~String();
	String& operator =(const String& other);
	bool operator == (const String& other)const;
	friend ostream& operator << (ostream& out,const String& obj );
	friend istream& operator >> (istream& in,  String& obj);
	const char& operator [] (int )const;
	String& operator +=(char);
	String& operator -=(char);
	void del_space();
	void b_s_latter();
	int getsize();





};