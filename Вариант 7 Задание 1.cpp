#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cctype>


using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	ifstream fin("Kond.txt");
	int n = 0, i = 0, j = 0; int choose;
	char exit[50];
	struct kond
	{
		int vesobsh; //вес сладостей
		int vesodn;//вес одной сладости
		int srok; //срок годности
		int kolorii;//Количество килокалорий
		char nazvanie[50];//Название сладости
	};
	while (exit[0] != '!')
	{
		n++;
		fin.getline(exit, 50);
	}
	n--;
	kond* arr_kond = new kond[n]; 
	fin.seekg(0, ios_base::beg);
	for (i = 0; i < n; i++)
	{
		fin >> arr_kond[i].vesobsh;
		fin >> arr_kond[i].vesodn;
		fin >> arr_kond[i].srok;
		fin >> arr_kond[i].kolorii;
		fin.getline(arr_kond[i].nazvanie, 50);
		cout << "вес имеющихся в наличии сладостей: " << arr_kond[i].vesobsh << endl;
		cout << "вес сладости: " << arr_kond[i].vesodn << endl;
		cout << "срок годности: " << arr_kond[i].srok << endl;
		cout << "название сладости: " << arr_kond[i].nazvanie << endl;
		cout << "количество килокалорий в 100 г сладости: " << arr_kond[i].kolorii << endl << endl;
	}

	cout << "Введите номер задания-"; cin >> choose;
	if (choose == 1) {
		int kolich;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				
					kolich=  arr_kond[i].vesobsh / arr_kond[i].vesodn;
					cout << "\nСладостей " << arr_kond[i].nazvanie << " на складе - " << kolich << endl;
					break;
				
			}
		}
	}
	if (choose == 2) {
		for (i = 65; i < 91; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((arr_kond[j].nazvanie[0] == i) && (arr_kond[j].kolorii * 10 < 400))
				{
					cout << "вес имеющихся в наличии сладостей: " << arr_kond[j].vesobsh << endl;
					cout << "срок годности: " << arr_kond[j].srok << endl;
					cout << "название сладости: " << arr_kond[j].nazvanie << endl;
					cout << "количество килокалорий в 100 г сладости:" << arr_kond[j].kolorii << endl << endl;
				}
			}
		}
		system("pause");
		return 0;
	}
}