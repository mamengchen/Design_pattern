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
	//���ʵĲ�����
public:
	virtual void installFrame() = 0;
protected:
	LayoutApi() {}
};

//pc�ϵ�Frame
class ComputerFrame : public FrameApi {
public:
	ComputerFrame(int pins)
		:m_pins(pins)
	{}

	void draw()
	{
		cout << "������pc����Frame�������õķֱ����ǣ�" << m_pins << endl;
	}
private:
	int m_pins;	//�ֱ���
};

//Moblie��Frame
class MoblieFrame : public FrameApi {
public:
	MoblieFrame(int pins)
		:m_pins(pins)
	{}

	void draw()
	{
		cout << "������Moblie��Frame�������õķֱ����ǣ�" << m_pins << endl;
	}
private:
	int m_pins;	//�ֱ���
};

//�߷ֱ�lv�Ĳ���
class HighLayout :public LayoutApi {
public:
	HighLayout(int FrameAdpaterPins)
		:m_FrameAdpaterPins(FrameAdpaterPins)
	{}

	void installFrame()
	{
		cout << "��������PC�����£�����ʹ�õĸ߷ֱ��ʲ���" << m_FrameAdpaterPins << endl;
	}
private:
	int m_FrameAdpaterPins;
};

//�ͷֱ�lv�Ĳ���
class LowLayout :public LayoutApi {
public:
	LowLayout(int FrameAdpaterPins)
		:m_FrameAdpaterPins(FrameAdpaterPins)
	{}

	void installFrame()
	{
		cout << "��������PC�����£�����ʹ�õĵͷֱ��ʲ���" << m_FrameAdpaterPins << endl;
	}
private:
	int m_FrameAdpaterPins;
};


//���󹤳����������Ʒ��
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