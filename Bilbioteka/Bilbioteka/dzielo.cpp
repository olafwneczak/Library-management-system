#include "Dzielo.h"

//static int ktory sluzy do inkrementowania id
int Dzielo::nextID = 1;
//konstruktor domyslny 
Dzielo::Dzielo() : imie(""), nazwisko(""), tytul(""), wypozyczona(false) { ID=nextID++; }
//konstruktor
Dzielo::Dzielo(std::string imie, std::string nazwisko, std::string tytul) {
	this->ID = nextID++;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->tytul = tytul;
	wypozyczona = false;
}
int Dzielo::getID()const{
	return this->ID;
}

bool Dzielo::zwroc() {
	if (wypozyczona) {
		wypozyczona = false;
		return true;
	}
	return false;
}
bool  Dzielo::wypozycz() {

	if (!wypozyczona) {
		wypozyczona = true;
		return true;
	}
	return false;
}