#include "Biblioteka.h"

#include <list>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>

//szablon uzywany do usuwania dziel, jako parametry funkcja usun przyjmuje nazwe listy oraz id wg ktorego szukane jest dzielo
template <typename T>
void usun(std::list<T>& list, int id_match) {
	if (!list.empty()) {
		for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++) {
			if (it->getID() == id_match)
			{			
				list.erase(it);
				std::cout << "Pomyslnie usunieto dzielo o ID: " << id_match << std::endl;
				return;
			}
		}
		std::cout << "Nie znaleziono wybranej pozycji. (ID: "<<id_match<<")\n";
	}
	else {
		std::cout << "Lista dziel jest pusta" << std::endl;
	}

}
//szablon uzywany do wypozyczania dziel, jako parametry funkcja wypozycz_d przyjmuje nazwe listy oraz id wg ktorego szukane jest dzielo
template <typename T>
void wypozycz_d(std::list<T>& list, int id_match) {
	if (!list.empty()) {
		for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++) {
			if (it->getID() == id_match)
			{
				
				if (it->wypozycz()) {
					std::cout << "Pomyslnie wypozyczono dzielo o ID: " << id_match << std::endl;
					break;
				}
				else {
					std::cout << "Pozycja aktualnie niedostepna. ID: " << id_match << std::endl;
					break;
				}
			
			}
		}
	}
	else {
		std::cout << "Nie znaleziono wybranej pozycji lub lista dziel jest pusta" << std::endl;
	}
}
template <typename T>
void zwroc_d(std::list<T>& list, int id_match) {
	if (!list.empty()) {
		for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++) {
			if (it->getID() == id_match)
			{

				if (it->zwroc()) {
					std::cout << "Pomyslnie zwrocono dzielo o ID: " << id_match << std::endl;
					break;
				}
				else {
					std::cout << "Pozycja jest dostepna. ID: " << id_match << std::endl;
					break;
				}
			}
		}
	}
	else {
		std::cout << "Nie znaleziono wybranej pozycji lub lista dziel jest pusta" << std::endl;
	}
}



int Biblioteka::int_exception(int &input) {
	while (true) {
		
		if (std::cin.fail()||input<0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "WARTOSC NIEPRAWIDLOWA. PODAJ LICZBE >0: "; std::cin >> input;
		}
		else {
			break;
		}
	}
	return input;
}
float Biblioteka::float_exception(float &input) {
	while (true) {

		if (std::cin.fail() || input < 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Blad , sprobuj ponownie: "; std::cin >> input;
		}
		else {
			break;
		}
	}
	return input;
}


void Biblioteka::dodaj_dzielo() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << "=WYBIERZ DZIELO DO DODANIA: \n1. DZIELO PISMIENNICZE\n2. DZIELO GRAFICZNE\n3. DZIELO AUDIOWIZUALNE\nWybor: ";
	std::string imie, nazwisko, tytul;
	int wybor_dodaj;
	std::cin >> wybor_dodaj;
	int_exception(wybor_dodaj);
	Dziela wybrane_dzielo = Dziela::powrot;
	switch (wybor_dodaj)
	{
	case 1:
		wybrane_dzielo = Dziela::pismiennicze;
		std::cout << "-DODAJESZ NOWA KSIAZKE-" << std::endl;
		break;
	case 2:
		wybrane_dzielo = Dziela::graficzne;
		std::cout << "-DODAJESZ NOWE DZIELO GRAFICZNE-" << std::endl;
		break;
	case 3:
		wybrane_dzielo = Dziela::audiowizualne;
		std::cout << "-DODAJESZ NOWE DZIELO AUDIOWIZUALNE-" << std::endl;
		break;
	default:
		std::cin.clear();
		//std::cerr << "Wybrano nieprawidlowa wartosc. Sprobuj ponownie: ";
		break;
	}
		std::cout << "Imie: ";
		std::cin >> imie;
		std::cout << "Nazwisko: ";
		std::cin >> nazwisko;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Tytul: ";
		std::getline(std::cin, tytul);
	if (wybrane_dzielo == Dziela::pismiennicze) {
		Dzielo_pismiennicze suma;
		unsigned long long int ISBN;
		std::cout << "Nr ISBN: ";
		std::cin >> ISBN;
		while (true)
		{
			if (std::cin.fail() || ISBN < 0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max()>'\n');
				std::cout << "Podana wartosc jest nieprawidlowa. Sprobuj ponownie: "; std::cin >> ISBN;
			}
			else {
				break;
			}
		}
		if (suma.sprawdz_sume_kontrolna(ISBN)) {
			Dzielo_pismiennicze nowe_dzielo_pismiennicze(imie, nazwisko, tytul, ISBN);
			ksiazki.push_back(nowe_dzielo_pismiennicze);
			std::cout << "-SUMA KONTROLNA PRAWIDLOWA-" << std::endl;
			std::cout << "-KSIAZKA DODANA-" << std::endl;
		}
		else {
			std::cout << "Wystapil blad przy podawaniu sumy kontrolnej! Pozycja nie zostala dodana" << std::endl;
		}
		
		
	}
	else if (wybrane_dzielo == Dziela::graficzne) {
		float wysokosc, szerokosc;
		std::cout << "Wysokosc: "; std::cin >> wysokosc;
		float_exception(wysokosc);
		std::cout << "Szerokosc: "; std::cin >> szerokosc;
		float_exception(szerokosc);

		Dzielo_graficzne nowe_dzielo_graficzne(imie, nazwisko, tytul, szerokosc, wysokosc);
		obrazy.push_back(nowe_dzielo_graficzne);
		std::cout << "-DZIELO GRAFICZNE DODANE-" << std::endl;
	}
	else if (wybrane_dzielo == Dziela::audiowizualne) {
		std::string dlugosc_nagrania;
		std::cout << "Dlugosc nagrania: ";
		std::getline(std::cin, dlugosc_nagrania);
		Dzielo_audiowizualne nowe_dzielo_audiowizualne(imie, nazwisko, tytul, dlugosc_nagrania);
		filmy.push_back(nowe_dzielo_audiowizualne);
		std::cout << "-DZIELO AUDIOWIZUALNE DODANE-" << std::endl;
	}
	else
	{
		std::cout << "Blad";
	}	
}
void Biblioteka::usun_dziela() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << "=usun DZIELO : \n1. DZIELO PISMIENNICZE\n2. DZIELO GRAFICZNE\n3. DZIELO AUDIOWIZUALNE\n4. CALY ZBIOR\nWybor: ";
	int wybor_dodaj;
	std::cin >> wybor_dodaj;
	int_exception(wybor_dodaj);
	Dziela wybrane_dzielo;
	switch (wybor_dodaj)
	{
	case 1:
		wybrane_dzielo = Dziela::pismiennicze;
		break;
	case 2:
		wybrane_dzielo = Dziela::graficzne;
		break;
	case 3:
		wybrane_dzielo = Dziela::audiowizualne;
		break;
	case 4:
		wybrane_dzielo = Dziela::wszystkie;
	default:
		std::cerr << "Wybrano nieprawidlowa wartosc. Sprobuj ponownie: ";
		break;
	}

	int id_match;
	std::cout << "Podaj id: ";
	std::cin >> id_match;
	int_exception(id_match);
	if (wybrane_dzielo == Dziela::pismiennicze) {
		usun(ksiazki, id_match);
	}
	else if (wybrane_dzielo == Dziela::graficzne) {
		usun(obrazy, id_match);
	}
	else if (wybrane_dzielo == Dziela::audiowizualne) {
		usun(filmy, id_match);
	}


}
void Biblioteka::wypisz_dziela() {

	std::cout << "\033[2J\033[1;1H";
	std::cout << "=WYBIERZ DZIELO DO WYPISANIA: \n1. DZIELO PISMIENNICZE\n2. DZIELO GRAFICZNE\n3. DZIELO AUDIOWIZUALNE\n4. CALY ZBIOR\nWybor: ";
	int wybor_dodaj;
	std::cin >> wybor_dodaj;
	int_exception(wybor_dodaj);
	Dziela wybrane_dzielo;
	switch (wybor_dodaj)
	{
	case 1:
		wybrane_dzielo = Dziela::pismiennicze;
		break;
	case 2:
		wybrane_dzielo = Dziela::graficzne;
		break;
	case 3:
		wybrane_dzielo = Dziela::audiowizualne;
		break;
	case 4:
		wybrane_dzielo = Dziela::wszystkie;
	default:
		std::cerr << "Wybrano nieprawidlowa wartosc. Sprobuj ponownie: ";
		break;
	}

	if (wybrane_dzielo == Dziela::pismiennicze && ksiazki.size()!=0) {
		std::cout << "=====================\n=Dziela pismiennicze=\n=====================" << std::endl;
		std::cout <<"| ID | IMIE | | NAZWISKO | | TYTUL | | NR ISBN | | WYPOZYCZONA | " << std::endl;
		std::string stan;
		for (auto dzielo : ksiazki) {
			stan = !dzielo.wypozyczona ? "Pozycja dostepna!" : "Pozycja niedostepna!";
			std::cout << dzielo.ID << " | " << dzielo.imie << " | " << dzielo.nazwisko << " | \"" << dzielo.tytul << "\" | " << dzielo.ISBN <<" | "<< stan << "\n";
			
		}
	}
	else if (wybrane_dzielo == Dziela::graficzne && obrazy.size()!=0) {
		std::cout << "=====================\n = Dziela graficzne = \n=====================\n";
		std::cout << "ID | IMIE | NAZWISKO | TYTUL | SZEROKOSC | WYSOKOSC | WYPOZYCZONA | " << std::endl;
		std::string stan;
		for (auto dzielo : obrazy) {
			stan = !dzielo.wypozyczona ? "Pozycja dostepna!" : "Pozycja niedostepna!";
			std::cout <<dzielo.ID<< " | " << dzielo.imie << " | " << dzielo.nazwisko << " | \"" << dzielo.tytul << "\" | " << dzielo.szerokosc << " | " << dzielo.wysokosc << stan<<"\n";
			
		}
	}
	else if (wybrane_dzielo == Dziela::audiowizualne && filmy.size() != 0) {
		std::cout << "=====================\n = Dziela audiowizualne = \n=====================";
		std::cout << "\nID | IMIE | NAZWISKO | TYTUL | DLUGOSC NAGRANIA | WYPOZYCZONA | " << std::endl;
		std::string stan;
		for (auto dzielo : filmy) {
			stan = !dzielo.wypozyczona ? "Pozycja dostepna!" : "Pozycja niedostepna!";
			std::cout <<dzielo.ID<<" | "<<dzielo.imie << " | " << dzielo.nazwisko << " | \"" << dzielo.tytul << "\" | " << dzielo.dlugosc_nagrania << stan<<"\n";
		}
	}
	else {
		std::cout << "Zbior nie zawiera zadnych pozycji"<<std::endl;
	}

}

void Biblioteka::wypozyczDzielo() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << "=WYBIERZ DZIELO DO WYPOZYCZENIA: \n1. DZIELO PISMIENNICZE\n2. DZIELO GRAFICZNE\n3. DZIELO AUDIOWIZUALNE\nWybor: ";
	int wybor_dodaj;
	std::cin >> wybor_dodaj;
	int_exception(wybor_dodaj);
	Dziela wybrane_dzielo;
	switch (wybor_dodaj)
	{
	case 1:
		wybrane_dzielo = Dziela::pismiennicze;
		break;
	case 2:
		wybrane_dzielo = Dziela::graficzne;
		break;
	case 3:
		wybrane_dzielo = Dziela::audiowizualne;
		break;
	default:
		std::cin.clear();
		//std::cerr << "Wybrano nieprawidlowa wartosc. Sprobuj ponownie: ";
		break;
	}

	int id_match;
	std::cout << "\nPodaj ID: "; std::cin >> id_match;
	int_exception(id_match);
	if (wybrane_dzielo == Dziela::pismiennicze) {
		wypozycz_d(ksiazki, id_match);
	}
	else if (wybrane_dzielo == Dziela::graficzne) {
		wypozycz_d(obrazy, id_match);
	}
	else if (wybrane_dzielo == Dziela::audiowizualne) {
		wypozycz_d(filmy, id_match);
	}

}

void Biblioteka::zwrocDzielo() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << "=WYBIERZ DZIELO DO ZWROCENIA: \n1. DZIELO PISMIENNICZE\n2. DZIELO GRAFICZNE\n3. DZIELO AUDIOWIZUALNE\nWybor: ";
	int wybor_dodaj;
	std::cin >> wybor_dodaj;
	int_exception(wybor_dodaj);
	Dziela wybrane_dzielo;
	switch (wybor_dodaj)
	{
	case 1:
		wybrane_dzielo = Dziela::pismiennicze;
		break;
	case 2:
		wybrane_dzielo = Dziela::graficzne;
		break;
	case 3:
		wybrane_dzielo = Dziela::audiowizualne;
		break;
	default:
		std::cin.clear();
		//std::cerr << "Wybrano nieprawidlowa wartosc. Sprobuj ponownie: ";
		break;
	}
	int id_match;
	std::cout << "\nPodaj ID: "; std::cin >> id_match;
	int_exception(id_match);
	if (wybrane_dzielo == Dziela::pismiennicze) {
		zwroc_d(ksiazki, id_match);
	}
	else if (wybrane_dzielo == Dziela::graficzne) {
		zwroc_d(obrazy, id_match);
	}
	else if (wybrane_dzielo == Dziela::audiowizualne) {
		zwroc_d(filmy, id_match);
	}
}

void Biblioteka::menu() {
	//menu programu sterowane za pomoca switch

	bool stop = false;
	while (!stop) {
		std::cout << "=WITAMY W BIBLIOTECE= \n";
		std::cout << "Wybierz opcje: \n1. DODAJ NOWE DZIELO\n2. USUN ISNTNIEJACE DZIELO\n3. WYPISZ\n4. WYPOZYCZ DZIELO\n5. ZWROC DZIELO\n6. WYJSCIE" << std::endl;
		std::cout << "Wybor: ";
		int wybor;
		std::cin >> wybor;	//wybor opcji
		int_exception(wybor); //funkcja obslugujaca blad uzytkownika, zwraca &wybor
		wybor -= 1;		// wybor -1 - aby enum wiedzial co wybrac a uzytkownikowi wyswietlal sie poprawny numer 
		Opcja opcja = static_cast<Opcja>(wybor);	//mapowanie wyboru na enum class

		switch (opcja)
		{
			//OPCJA DODAWNIA DZIEL
		case Opcja::dodaj:	
			dodaj_dzielo();
			break;
		case Opcja::usun:
			usun_dziela();
			break;
		case Opcja::wypisz:
			wypisz_dziela();
			break;
		case Opcja::wypozycz:
			wypozyczDzielo();
			break;
		case Opcja::zwroc:
			zwrocDzielo();
			break;
		case Opcja::wyjscie:
			std::cout << "DZIEKUJEMY";
			stop = true;
			break;
		default:
			break;
		}
		

	}
}