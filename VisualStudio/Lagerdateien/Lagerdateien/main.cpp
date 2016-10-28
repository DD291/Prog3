#include "Artikel.h"
#include "Bestand.h"
#include <iostream>
#include <vector>

Artikel& searchForArtikelnummer(std::vector<Artikel>& artikel, int artikelnummer) {
	for (int i = 0; i < artikel.size(); i++){
		if (artikel[i].getArtikelnummer == artikelnummer)
			return artikel[i];
	}
}

int main() {
	std::vector<Artikel> artikel = {
		Artikel(100),
		Artikel(101),
		Artikel(102),
		Artikel(103),
		Artikel(104)
	};
	artikel[0].getBezeichnung = "";
	artikel[0].getEinstandspreis = 350.00;
	artikel[0].getBestelldauer = 7;

}