#include "Employee.h"
#include "Set.h"


int main() {

	Set<Employee>emp1;
	Set<Employee>emp2;
	Employee group1;
	Employee group2;

	char str1[50];
	char str2[50];
	char str3[50];
	double frc;
	int R;

	float *arr1, *arr2,num;
	int size1, size2;
	

	// the first set:
	cout << "Please enter the number of elements that you want in the first set:"<<endl;
	cin >> size1;
	arr1 = new float[size1];
	cout << "Please enter "<<size1<<" elements:" << endl;
	for (int i = 0; i < size1; i++) 
		cin >> arr1[i];
	
	// the second set:
	cout << "Please enter the number of elements that you want in the second set:" << endl;
	cin >> size2;
	arr2 = new float[size2];
	cout << "Please enter " << size2 << " elements:" << endl;
	for (int i = 0; i < size2; i++) 
		cin >> arr2[i];
	
	// add values to constuctor with float type
	Set<float>arr1(arr1, size1);
	Set<float>arr2(arr2, size2);


	cout << "group1: " << endl;
	cout << arr1 << endl;
	cout << "group2: " << endl;
	cout << arr2 << endl;
	cout << "enter number to add :" << endl;
	cin >> num;
	arr1 += num;
	cout << "group1 after adding an element" << endl;
	cout << arr1 << endl;
	Set<float>arr3;
	arr3 = arr1 + arr2;
	cout << "The result of the union of group1 and group2 is:" << endl;
	cout << arr3 << endl;
	Set<float>arr4;
	arr4 = arr1 - arr2;
	cout << "The result of the intersection of group1 and group2 is:" << endl;
	cout << arr4 << endl;

	//print the detailes

	getchar();
	cout <<" enter the name of the first Employee:" << endl;
	cin.getline(str1, 50);
	cout <<"enter the family name of the first Employee : " << endl;
	cin.getline(str2, 50);
	cout <<"enter the Id of the first Employee : " << endl;
	cin.getline(str3, 50);
	cout <<"enter the first Employee's salary :" << endl;
	cin >> frc;
	cout << "enter the number of hours for the first Employee:" << endl;
	cin >> R;

	group1 = Employee(str1, str3, str2, frc,R);
	emp1 += group1;
	getchar();
	cout << "enter the name of the second Employee:" << endl;
	cin.getline(str1, 50);
	cout << "enter the family name of the second Employee : " << endl;
	cin.getline(str2, 50);
	cout << "enter the Id of the second Employee : " << endl;
	cin.getline(str3, 50);
	cout << "enter the second Employee's salary :" << endl;
	cin >> frc;
	cout << "enter the number of hours for the second Employee:" << endl;
	cin >> R;
	group2 = Employee(str1, str3, str2, frc,R);
	emp2 += group2;
	cout << emp2;
	cout << emp2;



	return 0;

}
