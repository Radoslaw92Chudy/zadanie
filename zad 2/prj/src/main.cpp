#include <iostream>
#include <cstdlib>
#include "dane.h"
#include "algorytm.h"

using namespace std;
/*!
 * \file
 * \brief Funkcja main
 *
 * Plik zawiera glowna funkcje main w ktorej wywolywana jest 
 * metoda test obiektu algorytm. Ponadto w niej wczytywana 
 * jest do pola obiektu klasy algorytm liczba powtorzen 
 * wykonania algorytmu. Po wykonaniu wszystkich operacji funkcja
 * zwraca zero.
 *
 * \return Zwraca wartosc logiczna 0.
 */

int main(){
	algorytm Algo;
	cout<<"Podaj ilosc powtorzen algorytmu"<<endl;
	//cin>>Algo.powtorzenia;
	while(!(cin>>Algo.powtorzenia)){
		cerr<<"Blad podanej ilosci powtorzen. Musisz podac liczbe!"<<endl;
		cin.clear();
		cin.sync();
		exit(0);
	}
	dane Info(Algo.powtorzenia);
	dane *wsk=&Info;
	Algo.test(wsk);
	return 0;
}