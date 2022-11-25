#include "My_List.h"

ptrNODE find_place(ptrNODE begin, const Apartment& objApartment)
{
	ptrNODE p = begin;
	while (p && p->info.compare(objApartment) < 0)
		p = p->next;
	return p;
}

DLIST::DLIST(const char* file_name)
{
	std::ifstream file(file_name);
	Apartment apartment(file);
	first_node(apartment);
	ptrNODE place;
	while (!file.eof())
	{
		Apartment stud(file);
		place = find_place(begin, stud);
		if (place)
			add_before(place, stud);
		else
			add_after(end, stud);
	}
	file.close();
}

void DLIST::first_node(const Apartment& objApartment)
{
	begin = new NODE(objApartment);
	end = begin;
}

bool DLIST::empty()
{
	return begin == nullptr;
}

void DLIST::add_after(ptrNODE ptr, const Apartment& objApartment)
{
	ptrNODE p = new NODE(objApartment, ptr->next, ptr);
	if (ptr == end)
		end = p;
	else
		ptr->next->prev = p;
	ptr->next = p;
}

void DLIST::add_before(ptrNODE ptr, const Apartment& objApartment)
{
	ptrNODE p = new NODE(objApartment, ptr, ptr->prev);
	if (ptr == begin)
		begin = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::del_before(ptrNODE& ptr)
{
	if (ptr && ptr->prev)
	{
		if (ptr->prev == begin)
			begin = ptr;
		Delete(ptr->prev);
	}
}

void DLIST::del_after(ptrNODE& ptr)
{
	if (ptr && ptr->next)
	{
		if (ptr->next == end)
			end = ptr;
		Delete(ptr->next);
	}
}

void DLIST::print()
{
	ptrNODE ptr = begin;
	while (ptr)
	{
		ptr->info.print();
		ptr = ptr->next;
	}
}

Apartment& DLIST::Delete(ptrNODE& ptr)
{
	ptrNODE p = ptr;
	if (ptr == begin) // удаление из начала
	{
		begin = p->next;
		ptr = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
		if (ptr == end) //удаление из конца
		{
			end = p->prev;
			ptr = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else // удаление из середины
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	static Apartment stud;
	stud = p->info;
	delete p;
	return stud;
}

DLIST::~DLIST()
{
	while (!empty())
		Delete(begin);
}