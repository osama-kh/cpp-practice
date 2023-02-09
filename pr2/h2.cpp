
#include "number.h"

#define _CRT_SECURE_NO_WARNINGS 

Number::Number() {//the default constructor

    Number_of_digits = 1;
    Num = new int[Number_of_digits];
    Num[0] = 0;
    symbol = true;

}


Number::Number(int* Num, int Number_of_digits, bool symbol) {//the initialization list constructor
    change_number(Num, Number_of_digits);
    this->symbol = symbol;
}


Number::Number(const Number& other) {// the copy constructor

    change_number(other.Num, other.Number_of_digits);
    this->symbol = other.symbol;

}

Number::~Number()// the destuctor
{
    delete[]Num;
}

int* Number::get_Num()const// the get function for array num
{


    return Num;
}

int  Number::get_Number_of_digits()const // the get function for the size of the array num
{
    return Number_of_digits;
}

bool Number::get_symbol()const // the get function for sympol of the array num
{
    return symbol;
}





void Number::change_symbol()//function for change the symbol of the array
{
    this->symbol = !symbol;

}

void Number::change_number(int* Num, int Number_of_digits) { // function to change the array num and its size

    if (Number_of_digits <= 0) {
        this->Number_of_digits = 1;
        this->Num = new int[this->Number_of_digits];
        this->Num[0] = 0;
    }
    else {
        this->Number_of_digits = Number_of_digits;

        this->Num = new int[Number_of_digits];

        for (int i = 0; i < Number_of_digits; i++)
            this->Num[i] = Num[i];

    }
}


void Number::print_number()// function to print the number 
{
    if (this->symbol == false)
        cout << switch_arr2intger() * -1;

    else
        cout << switch_arr2intger();

}



int Number::sum_of_digits() // function to calculate the sum of the digits of the number 
{
    int sum = 0, i;
    for (i = 0; i < this->Number_of_digits; i++)
        sum = this->Num[i] + sum;

    return sum;
}

int Number::switch_arr2intger()const // function to switch the array to intger tybe
{

    int number = 0, i = 0;

    while (i != Number_of_digits)
    {
        number = (number + Num[i]) * 10;
        i++;
    }
    number = number / 10;


    return number;
}

bool Number::palindrome()// function to test if the number is palindrome
{
    int help, sum = 0;
    int num = switch_arr2intger();

    help = num;
    while (help != 0)
    {
        sum = (sum + help % 10) * 10;

        help = help / 10;
    }
    sum = sum / 10;


    if (sum == num)
        return true;
    else return false;
}

bool Number::prime()// function to test if the number is prime
{
    int num = switch_arr2intger();
    int i, count = 0;
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
            count++;

    }
    if (count == 2)
        return true;

    else
        return false;
}

bool Number::isEqual(const Number& other) {// function to test if the data of the local object equal to the data in other opjects

    return  this->Number_of_digits == other.get_Number_of_digits() && this->symbol == other.get_symbol() && this->switch_arr2intger() == other.switch_arr2intger();
}

bool Number::isDivided(const Number& other) {

    return this->switch_arr2intger() % other.switch_arr2intger() == 0;
}

Number Number::Add(const Number& other) {// function to add the number in the local object with a number in other opjects
    int num1, num2, * num, num3, num_of_digits = 0, help;
    bool symbol;
    if (this->symbol == true) {
        num1 = switch_arr2intger();
    }
    else num1 = switch_arr2intger() * -1;

    if (other.get_symbol() == true) {
        num2 = other.switch_arr2intger();
    }
    else num2 = other.switch_arr2intger() * -1;

    num3 = num1 + num2;
    if (num3 == 0)
        return  Number();

    help = num3;
    for (; help != 0; help /= 10, num_of_digits++);

    if (num3 < 0)
        symbol = false;
    else symbol = true;

    num = new int[num_of_digits];
    for (int i = num_of_digits - 1; 0 <= i; i--) {
        num[i] = num3 % 10;

        num3 /= 10;

    }

    return  Number(num, num_of_digits, symbol);

}


Number Number::sub(const Number& other) {// function to substract the number in the local object from a number in other opjects
    int num1, num2, * num, num3, num_of_digits = 0, help;
    bool symbol;
    if (this->symbol == true) {
        num1 = switch_arr2intger();
    }
    else num1 = switch_arr2intger() * -1;

    if (other.get_symbol() == true) {
        num2 = other.switch_arr2intger();
    }
    else num2 = other.switch_arr2intger() * -1;

    num3 = num1 - num2;
    if (num3 == 0)
        return Number();

    help = num3;
    for (; help != 0; help /= 10, num_of_digits++);

    if (num3 < 0)
        symbol = false;
    else symbol = true;

    num = new int[num_of_digits];
    for (int i = num_of_digits - 1; 0 <= i; i--) {
        num[i] = num3 % 10;

        num3 /= 10;

    }

    return  Number(num, num_of_digits, symbol);

}
