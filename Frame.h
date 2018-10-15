//Frame.h
#pragma once

class Frame {
	string frameName;
protected:
	double fileSize;
	vector<Attribute> attributes;
public:
	Frame(string f, double size, vector<Attribute> d) :frameName(f), fileSize(size), attributes(d) {}
	virtual ~Frame() {}
	string& GetFrameName() { return frameName; }
	Attribute& operator[](int);
	int size() { return attributes.size(); }
	virtual void Compress() = 0;
	friend ostream& operator<<(ostream&, Frame&);
};