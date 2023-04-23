#pragma once
#include <string>

/**
 * @brief Klasa abstrakcyjna Dzielo, po ktorej dziedziczna inne klasy
*/
class Dzielo {
public:	
	/**
	 * @brief Zmienna statyczna nextID odpowiadajaca za przypisanie unikalnego ID kazdemu nowemu dzielu
	*/
	static int nextID;
	int ID;
	std::string imie;
	std::string nazwisko;
	std::string tytul;
	bool wypozyczona;
	//konstruktor domyslny klasy 
	
	/**
	 * @brief Konstruktor klasy Dzielo
	 * @param imie Imie autora
	 * @param nazwisko Nazwisko autora
	 * @param tytul Tytul dziela
	*/
	Dzielo(std::string imie, std::string nazwisko, std::string tytul);
	/**
	 * @brief Konstruktor domyslny klasy dzielo
	*/
	Dzielo();
	/**
	 * @brief Metoda getID
	 * @return zwraca ID danego dziela, uzywana podczas operacji usuwania i wypozyczania/zwracania
	*/
	int getID() const;
	/**
	 * @brief Funkcja wirtualna sluzaca do wypozyczania dziel
	 * @return Zwraca false jesli dzielo jest wypozyczone, zmienia wartosc pola wypozyczona
	*/
	virtual bool wypozycz() =0;
	/**
	 * @brief Funkcja wirtualna sluzaca do zwracania dziel
	 * @return Zwraca false jesli dzielo jest dostepne, zmienia wartosc pola wypozyczona
	*/
	virtual bool zwroc() =0;

};