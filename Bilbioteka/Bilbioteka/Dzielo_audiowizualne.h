#pragma once
#include "Dzielo.h"
/**
 * @brief Klasa Dzielo_audiowizualne, dziedziczaca po klasie Dzielo, implementuje pole dlugosc_nagrania
*/
class Dzielo_audiowizualne : public Dzielo {
public:
	/**
	 * @brief Zmienna typu string odpowiadajaca za dlugosc nagrania
	*/
	std::string dlugosc_nagrania;
	/**
	 * @brief Konstruktor domyslny klasy Dzielo_audiowizualne
	*/
	Dzielo_audiowizualne();
	/**
	 * @brief Konstruktor klasy Dzielo_audiowizualne
	 * @param imie Imie autora
	 * @param naziwsko Nazwisko autora
	 * @param tytul Tytul dziela
	 * @param dlugosc_nagrania Dlugosc nagrania
	*/
	Dzielo_audiowizualne(std::string imie, std::string naziwsko, std::string tytul, std::string dlugosc_nagrania);
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
