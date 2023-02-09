#include <iostream>
using namespace std;



template <class T>
class Set {
public:
	int size;
	T* a;
public:
	Set();
	Set(T*,int);
	Set(Set&);
	~Set();

	Set<T>& operator =(const Set&);
	Set<T>& operator +=(const T);
	Set<T>& operator -=(const T);
	bool operator ==(const Set&)const;
	bool operator >(const Set&)const;
	Set<T>& operator +(const Set&);
	Set<T>& operator -(const Set&);
	void getType() const;
	template <class K>
	friend ostream& operator<<(ostream&, const Set<K>&);
};

/////////////////////////////////////////////////////////////////////////////////////
//Default constructor
template <class T>
Set<T> ::Set() {
	size = 0;
	a = new T[size];
}

/////////////////////////////////////////////////////////////////////////////////////
//constructor that update the class values and the type of the class
template <class T>
Set<T> ::Set(T*a, int size) {
	T *other;
	other = new T[size];
	int size2 = 0;
	bool flag ;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2; j++) {
			if (a[i] == other[j])
				flag = true;
			else
				flag = false;
		}


		if (flag == false) {
			other[size2] = a[i];
			size2++;
		}
	}

	this->size = size2;
	this->a = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->a[i] = other[i];
	}
}

/////////////////////////////////////////////////////////////////////////////////////
//Copy constuctor
template <class T>
Set<T> ::Set(Set&obj) {

	size = obj.size;

	a = new T[size];

	for (int i = 0; i < size; i++) 
		a[i] = obj.a[i];
	
}

/////////////////////////////////////////////////////////////////////////////////////
//Destuctor
template <class T>
Set<T> ::~Set() {
	delete[]a;
}

/////////////////////////////////////////////////////////////////////////////////////
// equal operator
template <class T>
Set<T>& Set<T> :: operator =(const Set&obj) {
	size = obj.size;
	this->a = new T[obj.size];
	for (int i = 0; i < size; i++) {
		this->a[i] = obj.a[i];
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////
// test if both sides are equal 
template <class T>
bool Set<T> ::operator ==(const Set&obj)const {

	int count = 0;

	if (size != obj.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (obj.a[i] == a[j]) {
				count++;
			}
		}
		if (count != 1) {
			return false;
		}
		count = 0;
	}
	return true;

}

/////////////////////////////////////////////////////////////////////////////////////
// add/equal Operator to add new index to the array
template <class T>
Set<T>& Set<T>:: operator +=(const T index) {

	for(int i = 0; i < size; i++) {
		if (a[i] == index) {
			return *this;
		}
	}

	Set obj;
	obj = *this;
	size += 1;

	a = new T[size];
	for (int i = 0; i < size-1; i++) {
		a[i] = obj.a[i];
	}
	a[size - 1] = index;
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////
//Operator add
template <class T>
Set<T>& Set<T>:: operator +(const Set&other) {

	Set temp = *this;
	T* Arr;
	Arr = new T[size];
	int  idx1, idx2, idx3;
	for (idx1 = 0, idx2 = 0, idx3 = 0; idx1 < temp.size&& idx2 < other.size;) {
		if (temp.a[idx1] < other.a[idx2]) {
			Arr[idx3] = temp.a[idx1];
			idx1++;
			idx3++;
		}
		else if (temp.a[idx1] > other.a[idx2]) {
			Arr[idx3] = other.a[idx2];
			idx2++;
			idx3++;
		}
		else {
			Arr[idx3] = temp.a[idx1];
			idx1++;
			idx2++;
			idx3++;
		}
	}

	if (idx1 < temp.size) {
		for (; idx1 < temp.size; ++idx1) {
			Arr[k] = temp.a[idx1];
			k++;
		}
	}
	else if (idx2 < other.size) {
		for (; idx2 < other.size; ++idx2) {
			Arr[idx3] = other.a[idx2];
			idx3++;
		}
	}

	Set<T> b(Arr, idx3);
	size = b.size;
	a = new T[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = b.a[i];
	}

	return *this;
}


/////////////////////////////////////////////////////////////////////////////////////
//minus/equal Operator 
template <class T>
Set<T>& Set<T>:: operator -=(const T index) {
	bool flag ;

	for (int i = 0; i < size; i++) {
		if (a[i] == index) 
			flag = true;
		
		else 
			flag = false;

	}
	try {
		if (flag == false) {
			throw exception();
		}
	}

	catch (exception e) {
		cout << "unkown element!\n";
		return *this;
	}
	

	Set help;
	help = *this;
	size -= 1;
	a = new T[size];

	int l = 0;
	for (int i = 0; i < size + 1; i++) {
		if (help.a[i] != index) {
			a[l] = help.a[i];
			l++;

		}
	}

	return *this;
}


/////////////////////////////////////////////////////////////////////////////////////
// minus Operator 
template <class T>
Set<T>& Set<T>:: operator -(const Set&other) {

    int k = 0 ,pSize ;
	pSize = size + other.size;
	bool flag;
	Set sorted;
	sorted.a = new T[pSize];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < other.size; j++) {
			if (a[i] == other.a[j]) {
				flag = true;
			}
			else
				flag = false;
		}
		if (flag == false) {
			sorted.a[k] = a[i];
			k++;
		}
	}
	size = k;
	a = new T[size];

	for (int i = 0; i < size; i++) {
		a[i] = sorted.a[i];
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////
//Operator > 
template <class T>
bool Set<T> ::operator >(const Set&obj)const {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < obj.size; j++) {
			if (a[i] == obj.a[j]) {
				count++;
			}
		}
		if (count != 1) {
			return false;
		}
		count = 0;
	}

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////
//GetType() function.
template <class T>
void Set<T>::getType()const {
	cout << "the type array is: " << typeid(a).name() << endl;
}


/////////////////////////////////////////////////////////////////////////////////////
//cout Operator 
template <class K>
ostream& operator<<(ostream& out, const Set<K>& obj) {

	out << "The set size is: " << obj.size<<endl;
	obj.getType();
	int i;
	for ( i = 0; i <obj.size; i++) 
		out <<obj.a[i]<<" ";
	
	return out;
}

