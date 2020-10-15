/*
Meno a priezvisko: Martin �of��k 98034

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du04.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
	 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
	 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
	 Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Hmotnost produktu a obalu. Hmotnost zabaleneho produktu je suctom obidvoch poloziek
struct Weight {
	int product; // hmotnost produktu
	int packing; // hmotnost balenia
};


//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada pole 'data'.
	Pouzije algoritmus bubble sort.
	Poradie usporiadania je od najvacsieho prvku po najmensi.

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[in] length - pocet prvkov pola

	VSTUPNA PODMIENKA:
		ak 'length' > 0, tak 'data' ukazuje na platne pole

	PRIKLADY:
		{1,3,2} -> {3, 2, 1}
		{} -> {}
*/
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void bubbleSort(int* data, const size_t length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (data[j] < data[j + 1]) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada pole 'data' podla celkovej hmotnosti zabaleneho tovaru, t.j. podla suctu poloziek (product a packing).
	Pouzije algoritmus bubble sort.
	Poradie usporiadania je od najvacsieho prvku po najmensi.

	Podmienka porovnania struktur:
	Pri porovnavani prvkov funkcia scita hodnoty product a packing oboch porovnavanych struktur.
	Struktury s vacsim suctom poloziek budu po usporiadani pred strukturami s mensim suctom poloziek.

	Vzajomne usporiadanie struktur s rovnakym suctom poloziek:
	Pri bodovom hodnoteni nezalezi na vzajomnom usporiadani struktur s rovnakym suctom poloziek (aj ked hodnoty poloziek mozu byt rozne).
	Lepsie je vsak implementovat stabilne triedenie (struktury s rovnakym suctom poloziek nemenia vzajomne usporiadanie).

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[in] length - pocet prvkov pola

	VSTUPNA PODMIENKA:
		ak 'length' > 0, tak 'data' ukazuje na platne pole

	PRIKLADY:
		{{10, 1}, {20, 2}, {5,2}} -> {{20, 2}, {10, 1},{5,2}} pretoze 20+2=22, 10+1=11, 5+2=7 a 22 > 11 > 7
		{} -> {}

	POZNAMKA:
		Priklady jednoducheho vytvorenia pola v testovacom kode:
		Weight baliky[] = {{10, 1}, {20, 2}, {5,2}};
		Weight baliky[] = {{.product = 10, .packing = 1}, {.product = 20, .packing = 2}, {.product = 5, .packing = 2}};
*/
void swap(Weight* a, Weight* b) {
	Weight tmp = *a;
	*a = *b;
	*b = tmp;
}


void bubbleSort(Weight* data, const size_t length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if ((data[j].packing + data[j].product) < (data[j+1].packing + data[j+1].product)) {
				swap(&data[j], &data[j + 1]);
			}
		}
	}

}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury
void generateArray(int* data, const int n) {
	for (int i = 0; i < n; i++) {
		data[i] = rand() % 200 - 100;
	}
}

void printArray(const int* data, const int n) {
	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}


int main() {
	//int data[10];
	//generateArray(data, 10);
	//printArray(data, 10);

	//bubbleSort(data, 10);
	//printArray(data, 10);

	Weight baliky[3] = {{baliky[1].product = 10,baliky[1].packing = 1}, {baliky[2].product = 20,baliky[2].packing = 2}, {baliky[3].product = 5,baliky[3].packing = 2}};

	return 0;
}