#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "algorytm.h"
#include "stos.h"
#include "kolejka.h"

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
 * Zdefiniowane sa tez pliki testowe dla operacji wczytywania
 * danych do struktur danych min kolejki i stosu.
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
	void algorytm::wczytaj_dane_stostab(){
		fstream plik;
		int dana;
		plik.open("test10.txt");
		if(plik.good()==true){
			plik>>stos.rozmiar;
			stos.tworz(stos.rozmiar);
			while(plik>>dana){
				stos.push_pom(dana);
			}
		}
		else{
			cerr<<"Proba otwarca pliku testowego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
	}
	void algorytm::wczytaj_dane_stoslista(){
		fstream plik;
		int dana;
		plik.open("test10.txt");
		if(plik.good()==true){
			plik>>stos.rozmiar;
			stos.tworz(1);
			while(plik>>dana){
				stoslista.push(dana);
			}
		}
		else{
			cerr<<"Proba otwarca pliku testowego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
	}
	void algorytm::wczytaj_dane_kolejkatab(){
		fstream plik;
		int dana;
		plik.open("test1000000.txt");
		if(plik.good()==true){
			plik>>kolejkatablica.rozmiar;
			stos.tworz(1);
			kolejkatablica.tworz(stos.rozmiar);
			while(plik>>dana){
				kolejkatablica.enqueue_dod(dana);
			}
		}
		else{
			cerr<<"Proba otwarca pliku testowego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
	}
	void algorytm::wczytaj_dane_kolejkalist(){
		fstream plik;
		int dana=0;
		plik.open("test10.txt");
		if(plik.good()==true){
			plik>>stos.rozmiar;
			stos.tworz(1);
			while(plik>>dana){
				kolejkalista.enqueue(dana);
			}
		}
		else{
			cerr<<"Proba otwarcia pliku testowego nie powiodla sie"<<endl;
			exit(0);
		}
		plik.close();
	}
	void algorytm::wlacz_zegar(){
		struct timespec tp;
		clock_gettime(CLOCK_REALTIME,&tp);
		czas_nsec=tp.tv_nsec;
		czas_sec=tp.tv_sec;
	}
	void algorytm::wylacz_zegar(){
		struct timespec tp;
		clock_gettime(CLOCK_REALTIME,&tp);
		czas_nsec=static_cast<double>(tp.tv_nsec-czas_nsec)/1E9;
		czas_sec=static_cast<double>(tp.tv_sec-czas_sec);
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
		double czas_powtorzenia;
		int i;
		Info->powtorzenia=powtorzenia;
		wczytaj_dane();
		for(i=0;i<powtorzenia;i++){
			wlacz_zegar();
			wykonaj_obliczenia();
			wylacz_zegar();
			czas_powtorzenia=czas_sec+czas_nsec;
			Info->tab_czasow[i]=czas_powtorzenia;
		}
		wczytaj_dane_sprawdzajace();
		sprawdz();
		Info->wylicz_odchylenie();
		Info->zapisz_do_csv();
		return 0;
	}
	void algorytm::test_wczytania(dane *Info){
		int i=0;
		double czas_powtorzenia;
		Info->powtorzenia=powtorzenia;
		for(i=0;i<powtorzenia;i++){
			wlacz_zegar();
			wczytaj_dane_kolejkatab();
			wylacz_zegar();
			czas_powtorzenia=czas_sec+czas_nsec;
			Info->tab_czasow[i]=czas_powtorzenia;
			kolejkatablica.clear();
		}
		Info->wylicz_odchylenie();
		Info->zapisz_do_csv();
	}