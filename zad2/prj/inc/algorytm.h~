#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <iostream>
#include <ctime>
#include <cmath>
#include "dane.h"

using namespace std;
/*!
 * \file
 * \brief Definicja klasy algorytm
 *
 * Plik zawiera definicje klasy algorytm, ktora wykonuje 
 * niezbedne operacje na plikach tekstowych.
 */
 /*!
  * \brief Modeluje pojecie algorytmu
  *
  * Klasa modeluje pojecie algorytmu w sklad ktorego wchodza
  * pola odpowiadajace min. za ilosc wczytanych elementow,
  * powtorzenia algorytmow. Wsrod metod klasy znajduja sie min.
  * wczytanie danych, pobranie czasu, zamiana elementow tablicy
  * itd.
  */
class algorytm{
	public:
		/*!
		 *\brief Pole powtorzenia
		 *
		 * Pole to odpowiedzialne jest za przechowywanie
		 * informacji mowiacej o ilosci powtorzen algorytmu.
		*/
	int powtorzenia;
		/*!
		 *\brief Pole elementy
		 *
		 * Pole to odpowiedzialne jest za przechowywanie
		 * informacji mowiacej o ilosci elementow jaka 
		 * pozostanie wczytana do programu z pliku tekstowego.
		*/
	int elementy;
		/*!
		 *\brief Wskaznik tab_danych
		 *
		 * Pole to odpowiedzialne jest za przechowywanie
		 * wskaznika do alokowanej dynamicznie tablicy 
		 * danych zawierajacej elementy wczytane z pliku 
		 * testowego.
		*/
	int *tab_danych;
		/*!
		 *\brief Wskaznik tab_obliczone
		 *
		 * Pole to odpowiedzialne jest za przechowywanie
		 * wskaznika do alokowanej dynamicznie tablicy 
		 * danych zawierajacej wartosci elementow z tablicy
		 * danych przez okreslona wartosc. 
		*/
	int *tab_obliczone;
		/*!
		 *\brief Wskaznik tab_sprawdzajace
		 *
		 * Pole to odpowiedzialne jest za przechowywanie
		 * wskaznika do alokowanej dynamicznie tablicy 
		 * danych zawierajacej wartosci elementow z tablicy
		 * danych przez okreslona wartosc. 
		*/
	int *tab_sprawdzajace;
		/*!
		 *\brief Metoda wczytujaca dane z pliku tesowego
		 *
		 * Metoda ta wykonuje operacje wczytania pliku z 
		 * danymi do tablicy tab_danych zawierajacej dane
		 * int. rozmiar tablicy definiowany jest przez liczbe
		 * elementow okreslona przez pierwsza wartosc wczytana
		 * z pliku. W przypadku niepowodzenia operacji otwarcia
		 * pliku uzytkownik informowany jest o tym odpowiednim
		 * komunikatem. Metoda zwraca wskaznik na tablice 
		 * z wczytanymi przez nia danymi.
		 *
		 * \return Zwraca wskaznik na tab_danych
		 */
	int* wczytaj_dane();
		/*!
		 *\brief Metoda pobierajaca czas
		 *
		 * Metoda sluzy do pobrania czasu i wykorzystywana jest 
		 * obliczenia czasu w jakim wykonany zostal algorytm oraz
		 * kazde jego powtorzenie. Zwraca aktualny czas.
		 *
		 *\return Zwraca zmienna typu clock_t.
		 */
	clock_t pobierz_czas();
		/*!
		 *\brief Metoda wykonaj obliczenia
		 *
		 * Metoda sluzy do wykonywania obliczen na tablicy
		 * znajdujacej sie w polu klasy Algorytm. Funkcja zwraca
		 * wskaznik na tablice z danymi po wykonaniu operacji na 
		 * nich.
		 *
		 *\return Wskaznik na tab_obliczone.
		 */
	int* wykonaj_obliczenia();
		/*!
		 *\brief Metoda wczytujaca dane sprawdzajace z pliku tesowego
		 *
		 * Metoda ta wykonuje operacje wczytania pliku z 
		 * danymi do tablicy tab_sprawdzajace zawierajacej dane
		 * int. rozmiar tablicy definiowany jest przez liczbe
		 * elementow okreslona przez pierwsza wartosc wczytana
		 * z pliku z danymi testowymi. W przypadku niepowodzenia
		 * operacji otwarcia pliku uzytkownik informowany 
		 * jest o tym odpowiednim komunikatem. 
		 * Metoda zwraca wskaznik na tablice z wczytanymi
		 * przez nia danymi sprawdzajacymi.
		 *
		 * \return Zwraca wskaznik na tab_sprawdzajace.
		 */
	int* wczytaj_dane_sprawdzajace();
		/*!
		 *\brief Metoda Sprawdz
		 *
		 * Metoda ta sprawdza poprawnosci wykonania operacji
		 * na tablicy danych poprzez porownanie kazdego elementu
		 * tab_obliczone z odpowiadajacym jej elementem 
		 * tab_sprawdzjace. W przypadku poprawnego wykonania
		 * poprawnej operacji na tab_danych i porownaniu z
		 * tab_sprawdzajace metoda zwraca wartosc true gdy
		 * jakis z elementow jest inny od odpowiednika to
		 * zwracana jest wartosc false.
		 *
		 *\return Zwraca wartosc logiczna true/false w zaleznosci
		 * od rezultatu.
		 */
	bool sprawdz();
		/*!
		 *\brief Metoda zamien elementy
		 *
		 * Metoda zamien elementy dokonuje zamiany elementow
		 * o zadanych parametrach. Jako parametry metoda
		 * przyjmuje wskaznik na tablice na ktorej chcemy wykonac
		 * operacje oraz dwa kolejne argumenty typu int, ktore
		 * podaja numer elementu ktore maja byc ze soba zamienione.
		 * Zadna wartosc nie jest zwracana.
		 *
		 *\param[in] tablica - wskaznik na tablice, w ktorej chcemy zamienic elementy.
		 *\param[in] pierwszy - pierwszy z elementow tablicy ktore chcemy zamienic.
		 *\param[in] drugi - drug z elementow tablicy ktore chcemy ze soba zamienic.
		 *
		 */
	void zamien_elementy(int* tablica,int pierwszy,int drugi);
		/*!
		 *\brief Metoda odwroc tablice
		 *
		 * Metoda odwroc tablice wykonuje zamiane elementow tablicy
		 * w taki sposob iz pierwszy staje sie ostatni, a ostatni 
		 * pierwszym. Jako argument przyjmuje wskaznik na tablice
		 * ktora chcemy odwrocic. Nie zwraca wartosci.
		 *
		 *\param[in] tablica - wskaznik na tablice wartosci int.
		 */
	void odwroc_tablice(int* tablica);
		/*!
		 *\brief Metoda dodaj elementy
		 *
		 * Metoda dodaj element dodaje do zadanej tablicy jeden
		 * element o zadanej wartosci na koniec tablicy przez
		 * co tablica zwieksza swoj rozmiar o 1. Metoda zwraca 
		 * wskaznik na nowa tablice.
		 *
		 *\param[in] tablica - wskaznik na tablice do ktorej zostanie dodany element.
		 *\param[in] element - zmienna typu int ktora zostanie dodana do podanej tablicy.
		 *
		 *\return Zwraca wskaznik do nowej tablicy z dodanym elementem.
		 */
	int* dodaj_element(int* tablica,int element);
		/*!
		 *\brief Metoda dodaj elementy
		 *
		 * Metoda dodaje ze soba dwie tablice tworzac jeden element.
		 * Jako argumenty metoda przyjmuje wskazniki na tablice ktore
		 * maja byc ze soba dodane. Zwracany jest wskaznik na nowo
		 * stworzona tablice zlozona z elementow obu tablic.
		 *
		 *\param[in] tab_pierwsza - tablica od ktorej bedzie rozpoczynala sie nowo utworzona tablica.
		 *\param[in] tab_druga - tablica ktora zostanie dopisana jako druga do nowo utworzonej tablicy.
		 *
		 *\return Zwraca wskaznik na nowa tablice.
		 */
	int* dodaj_elementy(int* tab_pierwsza,int* tab_druga);
		/*!
		 *\brief Przeciazenie operatora przypisania
		 *
		 * Przeciazenie operatora przypisania pozwala na
		 * bezposrednie przypisanie dwoch tablic ze soba.
		 * Jako argument przyjmuje wskaznik na tablice ktora
		 * zostanie przypisana. Zwraca natomiast wskaznik
		 * na nowa tablice z przypisanymi elementami.
		 *
		 *\param[in] tab_pierwsza - wskaznik na tablice ktora bedzie przypisana do drugiej
		 *
		 *\return Zwraca wskaznik na ta tablice.
		 */
	int* operator = (int* tab_pierwsza);
		/*!
		 *\brief Metoda test
		 *
		 * Metoda test jak nazwa wskazuje dokonuje poprawnosci
		 * dzialania zalozen programu. Sklada sie z odpowiedniej
		 * sekkwencji wywolania funkcji. Otwierane sa tu pliki
		 * testowe i sprawdzajace. Do obiektu Info sa wysylane 
		 * odpowiednie informacje. Na koniec wywolywane sa metody
		 * klasy dane dokonujace zapisu danych statystycznych do
		 * pliku csv. Jako argument przyjmuje wskaznik do obiektu
		 * klasy dane. Zwraca wartosc logiczna 0 po wykonaniu testu
		 *
		 *\param[in] Info - wskaznik na obiekt klasy dane do ktorego zapisane bd wyniki przeprowadzonego testu.
		 *
		 *\return Zwraca wartosc logiczna typu int po wykonaniu testu.
		 */
	int test(dane *Info);
};


#endif