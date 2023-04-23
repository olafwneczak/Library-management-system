#pragma once
#include "Dzielo.h"

/**
 * @brief Klasa Dzielo_pismiennicze dziedziczaca po klasie Dzielo, implementuje nr ISBN oraz metode sprawdzajaca jego poprawnosc
*/
class Dzielo_pismiennicze : public Dzielo {
public:
	/**
	 * @brief pole numeru ISBN
	*/
	unsigned long long int ISBN;
	/**
	 * @brief Konstruktor klasy Dzielo_pismiennicze
	 * @param imie Imie autora
	 * @param nazwisko Nazwisko autora
	 * @param tytul Tytul dziela
	 * @param ISBN Nr ISBN
	*/
	Dzielo_pismiennicze(std::string imie, std::string nazwisko, std::string tytul, unsigned long long int ISBN);
	/**
	 * @brief Konstruktor domyslny klasy Dzielo_pismiennicze
	*/
	Dzielo_pismiennicze();
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
	/**
	* @brief Metoda sprawdzajaca popawnosc sumy kontrolnej w numerze ISBN
	* @param ISBN Nr ISBN podawany przez uzytkownika
	* @return true jesli nr jest poprawny, false jesli nie jest 
	*/
	bool sprawdz_sume_kontrolna(unsigned long long int& ISBN);

	/**
	* @brief Metoda zwracajaca ID danego dziela, wykorzystywana w porownaniu z ID szukanego dziela
	* @return ID dziela
	*/
	int getID() const;


};

