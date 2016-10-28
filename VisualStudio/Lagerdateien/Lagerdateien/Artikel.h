#include <string>
#pragma once
class Artikel
{
public:
	Artikel(int artikelnummer);
	~Artikel();
	int getArtikelnummer();
	std::string& getBezeichnung();
	double& getEinstandspreis();
	int& getBestelldauer();

private:
	int artikelnummer;
	std::string bezeichnung;
	double einstandspreis;
	int bestelldauer;
};

