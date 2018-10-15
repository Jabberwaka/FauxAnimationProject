/**********************************************
/	Author					Tyler Brady
/	Student Number			040 852 457
/	Assignment Number		3
/	File Name				AudioFrame.cpp
/	CST8219_300				C++
/	Lab Section				303
/	Professor				Andrew Tyler
/	Assignment Due			Apr 21st 2018
/	Assignment Submitted	Apr 21st 2018
/	Purpose					This file is an update of assignment #2, this time including polymorphism.
/
/	Functions				Compress()
/							operator<<(ostream&, Frame&)
************************************************/

using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Attribute.h"
#include "Frame.h"
#include "AudioFrame.h"



/*
Function name	Compress
Purpose:		Outputs the compression information

In Parameters	
Out parameters	
Version			1.0
Author			Tyler BRady
*/
void AudioFrame::Compress()
{
	cout << "Name = " << GetFrameName() << endl
		<< "MP3 Lossy Compression" << endl
		<< "-----------------------------------------------------------" << endl <<
		"bitrate (kbits/s) :\t| " << BITRATE[0] << "\t  | " << BITRATE[1] <<
		"\t    | " << BITRATE[2] << endl
		<< "-----------------------------------------------------------" << endl <<
		"file size (MB) :\t| " << setprecision(3) << fileSize / COMPRESSION_RATIO[0]
		<< "  | " << fileSize / COMPRESSION_RATIO[1] << "  | " << fileSize / COMPRESSION_RATIO[2] << endl
		<< "-----------------------------------------------------------" << endl;
}

/*
Function name	operator<<
Purpose:		Overloading << operator to output the frameName and the attributes

In Parameters	ostream&, AudioFrame&
Out parameters	ostream&
Version			1.0
Author			Tyler BRady
*/
ostream& operator<<(ostream& os, AudioFrame& af) {
	os << "AudioFrame" << endl << "Name = " << af.GetFrameName() << endl;
	for (int i = 0; i < af.size(); ++i) {
		os << "\t\tResolution #" << i << ": " << af[i];
	}
	return os;
}
