#include "Apartment.h"

Apartment::Apartment(std::ifstream& file)
{
	file >> numOfRooms >> floor;
	file >> square.generalSquare >> square.livingSquare;
	file >> numOfResidents;
	file >> address.street;
	file >> address.house >> address.apartment;
	file.ignore();
	std::string splitLine;
	std::getline(file, splitLine);
}

void Apartment::print()
{
	std::cout << numOfRooms << '\n' << floor << '\n';
	std::cout << square.generalSquare << '\n' << square.livingSquare << '\n';
	std::cout << numOfResidents << '\n';
	std::cout << address.street << '\n' << address.house << '\n' << address.apartment << '\n';
	std::cout << "--------------\n";
}

int Apartment::compare(const Apartment& objApartment)
{
	int result = 1;
	if (address.street < objApartment.address.street ||
		address.street == objApartment.address.street && address.house < objApartment.address.house ||
		address.street == objApartment.address.street && address.house == objApartment.address.house && address.apartment < objApartment.address.apartment)
		result = -1;
	else
		if (address.street == objApartment.address.street && address.house == objApartment.address.house && address.apartment == objApartment.address.apartment)
			result = 0;
	return result;
}

std::string Apartment::getStreet()
{
	return address.street;
}

int Apartment::getHouse()
{
	return address.house;
}
