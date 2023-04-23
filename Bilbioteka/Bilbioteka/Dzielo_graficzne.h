#pragma once
#include "Dzielo.h"

/**
 * @brief Klasa Dzielo_graficzne dziedziczaca po klasie Dzielo, implementuje dwa dodatkowe pola typu float; szerokosc i wysokosc.
*/
class Dzielo_graficzne : public Dzielo {
public:
	float szerokosc;
	float wysokosc;
	/**
	 * @brief Konstruktor klasy Dzielo_graficzne
	 * @param imie Imie autora
	 * @param nazwisko Nazwisko autora
	 * @param tytul Tytul dziela
	 * @param szerokosc Szerokosc dziela
	 * @param wysokosc Wysokosc dziela
	*/
	Dzielo_graficzne(std::string imie, std::string nazwisko, std::string tytul, float szerokosc, float wysokosc);
	/**
	 * @brief Konstruktor domyslny klasy Dzielo_graficzne
	*/
	Dzielo_graficzne();
	/**
	 * @brief Metoda zwracajaca ID danego dziela, wykorzystywana w porownaniu z ID szukanego dziela
	 * @return ID dziela
	*/
	int getID() const;
	/**
	 * @brief Funkcja wirtualna sluzaca do zwracania dziel
	 * @return Zwraca false jesli dzielo jest dostepne, zmienia wartosc pola wypozyczona
	*/
	virtual bool zwroc() override;
	/**
	 * @brief Funkcja wirtualna sluzaca do wypozyczania dziel
	 * @return Zwraca false jesli dzielo jest wypozyczone, zmienia wartosc pola wypozyczona
	*/
	virtual bool wypozycz() override;


};