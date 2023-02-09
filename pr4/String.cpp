#include "String.h"

String::String()
{
	size = 1;
 	string = new char[size+1];
	string [0]= '.';
	string[1] = '\0';
}

String::String(const char* string)
{
	int j = 0;
	while (string[j] != '\0') {
		j++;
	}
	size = j;
	this->string = new char[size];
	for (int i = 0; i < size; i++)
		this->string[i] = string[i];
}

String::String(const String& other)
{
	this->size = other.size;
	this->string = new char[size];
 	for (int i = 0; i < size; i++)
 		this->string[i] = other.string[i];
}

String::~String()
{

  	delete[] string;
}

String& String::operator=(const String& other)
{
	size = other.size;
	string = new char[size];
	for (int i = 0; i < size; i++)
		string[i] = other.string[i];


return *this;


}


const char& String::operator[](const int index) const
{
	if (index < 0 || index >= size) {
		cout << "\n Error : index " << index << " out of range " << endl;
		exit(1);
	}
	else
		return string[index];
}

String& String::operator+=(char latter)
{
	
	String temp = *this;
	delete[] this->string;
	this->size++;
	this->string = new char[this->size];
	for(int i=0; i<size; i++ )
	this->string[i] = temp.string[i];
	string[size - 1] = latter;
	return *this;
}

String& String::operator-=(char latter)
{
	int count = 0;
	String temp = *this;
	delete[] this->string;
	for (int i = 0; i < size; i++) {
		if (temp.string[i] == latter) {
			for (int j = i + 1, index = i; j < size; j++, index++)//temp.string[i] = ' ';
				temp.string[j] = temp.string[index];
			count++;
		}
	}
	this->size = size - count;
	this->string = new char[this->size];
	for(int i = 0; i < size; i++)
	this->string[i] = temp.string[i];//	this->string = temp.string;
	del_space();
	return *this;
	
}

void String::del_space()
{int i,j,index ,count=0;


for (i = 0; i < size; i++) {
		if ((string[i] == ' ' || string[i] == ',' || string[i] == ':' || string[i] == '.') ) {
			for (j = i + 1; j < size && string[j] == ' '; j++);
			if (j != i + 1) {
				count = j - (i + 1);
			for (index = i + 1; j < size; j++, index++ ) {
					string[index] = string[j];

				}
				size -= count;
			}
			if (string[i] == ' ' && i + 1 < size && (string[i + 1] == ',' || string[i + 1] == ':' || string[i + 1] == '.')) {
				for (j = i; j + 1 < size; j++) {
					string[j] = string[j + 1];
					
				}
				size--;
			}
		
			

	}
}
String temp = *this;
delete[] this->string;
this->string = new char[size];
for (i = 0; i < size; i++) {
	this->string[i] = temp.string[i];
}

b_s_latter();

}



	bool String::operator==(const String & other)const
{
	if (size == other.size) {
		for (int i = 0; i < size; i++) 
			if (this->string[i] != other.string[i])
				return false;

		//else
		return true;
	
	}
	else
		return false;

}



ostream& operator<<(ostream& out, const String& obj)
{
	for (int i = 0; i < obj.size; i++)
		out << obj.string[i];
	out << endl;

	return out;
}

istream& operator>>(istream& in, String& obj)
{ 
	char str[80];
	cout << "Enter a term: ";
	in.getline(str,80);
	cout << endl;
	String s(str);
	obj = s;
	obj.del_space();
	return in;


}

void String::b_s_latter()
{

	int i;

	for (i = 1; i < size; i++) {
		if ((string[i - 1] == ',' || string[i - 1] == ':' || string[i - 1] == '.')) {   
			if ('a' <= string[i] && string[i] <= 'z')
				string[i] -= ('a' - 'A');

		}
		else if ('A' <= string[i] && string[i] <= 'Z') {
			string[i] += ('a' - 'A');
		}
	}


	if ('a' <= string[0] && string[0] <= 'z') {
		string[0] -= ('a' - 'A');

	}


	


}

int String::getsize()
{

	return size;
}
