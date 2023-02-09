
#include<iostream>
using namespace std;

class card {

private:
	bool cards;
	char input;
public:
	card();
	card(const bool cards,const char input);
	card(const card& other);


	void change_case();
	bool If_equal(const card&other)const;
	void print_card();


};