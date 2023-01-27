#include <iostream>
using namespace std;

struct date
{
	int day, month, year;
};
struct car
{
	int id;
	char fname[20], sname[20], make[20], model[20];
	struct date regDate, nsDate;
}carD[100];

int mem = 0;

void disp() {
	for (int i = 0; i < mem; i++) {
		cout << "\nID\t\tName\t\tSurname\t\tMake\t\tModel" << endl
			<< "\n" << carD[i].id << "\t" << carD[i].fname << "\t" << carD[i].sname
			<< "\t" << carD[i].make << "\t" << carD[i].model << "\t" << carD[i].regDate.day
			<< "/" << carD[i].regDate.month << "/" << carD[i].regDate.year << "\t" << carD[i].nsDate.year << endl;
	}
}

void Add() {
	int no;

	cout << "\nHow many Cars would you like to add: ";
	cin >> no;

	for (int i = 1; i <= no; i++) {
		cout << "\nPlease Enter the ID of car " << i << " : ";
		cin >> carD[mem].id;

		cout << "\nPlease Enter the Owner's First Name: ";
		cin >> carD[mem].fname;

		cout << "\nPlease Enter the Owner's Surname: ";
		cin >> carD[mem].sname;

		cout << "\nPlease Enter the make of the car: ";
		cin >> carD[mem].make;

		cout << "\nPlease Enter the model of the car: ";
		cin >> carD[mem].model;

		cout << "\nPlease Enter the registration date of the car (DD/MM/YYYY): ";
		cin >> carD[mem].regDate.day >> carD[mem].regDate.month >> carD[mem].regDate.year;
		cout << "\nThe entered registration date is: " << carD[mem].regDate.day << "/" << carD[mem].regDate.month << "/" << carD[mem].regDate.year << endl;

		//cout<<"\nPlease Enter the Next Service date of the Car: ";
		//	cin>>carD[mem].nsDate.day>>carD[mem].nsDate.month>>carD[mem].nsDate.year;
		carD[mem].nsDate.year = carD[mem].regDate.year + 1;
		cout << "\nThe Next Service date is: " << carD[mem].regDate.day << "/" << carD[mem].regDate.month << "/" << carD[mem].nsDate.year << endl;
		//	cout<<"\n";

		mem++;
	}

}

void List() {

	cout << "\nID\t\tName\t\tSurname\t\tMake\t\tModel" << endl;

	for (int i = 0; i < mem; i++) {
		cout << "\n" << carD[i].id << "\t" << carD[i].fname << "\t\t" << carD[i].sname << "\t\t" << carD[i].make << "\t\t" << carD[i].model << endl;
		cout << "\n";
	}
}

void Del() {
	int delID, index = -1;
	int i, j; char choice;

	cout << "\nPlease Enter the Id of the Car you want to Delete from the Directory: ";
	cin >> delID;

	for (i = 0; i < mem; i++)
	{
		if (delID == carD[i].id) {
			cout << "\nID\t\tName\t\tSurname\t\tMake\t\tModel" << endl
				<< "\n" << carD[i].id << "\t" << carD[i].fname << "\t" << carD[i].sname
				<< "\t" << carD[i].make << "\t" << carD[i].model << "\t" << carD[i].regDate.day
				<< "/" << carD[i].regDate.month << "/" << carD[i].regDate.year << "\t" << carD[i].nsDate.year << endl;
		}
		cout << "\nIs this the directory you want to delete?\n\nPress Y for Yes and N for No: ";
		cin >> choice;

		if (choice == 'y' || choice == 'Y') {
			for (int j = i; j < (mem - 1); j++)
				carD[j] = carD[j + 1];
			index++;
			mem--;
		}
		else if (choice == 'n' || choice == 'N')
			Del();
		else
			cout << "\nWrong input";
	}
	if (index == 0)
		cout << "\nID not found in the Directory" << endl;
	else
		cout << "\nCar Deleted Successfully" << endl;

}
void Search() {

	int i, searchID, searchYear;
	char option;

	cout << "\nHow would you like to search\n(A)By car ID\n(B)By Registration Year\n\nPlease Enter option: ";
	cin >> option;

	if (option == 'a' || option == 'A') {
		cout << "\nPlease Enter the ID of the car you want to search: ";
		cin >> searchID;
	}
	if (option == 'b' || option == 'B') {
		cout << "\nPlease Enter the registration year of the car you want to search: ";
		cin >> searchYear;
	}
	for (i = 0; i <= mem; i++) {
		if (carD[i].id == searchID || carD[i].regDate.year == searchYear) {
			cout << "\nID\t\tName\t\tSurname\t\tMake\t\tModel" << endl
				<< "\n" << carD[i].id << "\t" << carD[i].fname << "\t" << carD[i].sname
				<< "\t" << carD[i].make << "\t" << carD[i].model << "\t" << carD[i].regDate.day
				<< "/" << carD[i].regDate.month << "/" << carD[i].regDate.year << "\t" << carD[i].nsDate.year << endl;
		}
	}
}


void Update() {
	int searchID; char option;
	//int foundin=-1;
	cout << "\nPlease Enter the ID of the car you want to update: ";
	cin >> searchID;
	int i;
	for (i = 0; i < mem; i++) {
		if (carD[i].id == searchID) {
			cout << "\nID\t\tName\t\tSurname\t\tMake\t\tModel" << endl
				<< "\n" << carD[i].id << "\t" << carD[i].fname << "\t" << carD[i].sname
				<< "\t" << carD[i].make << "\t" << carD[i].model << "\t" << carD[i].regDate.day
				<< "/" << carD[i].regDate.month << "/" << carD[i].regDate.year << "\t" << carD[i].nsDate.year << endl;
		}
		if (i < mem) {
			cout << "\nIs this the car you wish to update?\nType Y or N: ";
			cin >> option;

			if (option == 'y' || option == 'Y') {
				cout << "\nPlease Enter new car ID: ";
				cin >> carD[i].id;

				cout << "\nPlease Enter the Owner's First Name: ";
				cin >> carD[i].fname;

				cout << "\nPlease Enter the Owner's Surname: ";
				cin >> carD[i].sname;

				cout << "\nPlease Enter the make of the car: ";
				cin >> carD[i].make;

				cout << "\nPlease Enter the model of the car: ";
				cin >> carD[i].model;

				cout << "\nPlease Enter the registration date of the car (DD/MM/YYYY): ";
				cin >> carD[i].regDate.day >> carD[i].regDate.month >> carD[i].regDate.year;
				cout << "\nThe entered registration date is: " << carD[i].regDate.day << "/" << carD[i].regDate.month << "/" << carD[i].regDate.year << endl;

				//cout<<"\nPlease Enter the Next Service date of the Car: ";
				//	cin>>carD[mem].nsDate.day>>carD[mem].nsDate.month>>carD[mem].nsDate.year;
				carD[i].nsDate.year = carD[i].regDate.year + 1;
				cout << "\nThe Next Service date is: " << carD[i].regDate.day << "/" << carD[i].regDate.month << "/" << carD[i].nsDate.year << endl;
				//	cout<<"\n";
				break;
			}
			else if (option == 'n' || option == 'N')
				Update();
			else
				cout << "WRONG INPUT";
		}
	}

}

void Sort()
{
	int temp; // a temporary variable to hold the swapped element

	for (int i = 1; i < mem; i++)
	{
		for (int j = 0; j < mem - i; j++)
		{
			if (carD[j].id > carD[j + 1].id) //This condition checks if the next element is smaller or bigger than the next, depending on the order of sort i.e asce or desc
			{
				//	swap(carD[j].id, carD[j+1].id);
				temp = carD[j + 1].id; //The swapping takes place here
				carD[j + 1].id = carD[j].id;
				carD[j].id = temp;

				/*	for(int i=0; i<=mem; i++){
			cout<<carD[i].id<<"\t"<<carD[i].fname<<"\t"<<carD[i].sname<<"\t"<<carD[i].make<<"\t"
				<<carD[i].model<<"\t"<<carD[i].regDate.day<<"/"<<carD[i].regDate.month<<"/"<<carD[i].regDate.year<<"\t"<<carD[i].nsDate.year;
						*/
			}
		}
	}
	cout << "\nDirectory is Sorted Successfully";
}

int main() {

	int selection;

	do
	{
		cout << "\n\n***************DIRECTORY MENU***************\n"
			<< "\n1- Add a new car to directory"
			<< "\n2- Delete a car from the directory"
			<< "\n3- List available cars in the directory"
			<< "\n4- Search a car: "
			<< "\n\tA - Search according to car id"
			<< "\n\tB - Search according to registration year"
			<< "\n5- Update car information"
			<< "\n6- Sort according to car id"
			<< "\n7- Quit"
			<< "\n\nPlease select a menu option: ";

		cin >> selection;

		switch (selection)
		{
		case 1:
			Add();
			cout << "\nCar(s) added successfully";
			break;

		case 2:
			Del();
			break;

		case 3:
			List();
			break;

		case 4:
			Search();
			break;

		case 5:
			Update();
			break;
		case 6:
			Sort();
			break;
		case 7:
			cout << "\nHAVE A NICE DAY!!";
			break;
		default:
			cout << "\nINVALID SELECTION";
		}
	} while (selection != 7);

	return 0;

}
