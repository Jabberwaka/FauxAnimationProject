/**********************************************
/	Author					Tyler Brady
/	Student Number			040 852 457
/	Assignment Number		3
/	File Name				Attribute.cpp
/	CST8219_300				C++
/	Lab Section				303
/	Professor				Andrew Tyler
/	Assignment Due			Apr 21st 2018
/	Assignment Submitted	Apr 21st 2018
/	Purpose					This file is an update of assignment #2. A new method of holding information about a frame.
/
/	Functions				Attribute(char *)
/							Attribute(const Attribute &)
/							Attribute& operator=(Attribute &attr)
/							~Attribute
/							operator<<(ostream&, Frame&)
************************************************/

using namespace std;
#include <iostream>
#include "Attribute.h"

#pragma warning(disable: 4996)

/*
Function name	Attribute
Purpose:		Constructor

In Parameters	char*
Out parameters	none
Version			1.0
Author			Tyler BRady
*/
Attribute::Attribute(char * name)
{
	delete attributeString;
	attributeString = new char[20];
	strcpy(attributeString, name);
}

/*
Function name	Attribute
Purpose:		Copy construcor

In Parameters	const Attribute&
Out parameters	none
Version			1.0
Author			Tyler BRady
*/
Attribute::Attribute(const Attribute &attr)
{
	attributeString = new char[20];
	strcpy(attributeString, attr.attributeString);
}

/*
Function name	operator=
Purpose:		Overloads the assignment operator, when making an Attribute equal to another Attribute.
				It copies the Attributes&'s string into this's string

In Parameters	Display&
Out parameters	Display&
Version			1.0
Author			Tyler BRady
*/
Attribute& Attribute::operator=(Attribute &attr)
{
	strcpy(attributeString, attr.attributeString);
	return *this;
}

/*
Function name	~Attribute
Purpose:		destructor

In Parameters	none
Out parameters	none
Version			1.0
Author			Tyler BRady
*/
Attribute::~Attribute()
{
	delete attributeString;
}

/*
Function name	operator<<
Purpose:		Overloads the output operator to output the attribute information

In Parameters	ostream&, Attribute&
Out parameters	ostream&
Version			1.0
Author			Tyler Brady
*/
ostream& operator<<(ostream& os, Attribute &attr)
	{
		os << attr.attributeString << endl;
		return os;
}

