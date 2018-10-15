//Attribute.h
#pragma once

class Attribute
{
	char* attributeString;
public:
	Attribute(char*);
	Attribute(const Attribute&);
	Attribute& operator=(Attribute&);
	~Attribute();
	friend ostream& operator<<(ostream&, Attribute&);
};
