#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "algorytm.h"

using namespace std;

/*!
 * \file
 * \brief Plik z definicjami metod dla klasy algorytm
 *
 * Plik zawiera definicje metod klasy algorytm oraz
 * przeciazenie operatora przypisania. Zdefiniowane sa tutaj
 * metody odpowiadajace za wczytanie pliku z danymi
 * oraz pliku z danymi sprawdzajacymi. Ponadto zdefiniowana
 * sa metody pobrania czasu, wykonania obliczen algorytmu,
 * sprawdzajaca poprawnosc obliczen oraz test algorytmu.
 * w tym miejsu również znajduja sie definicje operacji
 * odwracania elementow tablicy, zamiany danych elementow,
 * dodanie elementu do tablicy, dodanie dwoch tablic.
 *
 */

	int* algorytm::wczytaj_dane(){
		fstream plik;
		int i;
		plik.open("test10.txt");
		if(plik.good()==true){
			plik>>elementy;
			tab_danych=new int[elementy];
			for(i=0;i<elementy;i++){
				plik>>tab_danych[i];
			}
		}
		else{
			cerr<<"Proba otwarcia pliku testowego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
		return tab_danych;
	}
	clock_t algorytm::pobierz_czas(){
		clock_t czas;
		czas=clock();
		return czas;
	}
	int* algorytm::wykonaj_obliczenia(){
		int i;
		tab_obliczone=new int[elementy];
		for(i=0;i<elementy;i++){
			tab_obliczone[i]=tab_danych[i]*2;
		}
	return tab_obliczone;
	}
	int* algorytm::wczytaj_dane_sprawdzajace(){
		fstream plik;
		int i;
		tab_sprawdzajace=new int[elementy];
		plik.open("sprawdzenie10.txt");
		if(plik.good()==true){
			for(i=0;i<elementy;i++){
				plik>>tab_sprawdzajace[i];
			}
		}
		else{
			cerr<<"Proba otwarcia pliku sprawdzajacego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
		return tab_sprawdzajace;
	}
	bool algorytm::sprawdz(){
		int i;
		int dobrze=0;
		int zle=0;
		bool rezultat;
		for(i=0;i<elementy;i++){
			if(tab_obliczone[i]==tab_sprawdzajace[i])
				dobrze++;
			else
				zle++;
		}
		if(dobrze==elementy){
			rezultat=true;
		}
		else{
			rezultat=false;
		}
		return rezultat;
	}
	void algorytm::zamien_elementy(int* tablica,int pierwszy,int drugi){
		int temp;
		temp=tablica[pierwszy];
		tablica[pierwszy]=tablica[drugi];
		tablica[drugi]=temp;
	}
	void algorytm::odwroc_tablice(int* tablica){
		int i,j;
		j=elementy-1;
		for(i=0;i<=j;i++){
			zamien_elementy(tablica,i,j);
			j--;
		}
	}
	int* algorytm::dodaj_element(int* tablica,int element){
		int* tab_nowa;
		int i;
		tab_nowa=new int[elementy+1];
		for(i=0;i<elementy;i++){
			tab_nowa[i]=tablica[i];
		}
		tab_nowa[elementy]=element;
		return tab_nowa;
	}
	int* algorytm::dodaj_elementy(int* tab_pierwsza,int* tab_druga){
		int* tab_nowa;
		int i=0,j=0;
		tab_nowa=new int[2*elementy];
		for(i=0;i<elementy;i++){
			tab_nowa[i+j]=tab_pierwsza[i];
		}
		for(j=0;j<elementy;j++){
				tab_nowa[i+j]=tab_druga[j];
			}
		return tab_nowa;
	}
	int* algorytm::operator = (int* tab_pierwsza){
		int i;
		int* tab_nowa;
		tab_nowa=new int[elementy];
		for(i=0;i<elementy;i++){
			tab_nowa[i]=tab_pierwsza[i];
		}
		return tab_nowa;
	}
	int algorytm::test(dane *Info){
		clock_t czas_przed,czas_po,czas_powtorzenia;
		int i;
		Info->powtorzenia=powtorzenia;
		wczytaj_dane();
		for(i=0;i<powtorzenia;i++){
			czas_przed=pobierz_czas();
			wykonaj_obliczenia();
			czas_po=pobierz_czas();
			czas_powtorzenia=((float(czas_po-czas_przed))/CLOCKS_PER_SEC);
			Info->tab_czasow[i]=czas_powtorzenia;
		}
		wczytaj_dane_sprawdzajace();
		sprawdz();
		Info->wylicz_odchylenie();
		Info->zapisz_do_csv();
		return 0;
	}