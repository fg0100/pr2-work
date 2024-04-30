#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
//include<>

using namespace std;

struct Series {
	string name = "";
	int season = 0;
	int episodes = 0;
	int length = 0;
	int price = 0;
};

class Filmek {
	int db;
	Series* tmb; //dinamikus tömb

public:
	//konstruktor
	Filmek(string file_name);
	
	int Getadatdb();
	int OsszesReszSzama();
	Series Legdragabb();
	void Kiír();
	//destruktor
	~Filmek();
};



//////////////main//////////
int main()
{
	setlocale(LC_ALL, "HUN");

	string file_name = "Filmsorozatok.txt";
	Filmek F(file_name);
	
	F.Kiír();

	cout << "Sorozatok szama: " << F.Getadatdb() << endl;

	cout << "Reszek szama: " << F.OsszesReszSzama() << endl;

	Series most_expensive = F.Legdragabb();
	cout << "Legdragabb film: " << most_expensive.name << ", " << most_expensive.price << endl;

}




//////////////////konstruktor////////////
Filmek::Filmek(string file_name) {
	db = 0;
	string row;
	ifstream be(file_name);
	if (be.fail())
	{
		cout << "Hiba a fajl megnyiasa soran!" << endl;
		return;
	}
	while (!be.eof()){
		getline(be, row); //be valtozoba beolvassuk a sort 
		db++;
	}
	be.seekg(0, ios::beg);//a meglevo filenak visszalepteti az inexet az elejere (nem kell ilyenkor bezarni)
	//be.close();
	cout << "A fajlban " << db << " sorozat talalhato!" << endl;

	int i = 0;
	tmb = new Series[db];
	while (!be.eof())
	{
		getline(be, tmb[i].name, ';');

		getline(be, row, ';');
		tmb[i].season = stoi(row); //string to int == stoi()
		getline(be, row, ';');
		tmb[i].episodes = stoi(row);
		getline(be, row, ';');
		tmb[i].length = stoi(row);
		getline(be, row, ';');
		tmb[i].price = stoi(row);

		i++;
	}
	be.close();
}


////////////// destruktor ///////////

Filmek::~Filmek()
{
	delete[] tmb;
}

int Filmek::Getadatdb() 
{
	return db;//mert a db valtozoban van eltarolva a darabszam
}

int Filmek::OsszesReszSzama()
{
	int all_films = 0;
	for (int i = 0; i < db; i++)
	{
		all_films += tmb[i].season * tmb[i].episodes;
	}

	return all_films;
}

Series Filmek::Legdragabb()
{
	int most_expensive_index = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[most_expensive_index].price < tmb[i].price)
		{
			most_expensive_index = i;
		}
	}
	return tmb[most_expensive_index];
}


void Filmek::Kiír() {
	cout << setw(15) << "Sorozat" << setw(8) << "Évad" << setw(10) << "Epizódok" << setw(8) << "Hossz" << setw(8) << "Ár" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(15) << tmb[i].name << setw(8) << tmb[i].season << setw(10) << tmb[i].episodes << setw(8) << tmb[i].length << setw(8) << tmb[i].price << endl;

	}

}



