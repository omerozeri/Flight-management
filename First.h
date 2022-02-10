#pragma once
#include "Capsule.h"
class First :public Capsule
{
	bool Realining_chair, Entertaiment;
	Person* mozeg;
public:
	First(const First& first);
	First(const Person& person, int capacity, int price, bool Realining_chair = false, bool Entertaiment = false);
	bool get_Realining_chair()const { return Realining_chair;}
	bool get_Entertaiment()const { return Entertaiment;}
	Person* get_BARTENDER()const { return mozeg;}
	void set_mozeg(const Person& person)throw(char*);
	void set_Realining_chair(bool Realining_chair);
	void set_Entertaiment(bool Entertaiment);
	friend ostream& operator<<(ostream& out, const First& first);
	const First& operator=(const First& other);
	
};

