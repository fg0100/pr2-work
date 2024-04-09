#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct worker
{
	string nev;
	int szul_ev, ora, aktual_fiz;
};


int main()
{
	setlocale(LC_ALL, "HUN");
	string file_name = "majus.txt";
	ifstream be(file_name);
	int length = 0; //munkasok szama
	while (!be.eof())
	{
		string name;
		be >> name;
		length++;
	}
	cout << "majusban ennyi fo dolgozott: " << length << endl;

	worker* Worker = new worker[length];
	be.clear();
	be.seekg(0, ios::beg);
	int i = 0;
	for ( i = 0; i < length; i++)
	{
		be >> Worker[i].nev;
		do
		{
			cout << Worker[i].nev << " születési éve: ";
			cin >> Worker[i].szul_ev;
			if (Worker[i].szul_ev < 1957 || Worker[i].szul_ev >2004)
			{
				cout << endl << "1957 és 2004 közöti évet adjon meg" << endl;
			}
		} while (Worker[i].szul_ev < 1957 || Worker[i].szul_ev >2004);
		Worker[i].ora = rand() % 160;
	}







	be.close();
	cout << length;
	system("PAUSE");
	return 0;

}