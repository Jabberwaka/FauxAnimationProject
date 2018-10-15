//ImageFrame.h
#pragma once

class ImageFrame :public Frame {
	static const int BITS = 8;
	static constexpr double COMPRESSION_RATIO = 6.0;
	static constexpr double BITDEPTH_FACTOR[]{ 11.1,4.6,3.5,2.4,1.9,1.5,1.2,1.0 };
public:
	ImageFrame(string fileName, double fileSize, vector<Attribute> d) :Frame(fileName, fileSize, d) {}
	~ImageFrame() {}
	void Compress();
	friend ostream& operator<<(ostream&, ImageFrame&);
};