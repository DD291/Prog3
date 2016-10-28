//Aufg_2_2.cpp: Rekursive Datentypen, einfach verkettete Liste
#include <iostream>
#include "Liste.h"
using namespace std;

struct ListElement {
	double inhalt;
	ListElement * next;
};
typedef ListElement * List;
const List EMPTYLIST = 0;

void insertLast(List& lst, double info) {
	ListElement * neuPointer = new ListElement;
	neuPointer->inhalt = info;
	neuPointer->next = 0;
	if (!lst) { // Wenn pointer auf erstes Element NULL 
		lst = neuPointer; // dann erstes Element erstellen
	}
	else { // Ansonsten
		ListElement * element = lst; // Anfang zwischenspeichern
		while (element->next) { //Liste entlang Hangeln
			element = element->next;
		}
		element->next = neuPointer; // und Letztes Element anhaengen
	}
}

void printList(List& lst) {
	ListElement element = *lst;
	std::cout << "[" << "Position" << ", " << "Inhalt" << ", " << "Adresse"<< "]" << std::endl;
	int pos = 0;
	while (element.next) {
		std::cout << "[" << pos << ", "<< element.inhalt << ", " << &element << "]" << std::endl;
		element = *element.next;
	}
}

void reverseList(List& lst) {
	
}


int main()
//-----------------------------------------------------------
//Testaufrufe fuer insertLast(), printList() und reverseList()
//-----------------------------------------------------------
{
	//Liste mit den Werten 1 bis 10 aufbauen
	List liste1 = EMPTYLIST;
	for (int wert = 1; wert <= 10; wert++)
	{
		//insertElem( liste1, wert ); 
		insertLast(liste1, wert);
	}

	//Inhalt der Liste ausgeben
	printList(liste1);  //sollte Reihenfolge 1 2 3 ... 10 ausgeben

						//Liste umdrehen
	reverseList(liste1);

	//Inhalt der Liste ausgeben
	printList(liste1);  //sollte Reihenfolge 10 9 8 ... 1 ausgeben

	cin.sync(); cin.get();
}
