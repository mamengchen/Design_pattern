#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class FrameApi {
public:
	virtual void draw() = 0;
protected:
	FrameApi() {}
};

class LayoutApi {
	//分率的布局器
public:
	virtual void installFrame() = 0;
protected:
	LayoutApi() {}
};

//pc上的Frame
class ComputerFrame : public FrameApi {
public:
	ComputerFrame(int pins)
		:m_pins(pins)
	{}

	void draw()
	{
		cout << "现在是pc机的Frame，我适用的分辨率是：" << m_pins << endl;
	}
private:
	int m_pins;	//分辨率
};

//Moblie的Frame
class MoblieFrame : public FrameApi {
public:
	MoblieFrame(int pins)
		:m_pins(pins)
	{}

	void draw()
	{
		cout << "现在是Moblie的Frame，我适用的分辨率是：" << m_pins << endl;
	}
private:
	int m_pins;	//分辨率
};

//高分辨lv的布局
class HighLayout :public LayoutApi {
public:
	HighLayout(int FrameAdpaterPins)
		:m_FrameAdpaterPins(FrameAdpaterPins)
	{}

	void installFrame()
	{
		cout << "现在是在PC环境下，我们使用的高分辨率布局" << m_FrameAdpaterPins <<endl;
	}
private:
	int m_FrameAdpaterPins;
};

//低分辨lv的布局
class LowLayout :public LayoutApi {
public:
	LowLayout(int FrameAdpaterPins)
		:m_FrameAdpaterPins(FrameAdpaterPins)
	{}

	void installFrame()
	{
		cout << "现在是在PC环境下，我们使用的低分辨率布局" << m_FrameAdpaterPins << endl;
	}
private:
	int m_FrameAdpaterPins;
};

//创建产品的简单工厂
class FrameFactory {
public:
	static FrameApi* createFrame(int type)
	{
		if (type == 1)
			return new ComputerFrame(1024);
		if (type == 2)
			return new MoblieFrame(800);
		return nullptr;
	}
};

class LayoutFactory {
public:
	static LayoutApi* createLayout(int type)
	{
		if (type == 1)
			return new HighLayout(1024);
		if (type == 2)
			return new LowLayout(800);
		return nullptr;
	}
};

class GUIEngineer {
public:
	void perpareDraw(int FrameType, int LayoutType)
	{
		this->pFrame = FrameFactory::createFrame(FrameType);
		this->pLayout = LayoutFactory::createLayout(LayoutType);
		pFrame->draw();
		pLayout->installFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

int main()
{
	GUIEngineer* pEng = new GUIEngineer;
	pEng->perpareDraw(1, 1);
	system("pause");
	return 0;
}