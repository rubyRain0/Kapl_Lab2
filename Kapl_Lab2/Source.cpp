#include "My_List.h"
#include <Windows.h>

void task(DLIST& DL)
{
	ptrNODE ptr = DL.get_begin();
	std::string targetStreet;
	int targetHouse;
	std::cout << "Enter street: \n";
	std::cin >> targetStreet;
	std::cout << "Enter house: \n";
	std::cin >> targetHouse;
	while (ptr && (ptr->info.getStreet() <= targetStreet ||  ( ptr->info.getStreet() == targetStreet && ptr->info.getHouse() <= targetHouse ) ))
	{
		if (ptr->info.getStreet() == targetStreet && ptr->info.getHouse() == targetHouse)
		{
			DL.Delete(ptr);
		}
		else ptr = ptr->next;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream file("apartments.txt");
	if (file)
	{
		DLIST DL("apartments.txt");
		DL.print();
		task(DL);
		std::cout << "List after task: \n";
		DL.print();
	}
	std::cin.get();
}