#include <iostream>
using namespace std;

class Carmera {
public:
	void turnOn()
	{
		cout << "相机启动" << endl;
	}

	void turnOff()
	{
		cout << "相机关闭" << endl;
	}
};

class Light {
public:
	void turnOn()
	{
		cout << "照明灯关闭" << endl;
	}
	void turnOff()
	{
		cout << "照明灯关闭" << endl;
	}
};

class Sensor {
public:
	void active()
	{
		cout << "传感器系统" << endl;
	}

	void deactive()
	{
		cout << "传感器关闭" << endl;
	}
};

class Alarm {
public:
	void action()
	{
		cout << "报警器启动" << endl;
	}

	void deactive()
	{
		cout << "报警器关闭" << endl;
	}
};

class SecuritFacade
{
public:
	SecuritFacade()
	{
		Carmera* pCarmera = new Carmera;
		Light* pLight = new Light;
		Sensor* pSensor = new Sensor;
		Alarm* pAlarm = new Alarm;
	}
	void active()
	{
		pCarmera->turnOn();
		pLight->turnOn();
		pSensor->active();
		pAlarm->action();
	}

	void close()
	{
		pCarmera->turnOff();
		pLight->turnOff();
		pSensor->deactive();
		pAlarm->deactive();
	}
private:
	Carmera* pCarmera;
	Light* pLight;
	Sensor* pSensor;
	Alarm* pAlarm;
};

int main()
{
	/*Carmera* pCarmera = new Carmera;
	Light* pLight = new Light;
	Sensor* pSensor = new Sensor;
	Alarm* pAlarm = new Alarm;
	cout << "启动系统" << endl;
	pCarmera->turnOn();
	pLight->turnOn();
	pSensor->active();
	pAlarm->action();
	cout << "关闭系统" << endl;*/
	/* 一系列关闭操作 ：但是这样有个缺点就是客户端知道太多了*/

	SecuritFacade* pv = new SecuritFacade;
	pv->active();
	pv->close();
	system("pause");
	return 0;
}