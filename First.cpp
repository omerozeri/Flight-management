#include "First.h"

First::First(const First& first):Capsule(first)
{
	*this = first;
}


First::First(const Person& person, int capacity, int price, bool Realining_chair, bool Entertaiment):Capsule(capacity,price)
{
	set_mozeg(person);
	set_Realining_chair(Realining_chair);
	set_Entertaiment(Entertaiment);
}

void First::set_mozeg(const Person& person) throw(char*)
{
	if (person.getRole() != Role::BARTENDER)throw"BARTENDER Required";
	mozeg =new Person(person);
}

void First::set_Realining_chair(bool Realining_chair)
{
	this->Realining_chair = Realining_chair;
}

void First::set_Entertaiment(bool Entertaiment)
{
	this->Entertaiment = Entertaiment;
}

const First& First::operator=(const First& other)
{
	if (this != &other) {
		this->Entertaiment = other.Entertaiment;
		this->Realining_chair = other.Realining_chair;
		this->mozeg = new Person(*other.mozeg);
	}
	return *this;
}



ostream& operator<<(ostream& out, const First& first)
{
	out << left << setw(25) << setfill(' ') << "Capsule first class:"<<endl;
	const Capsule& capsule = first;
	const Person& mozeg = *first.mozeg;
	out << left << setw(22) << setfill(' ') << "Entertaiment";
	out << left << setw(34) << setfill(' ') << "Realining_chair";
	out << left << setw(12) << setfill(' ') << "mozeg ID";
	out << left << setw(28) << setfill(' ') << "Full Name";
	out << left << setw(12) << setfill(' ') << "Role"<<endl;
	out << left << setw(120) << setfill('_') << "" << endl << endl;

	out << left << setw(22) << setfill(' ') << (first.Entertaiment?"True":"False");
	out << left << setw(22) << setfill(' ') << (first.Realining_chair ? "True" : "False");
		out << left << setw(22) << setfill(' ') << mozeg << endl;
	out << capsule;
	out << left << setw(93) << setfill(' ') << "" << endl << endl;
	return out;
}
