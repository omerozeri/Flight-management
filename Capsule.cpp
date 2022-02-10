#include "Capsule.h"

void Capsule::set_capacity(unsigned int capacity) throw(char*)
{
	if (capacity == 0)throw"error:Invalide capacity";
	this->capacity = capacity;
}



void Capsule::set_price(unsigned int price) throw(char*)
{
	if (price == 0)throw"eror:Invalid pricen";
	this->price = price;
}


Capsule::Capsule(int capacity, int price)
{
	num_of_tickets = 0;
	arr_Ticket = NULL;
	set_capacity(capacity);
	set_price(price);
}

Capsule::Capsule(const Capsule& capsule):arr_Ticket(NULL)
{
	*this = capsule;

}



Capsule Capsule::operator+=(AirlineTicket* Ticket) throw(char*)
{
	if (Isfull())throw"error:capacity is full";

	for (int i = 0; i < num_of_tickets; i++)
	{
		if (arr_Ticket[i] == Ticket)throw"error:An airline ticket is available";
	}
	AirlineTicket** newarr = new AirlineTicket * [num_of_tickets+1];
	if (IsEmpty())
	{
		
		arr_Ticket = newarr;
		arr_Ticket[num_of_tickets] = Ticket;
		num_of_tickets++;
		return *this;
	}
	for (int i = 0; i < num_of_tickets ; i++)
	{
		newarr[i] = arr_Ticket[i];
	}
	newarr[num_of_tickets] = Ticket;
	num_of_tickets++;
	delete[] arr_Ticket;
	arr_Ticket = newarr;
	return *this;

}

Capsule Capsule::operator-=(AirlineTicket* Ticket) throw(char*)
{
	bool isExist = false;
	if (IsEmpty())throw"error:Empty capsule card does not exsist";
	for (int i = 0; i < num_of_tickets; i++)
		if (arr_Ticket[i] == Ticket)isExist = true;
	if (!isExist)throw"error:Order does not exist";
	AirlineTicket** newarr = new AirlineTicket * [num_of_tickets-1];
	for (int j = 0, i = 0; i < num_of_tickets; i++)
	{
		if (arr_Ticket[i] == Ticket) {
			delete arr_Ticket[i]; continue;
		}
		newarr[j++] = arr_Ticket[i];
	}
	
	
	delete[] arr_Ticket;
	arr_Ticket = newarr;
	num_of_tickets--;
	return *this;
	
}

Capsule& Capsule::operator=(const Capsule& other)
{
	if (this != &other)
	{
		delete[] arr_Ticket;
		this->arr_Ticket = new AirlineTicket*[other.num_of_tickets];
		for (int i = 0; i < other.num_of_tickets; i++)
		{
			this->arr_Ticket[i] = new AirlineTicket(*other.arr_Ticket[i]);
		}
		this->capacity = other.capacity;
		this->price = other.price;
		this->num_of_tickets = other.num_of_tickets;
	}
	return *this;
}

Capsule::~Capsule()
{
	
		
		delete[] arr_Ticket;
	
	
}








ostream& operator<<(ostream& out, const Capsule& capsule)
{
	out << endl;
	out << left << setw(22) << setfill(' ') << "capacity";
	out << left << setw(12) << setfill(' ') << "price";
	out << left << setw(22) << setfill(' ') << "number of Tickets "<<endl<<endl;
	out << left << setw(120) << setfill('_') << "" << endl << endl;

	out << left << setw(23) << setfill(' ') << capsule.price;
	out << left << setw(12) << setfill(' ') << capsule.capacity;
	out << left << setw(24) << setfill(' ') << capsule.num_of_tickets<<endl<<endl;
	out << left << setw(12) << setfill(' ') << "Ticket:";
	out << left << setw(15) << setfill(' ') << "passanger ID";
	out << left << setw(34) << setfill(' ') << "passanger Name";
	out << left << setw(26) << setfill(' ') << "Ticket no";
	out << left << setw(10) << setfill(' ') << "Meal";
	out << left << setw(22) << setfill(' ') << "Type of Ticket " << endl;
	out << left << setw(120) << setfill('_') << "" << endl << endl;
	out << left << setw(93) << setfill(' ') << ""<<endl;
	for(int i=0;i<capsule.num_of_tickets;i++)
	{
		out << *capsule.arr_Ticket[i];
		
	}
	return out;
}
