/**********************************************
/	Author					Tyler Brady
/	Student Number			040 852 457
/	Assignment Number		2
/	File Name				Animation.cpp
/	CST8219_300				C++
/	Lab Section				303
/	Professor				Andrew Tyler
/	Assignment Due			Mar 24th 2018
/	Assignment Submitted	Mar 24th 2018
/	Purpose					This file is an update of assignment #2, this time including overloaded operators and sequential containers.
/
/	Functions				~Animation()
/							InsertFrame()
/							EditFrame()
/							DeleteFrames()
/							RunFrames()
/							operator<<(ostream&, Animation&)
************************************************/

using namespace std;

#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include "Attribute.h"
#include "Frame.h"
#include "AudioFrame.h"
#include "ImageFrame.h"
#include "Animation.h"

/*
Function name	InsertFrame
Purpose:		Inserts a frame into the animation.

In Parameters	none
Out parameters	void
Version			1.3
Author			Tyler BRady
*/
void Animation::InsertFrame()
{

	char* frameName = new(char[64]);

	cout << "Insert a frame into the animation" << endl << "Please enter the frame name: ";
	cin >> frameName;
	deque<Frame*>::iterator it = frames.begin();

	//check wether the frame is already within the animation
	for (int iterator = 0; iterator < frames.size(); ++iterator) {
		//if they are the same, we exit
		string frame;
		frame = frameName;
		Frame* f = frames.at(iterator);
		if (frame == f->GetFrameName()) {
			cout << "Frame already located within animation" << endl;
			delete frameName;
			return;
		}
	}

	double size;
	cout << "Please enter the file size in MB: ";
	cin >> size;

	int choice;
	cout << "What type of Frame is it? Audio Frame (1) or GIF Image Frame (2)? ";
	cin >> choice;
	if (choice == 1) {	//audio frame
		int freq;

		cout << "How many frequency ranges are associated with this audio frame? ";
		cin >> freq;
		vector<Attribute> v_atr;

		for (int i = 0; i < freq; ++i) {
			char range[20];
			cout << "Please enter the next frequency range: ";
			cin >> range;
			Attribute atr(range);
			v_atr.push_back(atr);
		}

		AudioFrame *audio;
		audio = new AudioFrame(frameName, size, v_atr);

		delete frameName;

		if (frames.size() == 0) {
			cout << "This is the first Frame in the deque";
			frames.push_back(audio);
		}
		else {
			int choice = -1;
			cout << "there are " << frames.size() << " frame(s) in the deque" << endl
				<< "which index position would you like to insert at? 0 or " << frames.size() << "? ";
			while (choice != 0 && choice != frames.size()) {		//loops to error check choice
				cin >> choice;
			}
			if (choice == 0) {
				frames.push_front(audio);
			}
			else {
				frames.push_back(audio);
			}
		}
		cout << endl;

	}
	else { //image frame
		int screens;
		vector<Attribute>d;
		cout << "How many screen resolutions are associated with this GIF image Frame? ";
		cin >> screens;
		for (int i = 0; i < screens; ++i) {
			char range[20];
			cout << "Please enter the next screen resolution: ";
			cin >> range;
			Attribute a(range);
			d.push_back(a);
		}
		ImageFrame* image;
		image = new ImageFrame(frameName, size, d);

		delete frameName;


		if (frames.size() == 0) {
			cout << "This is the first Frame in the deque";
			frames.push_back(image);
		}
		else {
			int choice = -1;
			cout << "there are " << frames.size() << " frame(s) in the deque" << endl
				<< "which index position would you like to insert at? 0 or " << frames.size() << "? ";
			while (choice != 0 && choice != frames.size()) {		//loops to error check choice
				cin >> choice;
			}
			if (choice == 0) {
				frames.push_front(image);
			}
			else {
				frames.push_back(image);
			}
		}
		cout << endl;
	}
}

/*
Function name	EditFrame
Purpose:		Edits a given frame

In Parameters	none
Out parameters	void
Version			1.3
Author			Tyler BRady
*/
void Animation::EditFrame()
{
	if (frames.size() == 0) {
		cout << "The animation is empty, no frames to edit" << endl;
		return;
	}

	//find if the frame exists
	char* name = new (char[20]);
	cout << "Please enter the name of the frame to edit: ";
	cin >> name;
	cout << endl;

	//check wether the frame is already within the animation
	for (int iterator = 0; iterator < frames.size(); ++iterator) {
		//if they are the same, we exit
		string frame;
		frame = name;
		Frame* f = frames.at(iterator);
		if (frame == f->GetFrameName()) {	//found the frame
			int choice;
			cout << "Found at index " << iterator << endl;
			cout << "MENU" << endl << " 1. Edit the frameName" << endl << " 2. Edit an attribute ";
			cin >> choice;
			if (choice == 1) { //frame name edit
				char newName[20];
				cout << "Please enter the new name";
				cin >> newName;

				for (int iter = 0; iter < frames.size(); ++iter) {	//check for duplicate name
					//if they are the same, we exit
					string framee;
					framee = newName;
					Frame* ff = frames.at(iter);
					if (framee == ff->GetFrameName()) {	//found the frame
						//frame already named, cant do that
						cout << "There is already a frame with that name" << endl;
						return;
					}
				}

				vector<Attribute>newVector;
				for (int it = 0; it < frames[iterator]->size(); ++it) {	//loop through and access members of attributes vector
					cout << frames[iterator][0][it] << endl;
					newVector.push_back(frames[iterator][0][it]);
				}
				
				AudioFrame* afp = dynamic_cast<AudioFrame*>(frames[iterator]);
				if (afp != NULL){ //if is an audioframe
					cout << "should be here?";
					double filesize;
					stringstream fsize;
					fsize << (frames[iterator][0]);
					filesize = stod(fsize.str());
					AudioFrame* afprime;
					afprime = new AudioFrame(newName, filesize, newVector);
					std::deque<Frame*>::iterator it = frames.begin();		//iterator
					delete frames[iterator];
					it = frames.begin();									//need to re-assign iterator
					frames.erase(it + iterator);							//delete old frame
					it = frames.begin();									//need to re-assign iterator
					frames.insert(it + iterator, afprime);					//inserts into deque
					delete name;
					return;

				}
				else { //else is an image frame
					double filesize;
					stringstream fsize;
					fsize << (frames[iterator][0]);
					filesize = stod(fsize.str());

					ImageFrame* ifprime;
					ifprime = new ImageFrame(newName, filesize, newVector);

					std::deque<Frame*>::iterator it = frames.begin();		//iterator
					delete frames.at(iterator);
					it = frames.begin();									//need to re-assign iterator
					frames.erase(it + iterator);							//delete old frame
					it = frames.begin();									//need to re-assign iterator
					frames.insert(it + iterator, ifprime);					//inserts into deque
					delete name;
					return;
				}
				

			}
			else { //attribute edit
				int aIndex;
				char attr[20];
				string oldname = frames[iterator]->GetFrameName();

				cout << "maxAttributeIndex = " << frames[iterator]->size()-1 << endl
				<< "What is the attribute index to modify? ";

				cin >> aIndex;
				cout << "Please give the new attribute value" << endl;
				cin >> attr;

				Attribute attribute(attr);

				vector<Attribute>newVector;
				for (int it = 0; it < frames[iterator]->size(); ++it) {	//loop through and access members of attributes vector
					if (it != aIndex) {
						newVector.push_back(frames[iterator][0][it]);
					}
					else {
						newVector.push_back(attribute);
					}
				}

				AudioFrame* afp = dynamic_cast<AudioFrame*>(frames[iterator]);
				if (afp != NULL) { //if is an audioframe
					cout << "should be here?";
					double filesize;
					stringstream fsize;
					fsize << (frames[iterator][0]);
					filesize = stod(fsize.str());
					AudioFrame* afprime;
					afprime = new AudioFrame(oldname, filesize, newVector);
					std::deque<Frame*>::iterator it = frames.begin();		//iterator
					delete frames[iterator];
					it = frames.begin();									//need to re-assign iterator
					frames.erase(it + iterator);							//delete old frame
					it = frames.begin();									//need to re-assign iterator
					frames.insert(it + iterator, afprime);					//inserts into deque
					delete name;
					return;

				}
				else { //else is an image frame
					double filesize;
					stringstream fsize;
					fsize << (frames[iterator][0]);
					filesize = stod(fsize.str());

					ImageFrame* ifprime;
					ifprime = new ImageFrame(oldname, filesize, newVector);

					std::deque<Frame*>::iterator it = frames.begin();		//iterator
					delete frames.at(iterator);
					it = frames.begin();									//need to re-assign iterator
					frames.erase(it + iterator);							//delete old frame
					it = frames.begin();									//need to re-assign iterator
					frames.insert(it + iterator, ifprime);					//inserts into deque
					delete name;
					return;
				}


			}


		}
	}

	cout << "Frame was not found" << endl;
	delete name;
	return;
}

/*
Function name	DeleteFrames
Purpose:		Clears the frames from the deque

In Parameters	none
Out parameters	void
Version			1.3
Author			Tyler BRady
*/
void Animation::DeleteFrames()
{
	int s = frames.size();
	for (int i = 0; i < s; ++i) {
		delete frames[i];
	}
	frames.clear();
	return;
}


/*
Function name	RunFrames
Purpose:		Functions as a means to call the overloaded operator that will output the information in the animation.

In Parameters	none
Out parameters	void
Version			1.3
Author			Tyler BRady
*/
void Animation::RunFrames()
{
	cout << animationName << endl << "Run the Animation" << endl << "Animation name is " << animationName << this << endl;
}

/*
Function name	~Animation
Purpose:		destructor

In Parameters	none
Out parameters	none
Version			1.3
Author			Tyler Brady
*/
Animation::~Animation()
{
	int s = frames.size();
	for (int i = 0; i < s; ++i) {
		delete frames[i];
	}
	frames.clear();
}

/*
Function name	operator<<
Purpose:		Handles most of what was originally done in the run function.


In Parameters	ostream&, Animation&
Out parameters	ostream
Version			1.1
Author			Tyler Brady
*/
ostream & operator<<(ostream &os, Animation &anime)
{

	unsigned int counter = 0;
	time_t startsec, oldsec, newsec;

	startsec = oldsec = time(NULL);

	while (counter<(anime.frames.size()))
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			cout << "Frame #" << counter << ", time = " << newsec - startsec << " sec" << endl;
			AudioFrame* afp = dynamic_cast<AudioFrame*>(anime.frames[counter]);
			if (afp != NULL) {
				cout << *afp;
			}
			else {
				ImageFrame* ifp = dynamic_cast<ImageFrame*>(anime.frames[counter]);
				cout << *ifp;
			}
			cout << endl;
			++counter;
			oldsec = newsec;
		}
	}

	return os;
}
