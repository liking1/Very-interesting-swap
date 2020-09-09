#include<iostream>
#include<string>
using namespace std;

int countCars = 0;
string* brandCars = new string[countCars];
int* yearsCars = new int[countCars];

struct Details {
	string klirens;
	string V;
	string W;
	string longg;
	string diametr;
	string color;
	string korobka;
};

int countDetails = 0;
Details* ListDetails = new Details[countDetails];

void addDetailsToSystem(Details newDetails) {


}

void addCarToSystem(string brand, int year) {
	string* tempBrads = new string[countCars + 1];
	int* tempYears = new int[countCars + 1];

	for (int i = 0; i < countCars; i++)
	{
		tempBrads[i] = brandCars[i];
		tempYears[i] = yearsCars[i];
	}

	tempBrads[countCars] = brand;
	tempYears[countCars] = year;

	countCars++;

	brandCars = new string[countCars];
	yearsCars = new int[countCars];

	for (int i = 0; i < countCars; i++)
	{
		brandCars[i] = tempBrads[i];
		yearsCars[i] = tempYears[i];
	}
	delete[]tempBrads;
	delete[]tempYears;
}

void showAllCars() {
	cout << endl;
	for (int i = 0; i < countCars; i++)
	{
		cout << i + 1 << ". " << yearsCars[i] << " - " << brandCars[i] << endl;
	}
	cout << endl;
}

void searchByFilter(string* dataSearch) {

	cout << endl;
	for (int i = 0; i < countCars; i++)
	{
		string temp = *dataSearch;

		//atoi - ??????? ??? ??????? ????? ????????
		int year = atoi(temp.c_str());
		if (brandCars[i].find(*dataSearch) != string::npos || yearsCars[i] == year)
		{
			cout << yearsCars[i] << " - " << brandCars[i] << endl;
		}
	}
	cout << endl;
}

void removeCarFromSystem(int indexCar) {
	string* tempBrads = new string[countCars - 1];
	int* tempYears = new int[countCars - 1];

	int freeIndex = 0;

	for (int i = 0; i < countCars; i++)
	{
		if (i != indexCar) {
			tempBrads[freeIndex] = brandCars[i];
			tempYears[freeIndex] = yearsCars[i];
			freeIndex++;
		}
	}
	countCars--;
	brandCars = new string[countCars];
	yearsCars = new int[countCars];

	for (int i = 0; i < countCars; i++)
	{
		brandCars[i] = tempBrads[i];
		yearsCars[i] = tempYears[i];
	}
	delete[]tempBrads;
	delete[]tempYears;
}

int main() {

	int action = 0;
	do
	{
		cout << "1. Show all cars" << endl;
		cout << "2. Add new car" << endl;
		cout << "3. Search car by filter" << endl;
		cout << "4. Remove car" << endl;
		cout << "5. Exit" << endl;
		cout << endl;
		cout << "Select action from list ->_";
		cin >> action;


		switch (action)
		{
		case 1: {
			showAllCars();
		}break;

		case 2: {
			string brandCar = "";
			int yearCar = 0;
			cout << "ADD NEW CAR:" << endl;
			cout << "\tEnter brand and model for new car: ";
			cin.ignore();
			getline(cin, brandCar);
			cout << "\tEnter year for new car: ";
			cin >> yearCar;
			addCarToSystem(brandCar, yearCar);
		}break;

		case 3: {
			string dataSearch = "";
			cout << "Search: ";


			cin.ignore();
			getline(cin, dataSearch);


			searchByFilter(&dataSearch);

		}break;

		case 4: {

			showAllCars();
			int number = 0;
			if (countCars > 0)
			{
				cout << "Select number card for remove ->_";
				cin >> number;
				if (number > 0 && number <= countCars) {
					removeCarFromSystem(number - 1);
				}
				else {
					cout << "Error: Invalid seleced number!" << endl;
				}
			}

		}break;

		case 5: {
			cout << "Goodbye!" << endl;
		}break;

		default: {
			cout << "Error: Please, select action from list!" << endl;
		}break;
		}

	} while (action != 5);


	return 0;
}