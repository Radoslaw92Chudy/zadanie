#ifndef KOLEJKA_H
#define KOLEJKA_H
#include <list>
#include <iostream>

/*!
 *\file
 *\brief Modeluje pojecie kolejki
 *
 * W pliku znajduja sie defincije klas tworzacych
 * strukture danych jaka jest kolejka. Pierwsza z
 * klas opiera sie na szablonie listy z kontenera STL
 * druga zas opiera dzialanie na bazie tablicy
 * alokowanej dynamicznie.
 */

using namespace std;

/*!
 *\brief Definicja klasy kolejkalist
 *
 * Szablon klasy kolejkalist jest implementacja
 * listy na bazie listy z kontenera STL. W sklad
 * szablonu wchodzi szablon listy oraz pole klasy 
 * pierwszy typu TYP przechowujacy pierwszy
 * element po wykonaniu operacji pobrania elemnetu.
 */
template<typename TYP>
class kolejkalist{
public:
	/*!
	 *\brief Pole lista
	 *
	 * Pole lista jest szablonem listy zmiennych typu TYP.
	 * W niej przechowywane sa elementy ktore dodawane sa
	 * do kolejki.
	 */
	list<TYP> lista;
	/*!
	 *\brief Pole pierwszy
	 *
	 * Pole pierwszy jest zmienna typu takiego jaki zostanie
	 * podany przez uzytkownika w momencie tworzenia
	 * obiektu. Przechowywana w nim jest wartosc elementu
	 * ktory jako ostatni zostal pobrany z kolejki.
	 */
	TYP pierwszy;
	/*!
	 *\brief Konstruktor klasy kolejkalist
	 *
	 * W konstruktorze klasy inicjalizowana jest
	 * wartosc zmiennej pierwszy.
	 */
	kolejkalist(){
		pierwszy=0;
	}
	/*!
	 *\brief Metoda size
	 * 
	 * Metoda size podaje ilosc elementow znajdujacych sie
	 * w kolejce. Zwraca wynik funkci size z szablonu
	 * listy. Wartosc ta jest typu calkowitego.
	 *
	 *\return Zwraca ilosc elementow w kolejce
	 */
	int size(){
		return lista.size();
	}
	/*!
	 *\brief Metoda empty
	 *
	 * Metoda ta sprawdza czy w kolejce znajduja sie jakiekolwiek elementy.
	 * Sprawdza ona warunek czy rozmiar kolejki zwracany w metodzie
	 * size jest rowny 0. Jeśli tak to zwraca wartosc logiczna true
	 * jesli nie to zwraca wartosc false. Metoda nie pobiera
	 * zadnych argumentow.
	 *
	 *\return Zwraca wartosc logiczna w zaleznosci od wyniku operacji porownania
	 */
	bool empty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	/*!
	 *\brief Metoda enqueue
	 *
	 * Metoda enqueue dodaje element na koniec kolejki.
	 * Wykorzystuje do tego metode z szablonu listy
	 * push_back ktora dodaje element na koniec listy.
	 * Metoda pobiera argument element typu TYP. Nie zwraca
	 * zadnych wartosci.
	 *
	 *\param[in] element - element ktory ma byc dolozony na koniec kolejki
	 */
	void enqueue(TYP element){
		lista.push_back(element);
	}
	/*!
	 *\brief Metoda dequeue
	 *
	 * Metoda ta zabiera pierwszy element znajdujacy sie w kolejce.
	 * Nie przyjmuje zadnych argumentow oraz nie zwraca zadnych
	 * wartosci. W przypadku braku elementow w kolejce uzytkownik
	 * jest informowany o tym fakcie odpowiednim komunikatem.
	 */
	void dequeue(){
		if(empty()!=true){
			pierwszy=lista.front();
			lista.pop_front();
		}
		else{
			cerr<<"Blad. Brak elementow w kolejce"<<endl;
			exit(0);
		}
	}
};
/*!
 *\brief Szablon klasy kolejkatab
 *
 * Szablon klasy kolejkatab jest implementacja kolejki
 * w oparciu o tablice alokowana dynamicznie. W szablonie
 * znajduja sie wszystkie niezbedne metody do poprawnego
 * funkcjonowania obiektow jako kolejek.
 */
template<typename TYP>
class kolejkatab{
public:
	/*!
	 *\brief Pole rozmiar
	 * 
	 * Rozmiar jest zmienna typu int ktora przechowuje rozmiar
	 * zaalokowanej dynamicznie tablicy w ktorej znajduje sie kolejka.
	 */
	int rozmiar;
	/*!
	 *\brief Pole wskaznika na tablice
	 *
	 * Pole to jest wskaznikiem na tablice tab ktora bedzie przechowywala
	 * elementy znajdujace sie w kolejce. Zainicjowanie tablicy
	 * dokonuje sie w w metodzie tworz po podaniu rozmiaru tablicy.
	 */
	TYP *tab;
	/*!
	 *\brief Pole ilosc
	 *
	 * Pole ilosc odpowiada za przechowywanie
	 * informacji ile elementow znajduje sie w kolejce.
	 * Sluzy do sprawdzenia wypelnienia tablicy.
	 */
	unsigned int ilosc;
	/*!
	 *\brief Pole pierwszy
	 *
	 * Pole pierwszy przechowuje wartosc pierwszego elementu znajdujacego sie 
	 * w kolejce.
	 *
	 */
	TYP pierwszy;
	/*!
	 *\brief Konstruktor klasy kolejkatab
	 * 
	 * Konstruktor klasy kolejkatab. W nim przypisywana
	 * jest wartosc poczatkowa polom ilosc oraz rozmiar.
	 */
	kolejkatab(){
		ilosc=0;
		rozmiar=0;
	}
	/*!
	 *\brief Metoda tworz
	 *
	 * Metoda tworz tworzy tablice dynamiczna o zadanym
	 * rozmiarze. Jako argument przyjmuje zmienna N typu
	 * int. Metoda zwraca wskaznik na tablice typow TYP.
	 *
	 *\param[in] N - wartosc rozmiaru zadeklarowanej tablicy
	 *
	 *\return Wskaznik na tablice typow TYP
	 */
	TYP* tworz(int N){
		rozmiar=N;
		tab=new TYP[rozmiar];
		return tab;
	}
	/*!
	 *\brief Metoda empty
	 *
	 * Metoda empty sluzy do sprawdzenia czy w kolejce
	 * znajduja sie jakies elementy. Jesli wartosc zwracana
	 * przez metoda size jest inna od 0 wtedy funkcja zwraca
	 * wartosc false. W przypadku prawdziwosci warunku zwracana
	 * jest wartosc true.
	 *
	 *\return Zwraca wartosc logiczna w zaleznosci od warunku petli
	 */
	bool empty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	/*!
	 *\brief Metoda size
	 *
	 * Metoda size sluzy do podania ilosci elementow w kolejce.
	 * Zwraca aktualna wartosc zmiennej ilosc. Zwracana wartosc
	 * jest typu int.
	 *
	 *\return Zwraca wartosc zmiennej ilosc. 
	 */
	int size(){
		return ilosc;
	}
	/*!
	 *\brief Metoda enqueue_dod
	 *
	 * Metoda enqueue_dod dokonuje dodania elementu
	 * na koniec kolejki. W przypadku kiedy tablica
	 * do ktorej wprowadzane sa wartosci jest
	 * zapelniona to jej rozmiar zwiekszany jest o 1.
	 * Jako argument metoda przyjmuje wartosc elementu
	 * typu TYP. Nie zwraca zadnych wartosci.
	 * 
	 *\param[in] element - zmienna typu TYP dodawana na koniec kolejki
	 */
	void enqueue_dod(TYP element){
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
	 *\brief Metoda enqueue_pom
	 *
	 * Metoda enqueue_dod dokonuje dodania elementu
	 * na koniec kolejki. W przypadku kiedy tablica
	 * do ktorej wprowadzane sa wartosci jest
	 * zapelniona to jej rozmiar zwiekszany dwukrotnie.
	 * Jako argument metoda przyjmuje wartosc elementu
	 * typu TYP. Nie zwraca zadnych wartosci.
	 * 
	 *\param[in] element - zmienna typu TYP dodawana na koniec kolejki
	 */
	void enqueue_pom(TYP element){
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
	 *\brief Metoda dequeue
	 *
	 * Metoda usuwajaca pierwszy element z kolejki.
	 * W przypadku gdy w kolejce nie ma elementow
	 * operacja usuniecia elementu nie zostanie wykonana.
	 * Uzytkownik jest o tym fakcie informowany odpowiednim komunikatem.
	 * Gdy kolejka wypelniona jest w co najmniej w 1/4 to
	 * rozmiar zaalokowanej tablicy zmniejszany jest o
	 * polowe. Metoda nie zwraca zadnych wartosci. Wartosc usunietego
	 * elementu przechowywana jest w polu pierwszy dopoki nie 
	 * zostanie wykonana kolejna operacja usuniecia elementu z 
	 * kolejki.
	 */
	void dequeue(){
		if(empty()==false){
			int wymiar;
			int *tmp;
			wymiar=rozmiar-1;
			tmp=new TYP[wymiar];
			pierwszy=tab[0];
			for(int j=0;j<wymiar;j++){
				tmp[j]=tab[j+1];
			}
			delete [] tab;
			tab=tmp;
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
	 *\brief Metoda clear
	 *
	 * Metoda wykonujaca operacje sciagniecia wszytskich elementow
	 * z kolejki. Zapobiega przed nadpisywaniem wartosci.
	 */
	void clear(){
		while(!empty())
			dequeue();
	}
};

#endif