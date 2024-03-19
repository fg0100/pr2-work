#include <iostream>
#include <ctime>
#include <string>/*
#include <>
#include <>
*/
using namespace std;
//makrók
#define PI 3.14145
#define osszead(X, Y) (X) + (Y)
#define szorzas(X, Y) (X) * (Y)
#define osztas(X, Y) (X) % (Y)


int a = 5;

//fuggveny
int fv(int b)
{
	cout << b << endl;
	cout << a << endl;
	char x = 'c';
	//blokkon belul lokális váltoozókat lehet létre hozni
	{
		double b = 3.5;
		cout << b << endl;
		cout << x << endl;
	
	}
	cout << x << endl;	
	return a + 1;
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//int a = 15;
	cout << fv(a);
	fstream be("szoveg.txt");

	cout << "makro: " << endl;
	cout << osszead(3, 4) << endl;
	cout << szorzas(8, 7) << endl;
	cout << osztas(8, 12) << endl;
	cout << szorzas(PI, 5 * 5) << endl;

	cout << endl << endl << "time:" << endl;
	clock_t kezd, veg;
	kezd = clock();
	int k;
	//for (int i = 0; i < 2 * pow(10, 9); i++)
	for (int i = 0; i < 200; i++)
	{
		//k = osszead(1, 1);
		//k = 1 + 1;
		k = add(1, 1);
	}
	veg = clock();
	cout << (float)(veg - kezd) << endl; //????????

	cout << endl << "Beolvasas: " << endl;
	char szoceg[80], bet;
	ifstream be;
	be.open("szoveg.txt");
	if (be.fail()==1)
	{
		cout << "Hiba: a fajl nem olvashato!";
		system("pause");
		exit();
	}
	while (!be.eof())
	{
		be.get(bet);
		text.
	}
	return 0;

}