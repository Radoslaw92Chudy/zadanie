#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "dane.h"

using namespace std;

/*!
 * \file
 * \brief Plik z definicjami metod dla klasy dane
 *
 * Plik zawiera definicje metod klasy dane tj. wyliczania 
 * wartosci odchylenia standardowego oraz zapisywania danych
 * do pliku formatu csv. Ponadto zawiera definicje konstruktora
 * parametrycznego w ktorym alokowana jest tablica do ktorej
 * beda wpisywane czasy poszczegolnych powtorzen.
 *
 */
	dane::dane(int powtorzenia){
		tab_czasow=new clock_t[powtorzenia];
	}
	void dane::wylicz_odchylenie(){
		double suma=0;
		double suma_kwadratow=0;
		double srednia=0;
		int i;
		for(i=0;i<powtorzenia;i++){
			suma+=suma+tab_czasow[i];
		}
		srednia=suma/powtorzenia;
		for(i=0;i<powtorzenia;i++){
			suma_kwadratow+=suma_kwadratow+(tab_czasow[i]-srednia)*(tab_czasow[i]-srednia);
		}
		odchylenie=sqrt(suma_kwadratow/(powtorzenia-1));
	}
	void dane::zapisz_do_csv(){
		fstream plikcsv;
		int i=0;
		plikcsv.open("dane.csv", ios::out); 
		plikcsv<<"Powtorzenia,"<<powtorzenia<<"\n";
  		plikcsv<<"Powtorzenie,"<<"Czas"<<endl;
  		for(i=0;i<powtorzenia;i++){
  			plikcsv<<i+1<<","<<tab_czasow[i]<<"\n";
  		}
  		czas_operacji=((float)(tab_czasow[i]-tab_czasow[0]))/CLOCKS_PER_SEC;
  		plikcsv<<"Czas Operacji,"<<czas_operacji<<"\n";
      	plikcsv<<"Odchy.standardowe,"<<odchylenie<<"\n"; 
  		plikcsv.close();
	}