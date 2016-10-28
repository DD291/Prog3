//Aufg_2_2.cpp: Rekursive Datentypen, einfach verkettete Liste
#include <iostream>
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
	ListElement * element = lst;
	std::cout << "[" << "Position" << ", " << "Inhalt" << ", " << "Adresse"<< "]" << std::endl;
	int pos = 0;
	while (element->next) { // so lange es einen naechsten gibt
		std::cout << "[" << pos << ", "<< element->inhalt << ", " << element << "]" << std::endl; // gib ihn aus
		element = element->next;
	}
	std::cout << "[" << pos << ", " << element->inhalt << ", " << element << "]" << std::endl; // Letzte Zeile hat keinen naechsten muss aber auch ausgegeben werden
}

void recReverse(List& lst, ListElement* anfang,ListElement* element) {
	if (!element->next)//wenn am ende der Liste
	{
		lst = element; // Letztes Element als Start Festlegen
	}
	else   {
		recReverse(lst,anfang, element->next); // Ansonsten weiter die Liste entlang gehen
		element->next->next = element; // und das .next des folgenden elementes auf das aktuelle element setzen
	}
	if (element == anfang) {
		element->next = 0;
	}
}

void reverseList(List& lst) {
	if (lst) { //Liste darf nicht NULL sein
		recReverse(lst, lst , lst);
	}
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
