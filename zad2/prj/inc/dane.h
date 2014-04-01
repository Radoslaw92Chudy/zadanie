#ifndef DANE_H
#define DANE_H

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

/*!
 * \file
 * \brief Definicja klasy dane
 *
 * Plik zawiera definicje klasy dane w ktorej znajduja sie 
 * informacje dotyczace wykonania algorytmu z powtorzeniami.
 */
 /*!
 * \brief Modeluje pojecie dane
 *
 * Klasa modeluje pojecie dane. W tej klasie znajduja sie 
 * informacje dotyczace podsumowania pracy algorytmu. Polami
 * tej klasy sa zmienne odpowiadajace za min. ilosc powtorzen
 * algorytmu. Metody tej klasy wyliczaja odchylenie 
 * standardowe oraz zapisuja dane podsumowujace w pliku csv.
 */
class dane{
public:
	/*!
	 *\brief Pole powtorzenia
	 *
	 * Pole to odpowiedzialne jest za przechowywanie
	 * informacji mowiacej o ilosci powtorzen algorytmu.
	 * Zmienna jest typu int.
	 */
	int powtorzenia;
	/*!
	 *\brief Pole czas_operacji
	 *
	 * Pole to odpowiedzialne jest za przechowywanie
	 * informacji mowiacej w jakim czasie wykonano wszystkie
	 * powtorzenia algorytmu. Zmienna jest typu double.
	 */
	double czas_operacji;
	/*!
	 *\brief Pole odchylenie
	 *
	 * Pole to odpowiedzialne jest za przechowywanie
	 * informacji mowiacej ile wynosi odchylenie standardowe
	 * z czasow wykonania algorytmu. Zmienna jest typu double.
	 */
	double odchylenie;
	/*!
	 *\brief Pole *tab_czasow
	 *
	 * Pole to odpowiedzialne jest za przechowywanie
	 * czasow kazdego powtorzenia. Jest ono wskaznikiem na te
	 * tablice, ktora jest alokowana w sposob dynamiczny. Ilosc
	 * elementow okreslona jest przez ilosc powtorzen algorytmu.
	 */
	double *tab_czasow;
	/*!
	 *\brief Konstruktor parametryczny
	 *
	 * Konstruktor jako parametr przyjmuje wartosc powtorzen, 
	 * aby zaalokowac pamiec potrzebna do przechowywania czasu
	 * kazdego powtorzenia algorytmu.
	 */
	dane(int powtorzenia);
	/*!
	 *\brief Metoda wyliczajaca odchylenie standardowe 
	 *
	 * Metoda ta wylicza wartosc odchylenia standardowego zestawu
	 * czasow zawartych w tablicy czasow tab_czasow. Metoda nie
	 * przyjmuje parametrow, ani nie zwraca zadnej wartosci.
	 */
	void wylicz_odchylenie();
	/*!
	 *\brief Metoda zapisujaca dane do pliku csv 
	 *
	 * Metoda ta zapisuje informacje dotyczace wykonania sie
	 * algorytmu w pliku formatu csv. W tej metodzie tworzony jest
	 * odpowiedni obiekt klasy fstream do ktorego zapisywane sa 
	 * informacje odnosnie ilosci powtorzen, czasu operacji, czasu
	 * powtorzen oraz odchylenie standardowe czasow.
	 */
	void zapisz_do_csv();
};

#endif