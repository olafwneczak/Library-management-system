#include "Dzielo_graficzne.h"

Dzielo_graficzne::Dzielo_graficzne(std::string imie, std::string nazwisko, std::string tytul, float szerokosc, float wysokosc) 
	:Dzielo(imie, nazwisko, tytul)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
}

Dzielo_graficzne::Dzielo_graficzne() : Dzielo(), szerokosc(0), wysokosc (0){}

int Dzielo_graficzne::getID() const {
	return ID;
}

bool Dzielo_graficzne::wypozycz() {

	if (!wypozyczona) {
		wypozyczona = true;
		return true;
	}
	return false;

}
bool Dzielo_graficzne::zwroc() {
	if (wypozyczona) {
		wypozyczona = false;
		return true;
	}
	return false;
}