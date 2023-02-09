#include "Dictionary.h"

Dictionary::Dictionary()
{
	int size_def=1;
    text =new Definition[size_def];
	text[0] = Definition();
}

Dictionary::Dictionary(int size_def, Definition* text):size_def(size_def)
{
	this->text = new Definition[size_def];
	for (int i = 0; i < size_def; i++)
		this->text[i] = text[i];
}

Dictionary::Dictionary(const Dictionary& other)
{
	this->size_def = other.size_def;
	this->text = new Definition[size_def];
	for (int i = 0; i < size_def; i++)
		this->text[i] = other.text[i];
}

Dictionary::~Dictionary()
{
	delete [] text;
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	size_def = other.size_def;
	text = new Definition[size_def];


	for (int i = 0; i < other.size_def; i++)
		this->text[i] = other.text[i];

	return *this;

}

bool Dictionary::operator==(const Dictionary& other) const
{
	if (size_def == other.size_def) {
		for (int i = 0; i < size_def; i++) 
			if (!(this->text[i] == other.text[i]))
				return false;
			return true;
		
		


	}
	else
		return false;
}



Dictionary& Dictionary::operator+=(Definition add)
{
	bool flag = true;
	for (int i = 0; i < size_def; i++)
		if (this->text[i] == add)
			flag = false;
	if (flag == true)
	{
		Dictionary  temp = *this;
		delete[] text;
		text = new Definition[++size_def];
		for (int i = 0; i < temp.size_def; i++)
			text[i] = temp[i];
		text[size_def - 1] = add;

	}
	return *this;

}

//Dictionary& Dictionary::operator+=(const Dictionary& other)
//{
//	int i;
//	Dictionary temp(*this);
//	int old_size = size_def;
//	delete[] text;
//	size_def += other.size_def;
//	text = new Definition[size_def];
//	for (i = 0; i < old_size; i++) {
//		text[i] = temp.text[i];
//	}
//	for (i = old_size; i < size_def; i++) {
//		text[i] = other.text[i];
//	}
//
//	return *this;
//}
Dictionary& Dictionary::operator-=(int index)
{
	Dictionary  temp = *this;
	delete[] text;
	text = new Definition[--size_def];
	for (int i = 0, j = 0; i < size_def; i++) {
		if (i != index)
			this->text[j++] = temp.text[i];
	}
	return *this;
}

Definition& Dictionary::operator[](int index)
{
	if (index < 0 || index >= size_def) {
		cout << "\n Error : index " << index << " out of range " << endl;
		exit(1);
	}
	else
		return text[index];
}

ostream& operator<<(ostream& out, const Dictionary& obj)
{
	cout << "---------------------------------- Dictinary ----------------------------------" << endl;
	for (int i = 0; i < obj.size_def; i++)
		out << obj.text[i];

	return out;
}

istream& operator>>(istream& in, Dictionary& obj)
{
	int i;
	cout<< "Enter the size of the Dictionary:";
	in >> obj.size_def;
	cout << endl;
	getchar();
	if (obj.size_def < 0) {
		cout << "Error! illegal size";
			exit(1);
	}

	obj.text = new Definition[obj.size_def];

	
	for (i = 0; i <obj.size_def; i++){

    	in >> obj.text[i]; 
	

	}
	cout << "Enter the definitions:" << endl;

	



	return in;
}
