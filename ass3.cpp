// ass3.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include <crtdbg.h>
#include <time.h>
#include <string.h>
#include <iostream>

#include "Attribute.h"
#include "Frame.h"
#include "AudioFrame.h"
#include "ImageFrame.h"
#include "Animation.h"

int main(void)
{
	char response;
	bool RUNNING = true;
	Animation A("Animation#1");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (RUNNING)
	{
		cout << "MENU\n 1. Insert a Frame\n 2. Edit a Frame\n 3. Delete all the Frames\n 4. Frame Compression Report\n 5. Run the Animation\n 6. Quit\n";
		cin >> response;
		switch (response)
		{
		case '1':A.InsertFrame(); break;
		case '2':A.EditFrame(); break;
		case '3':A.DeleteFrames(); break;
		case '4':A.CompressReport(); break;
		case '5': cout << A; break;
		case '6':RUNNING = false; break;
		default:cout << "Please enter a valid option" << endl;
		}
	}
	return 0;
}