//Aufgabe Doppelt verkettete Liste

#include <iostream>


using namespace std;


struct DListElement {
	int inhalt;
	DListElement * next;
	DListElement * prev;
};

struct DList {
	DListElement * first;
	DListElement * last;
};

void initializeDList(DList& list) {
	list.first = 0;
	list.last = 0;
}

bool get(DList& liste, int& val) {
	if (liste.last) { // wenn ein wert existiert
		val = liste.last->inhalt; // in val den wert uebergeben
		liste.last = liste.last->prev; // Lettes element auf das vorherige setzen
		if (!liste.last) { //liste leer
			liste.first = 0; // dann den first pointer auch zum null-pointer machen
		}
		else {
			liste.last->next = 0; // Letzte element muss bei next einen null-pointer haben
		}
		return true;
	}
	return false;
}

void put(DList& liste, int val) {
	DListElement* neu = new DListElement;
	neu->inhalt = val;
	if (liste.first) {
		neu->next = liste.first;
		liste.first->prev = neu;
		neu->prev = 0;
	}
	else {
		liste.last = neu;
	}
	liste.first = neu;
}

bool isEmpty(DList& liste) {
	if (!liste.first && !liste.last) // wenn first pointer nicht null impliziert last pointer auch nicht null
		return true;
	else
		return false;
}


int main(int argc, char* argv[])
{
	DList queue;

	initializeDList(queue);

	//fuenf Werte einfuegen
	for (int i = 1; i <= 5; i++) {
		cout << "put: " << 10 * i << endl;
		put(queue, 10 * i);
	}

	//drei Werte entnehmen und ausgeben
	for (int j = 1; j <= 3; j++) {
		int value;
		if (get(queue, value))
			cout << "     get: " << value << endl;
	}

	// cout << "Laenge: " << dlistLength(queue) << endl;

	//nochmal 5 Werte einfuegen
	for (int i = 6; i <= 10; i++) {
		cout << "put: " << 10 * i << endl;
		put(queue, 10 * i);
	}

	// cout << "Laenge: " << dlistLength(queue) << endl;

	//alle Werte entnehmen und ausgeben
	while (!isEmpty(queue)) {
		int value;
		get(queue, value);
		cout << "     get: " << value << endl;
	}

	cin.sync(); cin.get();
	return 0;
}