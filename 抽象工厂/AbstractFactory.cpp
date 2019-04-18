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
		cout << "现在是在PC环境下，我们使用的高分辨率布局" << m_FrameAdpaterPins << endl;
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


//抽象工厂用来定义产品簇
class AbstractFactory {
public:
	virtual FrameApi* createFrameApi() = 0;
	virtual LayoutApi* createLayoutApi() = 0;
protected:
	AbstractFactory() {}
};

class Schema1 : public AbstractFactory {
public:
	FrameApi* createFrameApi()
	{
		return new ComputerFrame(1024);
	}

	LayoutApi* createLayoutApi()
	{
		return new HighLayout(1024);
	}
};

class Schema2 : public AbstractFactory
{
public:
	FrameApi* createFrameApi()
	{
		return new MoblieFrame(800);
	}
	LayoutApi* createLayoutApi()
	{
		return new LowLayout(800);
	}
};

class AdvanceGuiEngineer {
public:
	void prepareMaterials(AbstractFactory* pSchema)
	{
		this->pFrame = pSchema->createFrameApi();
		this->pLayout = pSchema->createLayoutApi();

		pFrame->draw();
		pLayout->installFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

int main()
{
	AdvanceGuiEngineer* pEng = new AdvanceGuiEngineer();
	pEng->prepareMaterials(new Schema1);
	pEng->prepareMaterials(new Schema2);
	system("pause");
	return 0;
}