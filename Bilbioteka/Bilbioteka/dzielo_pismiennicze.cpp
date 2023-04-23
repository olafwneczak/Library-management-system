#include "Dzielo_pismiennicze.h"
#include <iostream>
//konstruktor

Dzielo_pismiennicze::Dzielo_pismiennicze(std::string imie, std::string nazwisko, std::string tytul, unsigned long long int ISBN) : Dzielo(imie, nazwisko, tytul) 
{
	this->ISBN = ISBN;
}

//konstruktor domyslny
Dzielo_pismiennicze::Dzielo_pismiennicze() : Dzielo(), ISBN(0){}


bool Dzielo_pismiennicze::sprawdz_sume_kontrolna(unsigned long long int &ISBN) {
	std::string ISBN_str = std::to_string(ISBN);	//konwersja na typ string w celu iteracji po elementach
	int suma = 0;
	int to_check =0;	//deklaracja zmiennej, ktora przyjmuje wartosc ostatniej cyfry numeru ISBN
	for (int i = 0; i < ISBN_str.size(); ++i) {
		if (i == ISBN_str.size() - 1) { //warunek sprawdzajacy czy znak jest ostatni 
			 to_check= ISBN_str[i] - '0';	//konwersja znaku na liczbe, przypisanie to_check wartosci ostatniego znaku
		}
		int cyfra = ISBN_str[i] - '0';	//konwersja znaku na liczbe 
		suma += cyfra * (i % 2 == 0 ? 1 : 3); //mnozenie *1 lub *3, warunek na odwrot, poniewaz idziemy od [0]
	}
	int checksum = (suma - to_check) % 10;	//reszta z dzielenia 
	int correct_sum = 10 - checksum; //obliczanie wartosci sumy kontrolnej

	if (correct_sum==to_check) {//warunek sprawdzajacy czy suma kontrolna zgadza sie z podana przez uzytkownika 
		return true;
	}
	else 
	{
		return false;
	}
}

int Dzielo_pismiennicze::getID() const {
	return this->ID;
}
 
bool Dzielo_pismiennicze::wypozycz() {
	if (!wypozyczona) {
		wypozyczona = true;
		return true;
	}
	return false;
}
bool Dzielo_pismiennicze::zwroc() {
	if (wypozyczona) {
		wypozyczona = false;
		return true;
	}
	return false;
}