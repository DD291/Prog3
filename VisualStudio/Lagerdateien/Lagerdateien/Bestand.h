#pragma once
class Bestand
{
public:
	Bestand(int artikelnummer);
	~Bestand();
	int getArtikelnummer();
	int& getIstBestand();
	int& getHoechstBestand();
	int& getVerbrauch();
private:
	int artikelnummer;
	int istbestand;
	int hoechstbestand;
	int verbrauch;
};

