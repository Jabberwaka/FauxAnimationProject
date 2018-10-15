/**********************************************
/	Author					Tyler Brady
/	Student Number			040 852 457
/	Assignment Number		3
/	File Name				Frame.cpp
/	CST8219_300				C++
/	Lab Section				303
/	Professor				Andrew Tyler
/	Assignment Due			Apr 21st 2018
/	Assignment Submitted	Apr 21st 2018
/	Purpose					This file is an update of assignment #2, this time including polymorphism.
/
/	Functions				operator[](int)
/							operator<<(ostream&, Frame&)
************************************************/

using namespace std;

#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include "Attribute.h"
#include "Frame.h"



/*
Function name	operator[]
Purpose:		Overloading [] operator to output the display object at the given index in the vector<Display>

In Parameters	int 
Out parameters	Attribute&
Version			1.1
Author			Tyler Brady
*/
Attribute & Frame::operator[](int i)
{
	return attributes.at(i);
}

/*
Function name	operator<<
Purpose:		Overloading << operator to output the frameName of the Frame object

In Parameters	ostream&, Frame&
Out parameters	ostream&
Version			1.1
Author			Tyler BRady
*/
ostream & operator<<(ostream &os, Frame &f)
{
	os << f.fileSize;
	return os;
}
