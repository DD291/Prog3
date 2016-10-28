#include "Artikel.h"




Artikel::Artikel(int artikelnummer)
{
	this->artikelnummer = artikelnummer;
}


Artikel::~Artikel()
{
}

int Artikel::getArtikelnummer()
{
	return this->artikelnummer;
}

std::string & Artikel::getBezeichnung()
{
	return this->bezeichnung;
}


double & Artikel::getEinstandspreis()
{
	return this->einstandspreis;
}

int & Artikel::getBestelldauer()
{
	return this->bestelldauer;
}

