#include "Definition.h"

Definition::Definition()
{
	char down[] = "default";
	size_sen = 1;
	word = new String[1];
	sentence = new String[1];
	word[0]=down;
	sentence[0] = down;

}

Definition::Definition(String* word, int size_sen):size_sen(size_sen)
{
	this->word = new String[1];
	this->word[0] = word[0]; 
	sentence = new String[this->size_sen];



}


Definition::~Definition()
{
	delete[]word;
	delete[]sentence;

}

Definition& Definition::operator=(const Definition& other)
{
	size_sen = other.size_sen;
	sentence = new String[size_sen];
	word[0] = other.word[0];


	for (int i = 0; i < other.size_sen; i++)
		this->sentence[i] = other.sentence[i];

	return *this;


}

bool Definition::operator==(const Definition& other) const
{
	if (word != other.word)
		return false;
	if (size_sen == other.size_sen) {
		for (int i = 0; i < size_sen; i++) 
			if (!(this->sentence[i] == other.sentence[i]))
				return false;
		return true;
	}
	else
		return false;
}



//Definition& Definition::operator+=(const Definition& other)
//{
//
//
//		int i;
//		Definition temp(*this);
//		int old_size = size_sen;
//		delete[] sentence;
//		size_sen += other.size_sen;
//		sentence = new String[size_sen];
//		for (i = 0; i < old_size; i++) {
//			sentence[i] = temp.sentence[i];
//		}
//		for (i = old_size; i < size_sen; i++) {
//			sentence[i] = other.sentence[i];
//		}
//
//		return *this;
//
//}
Definition& Definition::operator+=(const String word)
{
	
	bool flag = true;
	for (int i = 0; i < size_sen; i++)
		if (this->sentence[i] == word) {
			flag = false;
			cout << "already Exists!\n";
		}
	if (flag == true)
	{
		Definition  temp = *this;
		sentence = new String[++size_sen];
		for (int i = 0; i < temp.size_sen; i++)
			sentence[i] = temp[i];
		sentence[size_sen - 1] = word;

	}
	return *this;

}
Definition& Definition::operator-=(int index)
{
	Definition  temp = *this;
	delete[] sentence;
	sentence = new String[--size_sen];

	for (int i = 0,j=0; i < size_sen; i++) {
		if(i!=index)
		this->sentence[j++]=temp.sentence[i];
	}

	
	return *this;
	

}

String& Definition::operator[](int index)
{
	if (index <= 0 || index >= size_sen) {
		cout << "\n Error : index " << index << " out of range " << endl;
		exit(1);
	}
	else
		return sentence[index];
}

ostream& operator<<(ostream& out, const Definition& obj)
{
	cout << endl << "------------------------------------------------------------------------------"<<endl;
	if (obj.size_sen == 0)
		out << obj.word[0] << endl;
	else {
		out << "the meaning of:" << obj.word[0] << endl;

	}

	for (int i = 0; i < obj.size_sen; i++) {
		cout << i + 1 << ".";
		out << obj.sentence[i];
	}

	return out;
}

istream& operator>>(istream& in, Definition& obj)

{

	char str[200];
	int number;
	String main_term;

	in >> main_term;
		//getchar();
	cout << endl << "enter the number of definetion for: " << main_term << ":";
	cin >> number;
	cout << endl;
	getchar();
	Definition sen(&main_term,number);
	cout << endl;
	for (int i = 0; i < sen.size_sen; i++)
	{
		cout << i + 1 << ".";
		in.getline(str, 200);
		String sort(str);
		sen.sentence[i] = sort;
		sen.sentence[i].del_space();

	}
	cout << endl;

	obj = sen;

		return in;
	

}

int Definition::getsize_def()
{

	return size_sen;
}

bool Definition::equal_word(const Definition& obj) const
{for(int i=0; i<80; i++){
	if (!(this->word[i] == obj.word[i])) {
		return false;
}}
	return true;
}

//bool Definition::get_word(String word2)
//{
//	for (int i = 0; i < size_sen; i++)
//		if (word[i] == word2) {
//			return true;
//		}
//	cout << "the defintion does'nt exist \n";
//
//		return false;
//}
