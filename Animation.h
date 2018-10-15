//Animation.h
#pragma once

class Animation {
	string animationName;
	deque<Frame*> frames;
public:
	Animation(string name) :animationName(name) {}
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrames();
	void CompressReport()
	{
		for (int i = 0; i < frames.size(); i++)
			frames[i]->Compress();
	}
	void RunFrames();
	friend ostream& operator<<(ostream&, Animation&);
};
