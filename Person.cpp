#include "Person.h"
#include"Capsule.h"

const int Person::num_of_role = NONE;

/*
name:Person
parameters:id, fullName
return value:this object
algorithm:call setters
*/
Person::Person(const char* id,const char* fullName, Role role)
{
	setId(id);
	setFullName(fullName);
	setRole(role);
}
/*
name:Person
parameters:role
return value:this object
algorithm:Enter ID number and name per person and call setter for fole 
*/
Person::Person(Role role)
{
	char tmpId[10], tmpName[100];
	cout << "enter id: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpId, 9);
	setId(tmpId);
	cout << "enter full name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpName, 100);
	setFullName(tmpName);
	setRole(role);
}
/*
name:Person
parameters:p
return value:this object
algorithm:Enter NULL in dynamic values and run operator =
*/
Person::Person(const Person& p)
{
	this->id = NULL;
	this->fullName =NULL;
	*this = p;
}

void Person::setRole(const Role& role)throw(char*)
{
	if (role > num_of_role || role < 0)throw"error:Invalid role";
	this->role = role;
}
/*
name:setId
parameters:id
return value:none
algorithm:check if is valid (only numbers)
if ok set data
else throw INVALID_ID
*/

void Person::setId(const char* id)throw(char*)
{
	
	for (int i = 0; i < strlen(id); i++)
	{
		if (id[i] < 48 || id[i]>57)throw"error:Non-digit characters";
	}
	if (id == NULL || !strcmp(id, ""))throw"error:Empty string or Null";
	

	this->id=_strdup(id);
}
/*
name:setFullName
parameters:full name
return value:none
algorithm:check if is valid
if ok set data
else throw INVALID_NAME
*/
void Person::setFullName(const char* fullName)throw(char*)
{
	for (int i=0; i < strlen(fullName); i++)
	{
		if (!(fullName[i] <= 90 && fullName[i] >= 65 || fullName[i] <= 122 && fullName[i] >= 97))throw"error:Name contains Digits";
	}
	if (fullName == NULL || !strcmp(fullName, ""))throw"error:Empty string or Null";
	
	this->fullName=_strdup(fullName);
}

/*
name:operator==
parameters: peson to compare
return value:true if equal
algorithm:compare between the person's ids
*/
bool Person::operator==(const Person& person) const
{
	return strcmp(this->id,person.id)==0;
}
/*
name:operator<
parameters:person to compare
return value:true if small
algorithm:compare between the person's ids and return if this < id
*/
bool Person::operator<(const Person& person) const
{
	return strcmp(this->id, person.id)<0;
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT equal AND NOT bigger then this (using De morgan laws)
*/
bool Person::operator>(const Person& person) const
{
	return !(*this<person || *this==person);
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT bigger then this
*/
bool Person::operator>=(const Person& person) const
{
	return !(*this<person);
}

const Person& Person::operator=(const Person& p)
{
	if (this != &p) 
	{
		this->id = _strdup(p.id);
		this->fullName = _strdup(p.fullName);
		this->role = p.role;
	}
	return *this;
}

Person::~Person()
{
	delete[]id;
	delete[]fullName;
}
/*
name:operator<<
parameters:output stream, person to display,
return value:output stream for continous
algorithm: display the person
*/
ostream& operator<<(ostream& out, const Person& p)
{
	out << left << setw(12) << setfill(' ') << "";
	out << left << setw(15) << setfill(' ') << p.id << " ";
	out << left << setw(22) << setfill(' ') << p.fullName << " ";
	out << left << setw(12) << setfill(' ') << (p.role == PASSENGER ? "" : p.role == PILOT ? "PILOT" : p.role == BARTENDER ? "BARTENDER" : "STEWARDESS" )<< " ";
	out << left << setw(12) << setfill(' ') << "";
	return out;
}


