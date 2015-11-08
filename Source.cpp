#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void wzajemnyindekszgodnosci(string lancuch1, string lancuch2, string lancuch3, string lancuch4, string lancuch5){
	double mianownik, licznik[26][5], obliczenia_licznika = 0;
	int liczbagrup;
	mianownik = lancuch1.size()*lancuch2.size();

	char literka = 'a';
	liczbagrup = 1;
	for (int i = 0; i <= 25 && literka <= 'z'; i++, literka++)
		licznik[i][0] = count(lancuch1.begin(), lancuch1.end(), literka);

	literka = 'a';
	for (int i = 0; i <= 25 && literka <= 'z'; i++, literka++)
		licznik[i][1] = count(lancuch2.begin(), lancuch2.end(), literka);

	if (!(lancuch3.empty())){
		mianownik = lancuch1.size()*lancuch3.size();
		liczbagrup = 2;
		literka = 'a';
		for (int i = 0; i <= 25 && literka <= 'z'; i++, literka++)
			licznik[i][2] = count(lancuch3.begin(), lancuch3.end(), literka);
	}
	cout << endl;

	if (!(lancuch4.empty())){
		mianownik = lancuch1.size()*lancuch4.size();
		liczbagrup = 3;
		literka = 'a';
		for (int i = 0; i <= 25 && literka <= 'z'; i++, literka++)
			licznik[i][3] = count(lancuch4.begin(), lancuch4.end(), literka);
	}
	cout << endl;

	if (!(lancuch5.empty())){
		mianownik = lancuch1.size()*lancuch5.size();
		liczbagrup = 4;
		literka = 'a';
		for (int i = 0; i <= 25 && literka <= 'z'; i++, literka++)
			licznik[i][4] = count(lancuch5.begin(), lancuch5.end(), literka);
	}



	for (int obrot = 0; obrot < liczbagrup; obrot++){
		for (int i = 0; i <= 25; i++){
			obliczenia_licznika = 0;
			for (int j = 0; j <= 25; j++){
				obliczenia_licznika += licznik[j][0] * licznik[(j + i) % 25][obrot + 1];
			}
			cout << "k" << i << " = " << obliczenia_licznika / mianownik << endl;
		}
		cout << "\n";
	}
}

double indekszgodnosci(string grupa){
	double mianownik, licznik = 0;
	mianownik = grupa.length()*(grupa.length()-1);

	for (char i = 'a'; i <= 'z'; i++){
		double z;
			z = count(grupa.begin(), grupa.end(), i);
			licznik += (z*(z - 1));
	}
	return (licznik/mianownik);
}

void dwuznakowyklucz(string lancuch){
	string rzad1, rzad2, rzad3 = "", rzad4 = "", rzad5 = "";
	char pytanie;
	int i = 0;
	while (i < lancuch.length()){
		if (i%2 == 0)
			rzad1.push_back(lancuch[i]);
		if (i%2 == 1)
			rzad2.push_back(lancuch[i]);
		i++;
	}
	cout << "Ic_1 " << indekszgodnosci(rzad1) << endl;
	cout << "Ic_2 " << indekszgodnosci(rzad2) << endl;

	cout << "Obliczycz wzajemny indeks zgodnosci? (y/n)";
	cin >> pytanie;
	if (pytanie == 'y')
		wzajemnyindekszgodnosci(rzad1, rzad2, rzad3, rzad4, rzad5);
	else
		cout << "Nie? To nie!!! Foch!!\n";
}

void trojznakowyklucz(string lancuch){
	string rzad1, rzad2, rzad3, rzad4 = "", rzad5 = "";
	char pytanie;
	for (int i = 0; i < lancuch.length(); i++){
		if (i%3 == 0)
			rzad1.push_back(lancuch[i]);
		if (i % 3 == 1)
			rzad2.push_back(lancuch[i]);
		if (i % 3 == 2)
			rzad3.push_back(lancuch[i]);
	}
	cout << "Ic_1 " << indekszgodnosci(rzad1) << endl;
	cout << "Ic_2 " << indekszgodnosci(rzad2) << endl;
	cout << "Ic_3 " << indekszgodnosci(rzad3) << endl;

	cout << "Obliczycz wzajemny indeks zgodnosci? (y/n)";
	cin >> pytanie;
	if (pytanie == 'y')
		wzajemnyindekszgodnosci(rzad1, rzad2, rzad3, rzad4, rzad5);
	else
		cout << "Nie? To nie!!! Foch!!\n";
}

void czteroznakowyklucz(string lancuch){
	string rzad1, rzad2, rzad3, rzad4, rzad5 = "";
	char pytanie;
	for (int i = 0; i < lancuch.length(); i++){
		if (i % 4 == 0)
			rzad1.push_back(lancuch[i]);
		if (i % 4 == 1)
			rzad2.push_back(lancuch[i]);
		if (i % 4 == 2)
			rzad3.push_back(lancuch[i]);
		if (i % 4 == 3)
			rzad4.push_back(lancuch[i]);
	}
	cout << "Ic_1 " << indekszgodnosci(rzad1) << endl;
	cout << "Ic_2 " << indekszgodnosci(rzad2) << endl;
	cout << "Ic_3 " << indekszgodnosci(rzad3) << endl;
	cout << "Ic_4 " << indekszgodnosci(rzad4) << endl;

	cout << "Obliczycz wzajemny indeks zgodnosci? (y/n)";
	cin >> pytanie;
	if (pytanie == 'y')
		wzajemnyindekszgodnosci(rzad1, rzad2, rzad3, rzad4, rzad5);
	else
		cout << "Nie? To nie!!! Foch!!\n";
}

void piecioznakowyklucz(string lancuch){
	string rzad1, rzad2, rzad3, rzad4, rzad5;
	char pytanie;
	for (int i = 0; i < lancuch.length(); i++){
		if (i % 5 == 0)
			rzad1.push_back(lancuch[i]);
		if (i % 5 == 1)
			rzad2.push_back(lancuch[i]);
		if (i % 5 == 2)
			rzad3.push_back(lancuch[i]);
		if (i % 5 == 3)
			rzad4.push_back(lancuch[i]);
		if (i % 5 == 4)
			rzad5.push_back(lancuch[i]);
	}
	cout << "Ic_1 " << indekszgodnosci(rzad1) << endl;
	cout << "Ic_2 " << indekszgodnosci(rzad2) << endl;
	cout << "Ic_3 " << indekszgodnosci(rzad3) << endl;
	cout << "Ic_4 " << indekszgodnosci(rzad4) << endl;
	cout << "Ic_5 " << indekszgodnosci(rzad5) << endl;

	cout << "Obliczycz wzajemny indeks zgodnosci? (y/n)";
	cin >> pytanie;
	if (pytanie == 'y')
		wzajemnyindekszgodnosci(rzad1, rzad2, rzad3, rzad4, rzad5);
	else
		cout << "Nie? To nie!!! Foch!!\n";
}


int main(void){
	string line;
	ifstream myfile("szyfr.txt");
	if (myfile.is_open()){
		while (getline(myfile, line)){
			//cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	
	cout << "Ideks zgodnosci dla j. ang wynosi okolo 0,065\n\n";

	int dlugoscklucza;
	cout << "Podaj przypuszczalna dlugosc klucza:\n\n";
	cin >> dlugoscklucza;

	switch (dlugoscklucza)
	{
	case 2:
		dwuznakowyklucz(line);
		break;
	case 3:
		trojznakowyklucz(line);
		break;
	case 4:
		czteroznakowyklucz(line);
		break;
	case 5:
		piecioznakowyklucz(line);
		break;
	}

	system("pause");
	return 0;
}