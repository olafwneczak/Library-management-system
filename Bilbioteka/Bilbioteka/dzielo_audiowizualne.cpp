#include "Dzielo_audiowizualne.h"

//konstruktor
Dzielo_audiowizualne::Dzielo_audiowizualne(std::string imie, std::string nazwisko, std::string tytul, std::string dlugosc_nagrania)
	:Dzielo(imie, nazwisko, tytul), dlugosc_nagrania(dlugosc_nagrania) {}

//konstruktor domyslny
Dzielo_audiowizualne::Dzielo_audiowizualne() : Dzielo(), dlugosc_nagrania(""){}

int Dzielo_audiowizualne::getID() const {
	return ID;
}

//implementacja funkcji wirtualnych
bool Dzielo_audiowizualne::zwroc() {
	if (wypozyczona) {
		wypozyczona = false;
		return true;
	}
	return false;
}
bool Dzielo_audiowizualne::wypozycz() {
	if (!wypozyczona) {
		wypozyczona = true;
		return true;
	}
	return false;
}