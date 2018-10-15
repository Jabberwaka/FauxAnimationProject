/**********************************************
/	Author					Tyler Brady
/	Student Number			040 852 457
/	Assignment Number		3
/	File Name				ImageFrame.cpp
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
#include "ImageFrame.h"




double const COLOURS[]{2, 4, 8, 16, 32, 64, 128, 256};

/*
Function name	Compress
Purpose:		Outputs the compression information

In Parameters
Out parameters
Version			1.0
Author			Tyler BRady
*/
void ImageFrame::Compress()
{
	cout << "Name = " << GetFrameName() << endl
		<< "Lempel-Ziv-Welch Lossless Compression" << endl <<
		"----------------------------------------------------------------------------------" << endl <<
		"colours:\t | " << COLOURS[0] << "\t  | " << COLOURS[1] <<
		"\t  | " << COLOURS[2] << "\t  | " << COLOURS[3] << "\t  | " << COLOURS[4] <<
		"\t  | " << COLOURS[5] << "\t  | " << COLOURS[6] << "\t  | " << COLOURS[7] << endl <<
		"----------------------------------------------------------------------------------" << endl


		<< "file size (MB) : | " << setprecision(4) << fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[0]) << " | "
		<< fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[1]) << " | " << fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[2]) << " | "
		<< fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[3]) << " | " << fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[4]) << " | "
		<< fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[5]) << " | " << fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[6]) << " | "
		<< fileSize / (COMPRESSION_RATIO*BITDEPTH_FACTOR[7]) << endl <<
		"----------------------------------------------------------------------------------" << endl;

}

/*
Function name	operator<<
Purpose:		Overloading << operator to output the frameName and the attributes

In Parameters	ostream&, ImageFrame&
Out parameters	ostream&
Version			1.1
Author			Tyler BRady
*/
ostream & operator<<(ostream & os, ImageFrame & iframe)
{
	os << "ImageFrame" << endl << "Name = " << iframe.GetFrameName() << endl; 
	for (int i = 0; i < iframe.size(); ++i) {
		os << "\t\tResolution #" << i << ": " << iframe[i];
	}
	return os;
}
