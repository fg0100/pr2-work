#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int f = 10;
	int *mut;
	int &fi = f;
	mut = &f;

	cout << "f= " << f <<", fi= " << fi <<", *mut= " << *mut << endl;
	
	fi = 20;
	cout << "f= " << f <<", fi= " << fi <<", *mut= " << *mut << endl;
	
//mutatok
	cout << &f << " " << &fi << " " << mut << " " << &mut << endl;

	//vektorok
	//jeleneleg 3 elem  kesobb lehet meg hoza adni
	
	vector <int> jegyek(3);
	char bet;
	int szam;
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "Adja meg az " << (i + 1) << ". tanulo jegyet (1-5):";
		cin >> jegyek[i];

	}
	 
	cout << "akar meg jegyet felvenni? (y/n): " << endl;
	cin >> bet;
	if (bet == 'y')
	{
		do
		{
			cout << "Jegy (1-5): ";
			cin >> szam;
			//vektor vegehez hozza ad egy uj elemet
			jegyek.push_back(szam);
			cout << "Akar meg egyet? (y/n): " << endl;
			cin >> bet;
			i++;
		} while (bet ==  'y');
	}
	//.size() vektornak hany eleme van
	cout << "\nJegyek szama: " << jegyek.size() << endl;

	cout << "\nOsztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		//.at() index alapjan lekeri a vektor adott elemet
		cout << jegyek.at(i) << ", ";
	}

	//kitorli az utolso elemet a vektornak
	jegyek.pop_back();

	cout << "\n\n\nOsztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}

	jegyek.insert(jegyek.begin() + 1, 1);
	
			
	cout << "\n\n\nOsztalyzatok: " << endl;
	for (i = 0; i < jegyek.size(); i++)
	{
		cout << jegyek.at(i) << ", ";
	}
}