#pragma once
#include"AirlineTicket.h"

#include<iostream>
using namespace::std;
class Capsule
{

	int price, capacity, num_of_tickets;
	AirlineTicket** arr_Ticket;
	void set_capacity(unsigned int capacity)throw(char*);

	
public:
	Capsule(int capacity = 0, int price = 0);
	Capsule(const Capsule& capsule);	
	int get_price()const { return price; }
	int get_ticket_num()const { return num_of_tickets; }
	int get_capacity()const { return capacity; }
	AirlineTicket** getTickets()const { return arr_Ticket; }
	void set_price(unsigned int price)throw(char*);
	bool Isfull() { return capacity == num_of_tickets; }
	bool IsEmpty() { return num_of_tickets == 0; }
	Capsule operator+=(AirlineTicket* Ticket)throw(char*);
	Capsule operator-=(AirlineTicket* Ticket)throw(char*);
	Capsule& operator =(const Capsule& other);
	friend ostream& operator<<(ostream& out, const Capsule& capsule);
	operator int()const { return capacity - num_of_tickets; }
	
	
	~Capsule();
};

