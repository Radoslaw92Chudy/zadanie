#ifndef TABLICA_ASOCJACYJNA_H
#define TABLICA_ASOCJACYJNA_H
#include <iostream>
#include <list>

using namespace std;
//struktura danej dodawanej do tablicy
template<typename TYP>
class informacja{
public:
	TYP klucz;
	TYP wartosc;
};
//struktura tablicy
template<typename TYP>
class tab_asoc{
public:
	int ilosc;
	list<informacja> lista;
	
	tab_asoc(){
		ilosc=0;
	}
	~tab_asoc(){
	}

	int zliczElementy(){
		return ilosc;
	}

	bool czyPusta(){
		if(zliczElementy()==0)
			return true;
		else
			return false;
	}

	void dodaj(TYP klucz,TYP wartosc){
		informacja temp;
		temp.klucz=klucz;
		temp.wartosc=wartosc;
		lista.push_back(temp);	
		ilosc++;
	}

	void usun(TYP klucz){

		ilosc--;
	}

	TYP pobierz(TYP klucz){
		TYP wartosc;

		return wartosc;
	}

};


#endif
