#pragma once
#include <list>
#include "Dzielo.h"
#include "Dzielo_audiowizualne.h"
#include "Dzielo_graficzne.h"
#include "Dzielo_pismiennicze.h"


/**
 * @brief Szablon uzywany do usuwania dziel
 * @tparam T Rodzaj listy
 * @param list Nazwa listy
 * @param id_match Nr ID, ktory jest wyszukiwany (podany przez uzytkownika)
*/
template <typename T>
void usun(std::list<T>& list, int id_match);
/**
 * @brief Szablon uzywany do zwracania wypozyczania dziel
 * @tparam T Rodzaj listy
 * @param list Nazwa listy
 * @param id_match Nr ID, ktory jest wyszukiwany (podany przez uzytkownika)
*/
template <typename T>
void wypozycz_d(std::list<T>& list, int id_match);
/**
 * @brief Szablon uzywany do zwracania dziel
 * @tparam T Rodzaj listy
 * @param list Nazwa listy
 * @param id_match Nr ID, ktory jest wyszukiwany (podany przez uzytkownika)
*/
template <typename T>
void zwroc_d(std::list<T>& list, int id_match);

/**
 * @brief Klasa glowna biblioteka
 * Zawiera pola prywatne w postaci list poszczegolnych zbiorow
 * Metody publiczne wywolywane w menu sluzace do wykonywania operacji na zbiorach bibliotecznych
*/
class Biblioteka {
private:
	/**
	 * @brief Lista przechowujaca dziela pismiennicze
	*/
	std::list<Dzielo_pismiennicze> ksiazki;
	/**
	 * @brief Lista przechowujaca dziela graficzne
	*/
	std::list<Dzielo_graficzne> obrazy;
	/**
	 * @brief Lista przechowujaca dziela audiowizualne
	*/
	std::list<Dzielo_audiowizualne> filmy;
public:
	/**
	 * @brief Typy wyliczeniowe sluzacae do wybierania opcji
	*/
	enum class Opcja { dodaj, usun, wypisz, wypozycz, zwroc, wyjscie };
	/**
	 * @brief Typ wyliczeniowy sluzacy do wybierania dziela, na ktorym operujemy 
	*/
	enum class Dziela { pismiennicze, graficzne, audiowizualne, wszystkie, powrot };
	/**
	 * @brief Funkcja sprawdzajaca, czy uzytkownik podal poprawna wartosc liczbowa (int)
	 * @param input Dane podane przez uzytkownika
	 * @return Poprawna wartosc input
	*/
	int int_exception(int& input);
	/**
	 * @brief Funkcja sprawdzajaca, czy uzytkownik podal poprawna wartosc liczbowa (float) 
	 * @param input Dane podane przez uzytkownika
	 * @return Poprawna wartosc input
	*/
	float float_exception(float& input);
	/**
	 * @brief Funkcja wywolywana w menu, sluzaca do dodawania nowych dziel
	*/
	void dodaj_dzielo();
	/**
	 * @brief Funkcja wywolywana w menu, sluzaca do usuwania istniejacych dziel po ich ID
	*/
	void usun_dziela();
	/**
	 * @brief Funkcja wywolywana w menu, sluzaca do wypisywania aktualnych dziel
	*/
	void wypisz_dziela();
	/**
	 * @brief Funkcja wywolywana w menu, sluzaca do wypozyczania dziel dziel po ich ID
	*/
	void wypozyczDzielo();
	/**
	 * @brief Funkcja wywolywana w menu, sluzaca do zwracania dziel dziel po ich ID
	*/
	void zwrocDzielo();
	/**
	 * @brief Glowna funkcja programu, w niej wywolywane sa wszystkie metody
	*/
	void menu();

};