#include "Bestand.h"



Bestand::Bestand(int artikelnummer)
{
	this->artikelnummer = artikelnummer;
}

Bestand::~Bestand()
{
}

int Bestand::getArtikelnummer()
{
	return this->artikelnummer;
}



int Bestand::getIstBestand()
{
	return this->istbestand;
}

int Bestand::getHoechstBestand()
{
	return this->hoechstbestand;
}

int Bestand::getVerbrauch()
{
	return this->verbrauch;
}

void Bestand::setVerbrauch(int & wert)
{
	this->verbrauch = wert;
}
