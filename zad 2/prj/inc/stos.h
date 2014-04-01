#ifndef STOS_H
#define STOS_H
#include <list>
#include <iostream>

/*!
 *\file
 *\brief Modeluje pojecie stosu
 * 
 * Plik definuje pojecie Stosu w oparciu o dwie klasy wykorzystujace
 * inne metody implementacji struktury. Klasa stoslist wykorzystuje 
 * szablon STL listy natomiast stostab implementuje tablice 
 * alokowana dynamicznie.
 */

using namespace std;
/*!
 *\brief Definicja szablonu stoslist
 *
 * Szablon stoslist jest implementacja stosu przy uzyciu 
 * szablonu listy dostepnego w STL list. W sklad szablonu 
 * wchodzi uzyty jako pole klasy szablon listy dzialajacy
 * dla roznych typow danych oraz pole ostatni ktore przechowuje
 * ostatni element znajdujacy sie na stosie.
 */
template<typename TYP>
class stoslist{
public:
	/*!
	 *\brief Pole lista
	 * 
	 * Lista jest to miejsce przechowywania danych 
	 * umieszczanych na stosie. Jest to obiekt typu list
	 * na bazie szablonu i dziala dla roznych typu danych.
	 */
	list<TYP> lista;
	/*!
	 *\brief Pole ostatni
	 * 
	 * Pole to odpowiada za przechowanie wartosci ostatniego
	 * elementu (pierwszy z gory) znajdujacego sie na stosie.
	 */
	TYP ostatni;
	/*!
	 *\brief Metoda size
	 * 
	 * Metoda size podaje ilosc elementow znajdujacych sie na stosie.
	 * Zwraca ona wynik metody z obiektu list.
	 *
	 *\return Zwraca wartosc typu int wyniku metody lista.size()
	 */
	int size(){
		return lista.size();
	}
	/*!
	 *\brief Metoda empty
	 * 
	 * Metoda empty sprawdza czy na stosie znajduja sie elementy.
	 * Jesli wynik wartosci zwracanej przez metode size jest inny
	 * od 0 to funkcja zwraca wartosc logiczna false. W przypadku
	 * gdy metoda size zwraca wartosc 0 to zwracana jest wartosc 
	 * logiczna true.
	 *
	 *\return Zwraca w zaleznosci od wyniku true badz false
	 */
	bool empty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	/*!
	 *\brief Metoda push
	 *
	 * Metoda push odpowiada za dodanie elementu do stosu 
	 * (na koniec listy). Metoda bazuje na metodzie obiektu lista
	 * push_back, ktora dodaje element na koniec listy. Jako 
	 * parametr wejsciowy metoda przyjmuje zmienna typu TYP. 
	 * Metoda nie zwraca zadnej wartosci.
	 *
	 *\param[in] element - element ktory ma zostac dodany do struktury stosu
	 */
	void push(TYP element){
		lista.push_back(element);
	}
	/*!
	 *\brief Metoda pop
	 *
	 * Metoda pop odpowiada za zabranie elementu ze stosu
	 * (z konca listy). W tej metodzie wykorzystywana jest
	 * metoda pop_back ktora usuwa ostatni element z listy.
	 * Przed wykonaniem usuniecia elementu z listy do pola
	 * ostatni zapisywana jest wartosc ostatniego elementu
	 * znajdujacego sie w liscie. Przed wykonaniem 
	 * jakiejkolwiek operacji sprawdzana jest liczba 
	 * elementow na stosie. W przypadku gdy na stosie nie 
	 * nie ma zadnego elementu to nie mozna wykonac
	 * operacji pobrania elementu ze stosu. W przypadku
	 * wywolania funkcji pop bez elementu na stosie. Uzytkownik
	 * informowany jest odpowiednim komunikatem o braku
	 * elementow na stosie. Metoda nie przyjmuje ani też nie 
	 * zwraca zadnych elementow.
	 */
	void pop(){
		if(empty()!=true){
			ostatni=lista.back();
			lista.pop_back();
		}
		else{
			cerr<<"Blad. Za malo elementow w kolejce"<<endl;
			exit(0);
		}
	}
};
/*!
 *\brief Definicja szablonu stostab
 *
 * Szablon stostab jest implementacja stosu przy uzyciu 
 * tablicy alokowanej dynamicznie. Zawiera on w sobie 
 * metody sprawdzajace ilosc oraz czy sa jakiekolwiek
 * elementy na stosie. Ponadto zawiera operacje dodania
 * elementu na stos ( na dwa sposoby: przy zwiekszaniu rozmiaru
 * tablicy o 1 oraz zwiekszaniu rozmiaru tablicy dwukrotnie) oraz
 * operacje pobrania elementu ze stosu. W swojej strukturze zdefiniowana ma
 * metode tworz ktora tworzy tablice o zadanym rozmiarze.
 */
template<typename TYP>
class stostab{
public:
	/*!
	 *\brief Pole rozmiar
	 *
	 * Pole rozmiar jest to zmienna typu int, ktora odpowiada za
	 * przechowywanie informacji o rozmiarze zaalokowanej
	 * dynamicznie tablicy.
	 */
	int rozmiar;
	/*!
	 *\brief Pole ilosc
	 *
	 * Pole ilosc odpowiada za przechowywanie informacji ile
	 * elementow znajduje sie aktualnie na stosie. Jest to zmienna
	 * typu int.
	 */
	unsigned int ilosc;
	/*!
	 *\brief Pole tab
	 *
	 * Pole tab jest to wskaznik na tablice zmiennych typu TYP alokowanej
	 * dynamicznie w metodzie tworz.
	 */
	TYP *tab;
	/*!
	 *\brief Pole ostatni
	 *
	 * Pole ostatni przechowuje wartosc ostatniego elementu pobranego ze stosu.
	 */
	TYP ostatni;
	/*!
	 *\brief Kontruktor stostab
	 *
	 * Konstruktor wywolywany przy kazdorazowym utworzeniu
	 * obiektu typu stostab. W nim przypisywane sa wartosci
	 * zmiennym ilosc oraz rozmiar ktore wynosza 0.
	 */
	stostab(){
		ilosc=0;
		rozmiar=0;
	}
	/*!
	 *\brief Destruktor stostab
	 *
	 * Destruktor obiektu stostab wywolywany przy 
	 * zakonczeniu dzialania obiektu. W nim usuwana
	 * jest cala tablica dynamiczna tab.
	 */
	~stostab(){
		delete [] tab;
	}
	/*!
	 *\brief Metoda tworz
	 *
	 * Metoda tworz tworzy tablice dynamiczna o zadanym rozmiarze
	 * Metoda przyjmuje jako parametr wejsciowy zmienna
	 * typu int. Jest to wartosc przypisywana do zmiennej rozmiar
	 * ktora opisuje rozmiar inicjalizowanej tablicy. Metoda
	 * zwraca wskaznik na tablice dynamiczna tab.
	 *
	 *\param[in] N - wartosc rozmiaru alokowanej tablicy
	 *
	 *\return Zwraca wskaznik na tablice tab
	 */
	int* tworz(int N){
		rozmiar = N;
		tab = new TYP[rozmiar];
		return tab;
	}
	/*!
	 *\brief Metoda push_dod
	 *
	 * Metoda push_dod jest to metoda wykonujaca operacje dodania
	 * elementu na koniec tablicy. Opiera się ona na powiekszeniu
	 * tablicy za kazdym razem o jeden gdy ilosc elementow
	 * jest rowna rozmiarowi tablicy. Jako argument metoda
	 * przyjmuje element typu TYP. Nie zwraca zadnej wartosci.
	 * W funkcji przepisywany jest wskaznik z tablicy tworzonej
	 * tymczasowo tablicy do tablicy stosu. Po kazdorazowym
	 * dodaniu elementu na stos zmienna ilosc jest powiekszana o 1.
	 *
	 *\param[in] element - element ktory ma zostac polozony na stos
	 */
	void push_dod(TYP element){
		int i,wymiar=0;
		if(ilosc==rozmiar){
			int *tmp;
			wymiar=rozmiar+1;
			tmp=new int[wymiar];
			for(i=0;i<rozmiar;i++){
				tmp[i]=tab[i];
			}
			delete [] tab;
			tmp[ilosc]=element;
			tab=tmp;
			rozmiar=wymiar;
		}
		else{
		tab[ilosc]=element;
		}
		ilosc++;
	}
	/*!
	 *\brief Metoda push_pom
	 *
	 * Metoda push_pom jest to metoda wykonujaca operacje
	 * dodania elementu na koniec stosu(tablicy). Opiera się
	 * ona na powiekszaniu rozmiaru tablicy dwukrotnie zawsze
	 * kiedy ilosc elementow tablicy bedzie rowna rozmiarowi 
	 * tablicy. Jako argument funkcja przyjmuje element typu
	 * TYP natomiast nie zwraca ona zadnej wartosci. W metodzie
	 * tworzona jest tymczasowa zmienna wymiar odpowiadajaca za 
	 * zaalokowanie tymczasowej tablicy o rozmiarze 2 razy 
	 * wiekszym w przypadku zapelnienia pierwotnej tablicy.
	 *
	 *\param[in] element - wartosc jaka ma zostac dodana na stos
	 */
	void push_pom(TYP element){
		int i,wymiar=0;
		if(ilosc==rozmiar){
			int *tmp;
			wymiar=rozmiar*2;
			tmp=new int[wymiar];
			for(i=0;i<rozmiar;i++){
				tmp[i]=tab[i];
			}
			delete [] tab;
			tmp[ilosc]=element;
			tab=tmp;
			rozmiar=wymiar;
		}
		else{
		tab[ilosc]=element;
		}
		ilosc++;
	}
	/*!
	 *\brief Metoda pop
 	 *
 	 * Metoda pop wykonuje operacje usuniecia elementu
 	 * ze stosu. Nie przyjmuje argumentow wejsciowych.
 	 * Przed wykonaniem operacji usuniecia elementu
 	 * ze stosu sprawdzane jest czy na stosie znajduja
 	 * sie elementy. Jesli tak to operacja moze zostac
 	 * wykonana jezeli nie to uzytkownik jest informowany
 	 * o tym fakcie odpowiednim komunikatem. Po wykonaniu
 	 * usuniecia elementu z tablicy sprawdzana jest ilosc
 	 * elementow w tablicy. Jezeli tablica jest zapelniona
 	 * w 1/4 rozmiaru elementami to jej rozmiar jest zmniejszany
 	 * o polowe. Jezeli nie jest spelniony ten warunek to tablica
 	 * zachowuje swoj rozmiar. Metoda zwraca usuniety element ze stosu.
 	 * 
 	 *\return Zwraca ostatni element na stosie 
 	 */
	void pop(){
		if(empty()==false){
			int indeks=ilosc-1;
			ostatni=tab[indeks];
			ilosc--;
		}
		else{
			cerr<<"Brak elementow na stosie"<<endl;
			exit(0);
		}
		if(4*ilosc<=rozmiar){
			int *tmp;
			int wymiar;
			wymiar=rozmiar/2;
			tmp=new int[wymiar];
			for(int k=0;k<ilosc;k++){
				tmp[k]=tab[k];
			}
			delete [] tab;
			tab=tmp;
			rozmiar=wymiar;
		}
	}
	/*!
	 *\brief Metoda size
	 *
	 * Metoda size podaje ilosc elementow znajdujacych sie na stosie.
	 * Metoda ta zwraca wartosc typu int tzn aktualna wartosc
	 * pola ilosc klasy stostab.Nie przyjmuje zadnych wartosci.
	 *
	 *\return Zwraca wartosc zmiennej ilosc
	 */
	int size(){
		return ilosc;
	}
	/*!
 	 *\brief Metoda empty
 	 *
 	 * Metoda empty sprawdza czy na stosie znajduja sie elementy.
 	 * Petla warunkowa if sprawdza wartosc zwracana przez
 	 * funkcje size. Jezeli jest ona rowna 0 to zwracana jest
 	 * wartosc logiczna true. Natomiast kiedy size zwraca inna wartosc
 	 * niz 0 to zwracana jest wartosc false. Metoda nie przyjmuje 
 	 * argumentow wejsciowych.
 	 *
 	 *\return Zwraca wartosc logiczna typu bool w zaleznosci od rezultatu
 	 */
	bool empty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	/*!
	 *\brief Metoda clear
	 *
	 * Metoda clear sluzy do usuniecia wszystkich elementow ze stosu.
	 * Wykorzystywana jest w momencie kilkukrotnego mierzenia czasu
	 * operacji. Zapobiega przed zaalokowaniem za duzej pamieci.
	 * Nie zwraca zadnych wartosci. Nie przyjmuje tez argumentow.
	 */
	void clear(){
		while(!empty())
			pop();
	}
};



#endif